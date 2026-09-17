#!/usr/bin/env python3
"""Generate typed COM-vtable wrapper sources from api_inventory.json.

The generated source intentionally includes a build-provided
``xgrtrace_gdk_abi.h``.  That header is created from the locally installed
public GDK headers during a Windows build and is never committed here.
"""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path
from typing import Dict, Iterable, List, Optional, Sequence, Tuple


def clean_identifier(value: str) -> str:
    return re.sub(r"[^A-Za-z0-9_]", "_", value)


def load(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8"))


def own_methods(inventory: dict) -> Dict[str, List[dict]]:
    result: Dict[str, List[dict]] = {}
    for method in inventory["methods"]:
        if method["kind"] == "interface_method":
            result.setdefault(method["interface_name"], []).append(method)
    return result


def interfaces(inventory: dict) -> Dict[str, dict]:
    return {item["name"]: item for item in inventory["interfaces"]}


def effective_methods(name: str, defs: Dict[str, dict], own: Dict[str, List[dict]]) -> List[dict]:
    current = defs[name]
    parent = current["parent"]
    inherited = [] if parent == "IUnknown" or parent not in defs else effective_methods(parent, defs, own)
    return inherited + sorted(own.get(name, []), key=lambda item: item["vtable_slot"])


def method_key(method: dict) -> Tuple[str, int]:
    return method["interface_name"], int(method["vtable_slot"])


def wrapper_symbol(method: dict) -> str:
    return f"xgrtrace_wrap_{clean_identifier(method['interface_name'])}_slot{method['vtable_slot']}_{clean_identifier(method['method_name'])}"


def safe_wrapper(method: dict) -> bool:
    return "PADDING" not in method["method_name"].upper()


def pointer_depth(parameter: dict) -> int:
    return parameter["ctype"].count("*")


def callback_name(parameter: dict, callback_names: set[str]) -> Optional[str]:
    type_name = parameter["ctype"].replace("*", " ").split()
    for candidate in sorted(callback_names, key=lambda value: (-len(value), value)):
        if candidate in type_name:
            return candidate
    return None


def parameter_base_type(parameter: dict) -> str:
    return re.sub(r"\s+", " ", parameter["ctype"].replace("const", "").replace("*", " ").strip())


def callback_struct_for_parameter(parameter: dict, callback_structs: Dict[str, dict]) -> Optional[dict]:
    if pointer_depth(parameter) != 1:
        return None
    return callback_structs.get(parameter_base_type(parameter))


def method_context_parameter(method: dict) -> Optional[dict]:
    for parameter in method["parameters"]:
        if parameter["name"].lower() == "context":
            return parameter
    for parameter in method["parameters"]:
        lowered = parameter["name"].lower()
        if lowered.endswith("context") and not lowered.startswith("service"):
            return parameter
    return None


def callback_context_parameter(callback: dict) -> Optional[dict]:
    # Prefer the ABI's conventional exact ``context`` argument.  A callback
    # may also have data such as ``serviceContext``; treating that as the
    # registration context makes the generated thunk look up the wrong
    # function and can suppress a real callback.
    for parameter in callback["parameters"]:
        if parameter["name"].lower() == "context":
            return parameter
    for parameter in callback["parameters"]:
        lowered = parameter["name"].lower()
        if lowered.endswith("context") and not lowered.startswith("service"):
            return parameter
    return None


def callback_queue_parameter(callback: dict) -> Optional[dict]:
    for parameter in callback["parameters"]:
        if parameter["name"].lower() == "queue" or "queue" in parameter["name"].lower():
            return parameter
    return None


def cpp_quote(value: str) -> str:
    return value.replace("\\", "\\\\").replace('"', '\\"')


def expression_terms(value: Optional[str]) -> List[str]:
    if not value:
        return []
    aliases = {"localSize": "localeSize"}
    return [aliases.get(term.strip(), term.strip()) for term in value.split(",") if term.strip()]


def safe_expression(value: Optional[str]) -> Optional[str]:
    """Allow only the identifier/constant expressions emitted by the IDL parser."""
    if not value:
        return None
    terms = expression_terms(value)
    if not terms or any(not re.fullmatch(r"[A-Za-z_]\w*|0[xX][0-9A-Fa-f]+|\d+", term) for term in terms):
        return None
    return " * ".join(f"static_cast<std::size_t>({term})" for term in terms)


def element_size_expression(parameter: dict) -> str:
    """Return a valid C++ element-size expression for a pointer parameter."""
    normalized = re.sub(r"\s+", " ", parameter["ctype"].replace("const", "").strip())
    if normalized in {"void *", "void*"}:
        return "1"
    return f"sizeof(*{parameter['name']})"


def parameter_size_expression(parameter: dict) -> Tuple[Optional[str], int]:
    """Return a byte bound and the element unit used by an IDL annotation."""
    if parameter.get("size_is"):
        expression = safe_expression(parameter["size_is"])
        # Most local IDL annotations describe element counts, but a few
        # public APIs intentionally use size_is for an allocated byte count
        # (notably XGameSaveBlob arrays).  Preserve those byte semantics so
        # a struct array is not over-read by sizeof(struct).
        terms = expression_terms(parameter["size_is"])
        byte_count = any(term.lower() in {"blobssize", "bodysize", "bytecount"} for term in terms)
        if byte_count:
            return expression, 1
        return (f"({expression}) * {element_size_expression(parameter)}" if expression else None), 0
    if parameter.get("length_is"):
        expression = safe_expression(parameter["length_is"])
        return (f"({expression}) * {element_size_expression(parameter)}" if expression else None), 0
    return None, 1


def matching_used_parameter(method: dict, parameter: dict) -> Optional[dict]:
    name = parameter["name"].lower()
    candidates = []
    for candidate in method["parameters"]:
        candidate_name = candidate["name"].lower()
        if candidate is parameter or not candidate["out_param"]:
            continue
        if "used" not in candidate_name:
            continue
        if candidate_name.startswith(name) or name.startswith(candidate_name.removesuffix("used")):
            candidates.append(candidate)
    return candidates[0] if candidates else None


def credential_method(method: dict) -> bool:
    """Return whether a method can produce or consume reusable credentials."""
    lowered = method["method_name"].lower()
    return any(token in lowered for token in ("token", "signature", "authentication", "auth"))


def sensitive_parameter(method: dict, parameter: dict) -> bool:
    return bool(parameter.get("sensitive") or credential_method(method))


def is_handle_type(parameter: dict) -> bool:
    type_names = re.findall(r"[A-Za-z_]\w*", parameter["ctype"].lower())
    return any(
        token == "handle" or token.endswith("handle") or
        token == "registrationtoken" or token.endswith("registrationtoken") or
        token == "operation" or token.endswith("operation")
        for token in type_names
    )


def default_return(ret: str) -> str:
    if ret == "void":
        return ""
    if ret == "HRESULT":
        return "E_FAIL"
    if ret in {"BOOLEAN", "bool"}:
        return "FALSE"
    if "*" in ret:
        return "nullptr"
    return "{}"


def callback_return_type(callback: dict) -> str:
    # The public desktop GDK headers spell these callback results as C++ bool,
    # while the source IDL uses the ABI-compatible BOOLEAN spelling.
    if callback["name"] == "XErrorCallback":
        return "bool"
    return "bool" if callback["return_type"] == "BOOLEAN" else callback["return_type"]


def callback_parameter_type(callback: dict, parameter: dict) -> str:
    # A few desktop GDK headers tightened or corrected callback declarations
    # relative to the legacy source IDL.  Keep the inventory source type
    # intact, but emit the public-header type for the actual thunk ABI.
    key = (callback["name"], parameter["name"])
    compatibility = {
        ("XGameUiShowPlayerPickerUiCallback", "info"): "const XGameUiPlayerPickerInfo *",
        ("XNetworkingPreferredLocalUdpMultiplayerPortChangedCallback", "preferredLocalUdpMultiplayerPort"): "uint16_t",
        ("XTaskQueueCallback", "canceled"): "bool",
    }
    return compatibility.get(key, parameter["ctype"])


def include_params(method: dict) -> str:
    return ", ".join(f"{parameter['ctype']} {parameter['name']}" for parameter in method["parameters"])


def callback_struct_setup(method: dict, callback_structs: Dict[str, dict]) -> Tuple[List[str], List[str], Dict[str, str]]:
    declarations: List[str] = []
    setup: List[str] = []
    replacements: Dict[str, str] = {}
    queue = next((candidate for candidate in method["parameters"] if candidate["name"].lower() == "queue"), None)
    queue_value = f"reinterpret_cast<const void *>({queue['name']})" if queue else "nullptr"
    for parameter in method["parameters"]:
        spec = callback_struct_for_parameter(parameter, callback_structs)
        if not spec:
            continue
        copy_name = f"{parameter['name']}_callback_copy"
        valid_name = f"{parameter['name']}_callback_copy_valid"
        declarations += [f"    {parameter_base_type(parameter)} {copy_name}{{}};", f"    bool {valid_name} = false;"]
        setup.append(f"        {valid_name} = trace::CopyFromTarget({parameter['name']}, &{copy_name});")
        setup.append(f"        if ({valid_name}) {{")
        for field in spec["fields"]:
            setup.append(
                f'            {copy_name}.{field["name"]} = trace::WrapCallback<{field["callback"]}>(call_id, "{field["callback"]}", '
                f'{copy_name}.{field["name"]}, reinterpret_cast<const void *>({copy_name}.{spec["context_field"]}), '
                f'{queue_value}, &xgrtrace_callback_{field["callback"]});'
            )
        setup.append("        }")
        replacements[parameter["name"]] = f"({valid_name} ? &{copy_name} : {parameter['name']})"
    return declarations, setup, replacements


def call_params(method: dict, callback_names: set[str], replacements: Optional[Dict[str, str]] = None) -> str:
    replacements = replacements or {}
    values = []
    for parameter in method["parameters"]:
        name = parameter["name"]
        if name in replacements:
            values.append(replacements[name])
            continue
        callback = callback_name(parameter, callback_names)
        context = method_context_parameter(method)
        queue = next(
            (candidate for candidate in method["parameters"] if candidate["name"].lower() == "queue"),
            None,
        )
        if callback and context:
            context_value = f"reinterpret_cast<const void *>({context['name']})"
            queue_value = f"reinterpret_cast<const void *>({queue['name']})" if queue else "nullptr"
            thunk = f"&xgrtrace_callback_{callback}"
            wrapper = "WrapCallback" if "*" in parameter["ctype"] else "WrapCallbackValue"
            values.append(
                f'trace::{wrapper}<{callback}>(call_id, "{callback}", {name}, {context_value}, {queue_value}, {thunk})'
            )
        else:
            values.append(name)
    return ", ".join(values)


def method_metadata(method: dict) -> str:
    return (
        "{"
        f'"{method["method_name"]}", '
        f'"{method["interface_iid"]}", '
        f'{method["vtable_slot"]}, '
        f'"{method["complete_signature"].replace("\\", "\\\\").replace(chr(34), chr(92) + chr(34))}", '
        f'"{method["current_xodus_implementation_state"]}", '
        f'"{method["public_microsoft_documentation_url"] or ""}", '
        f'{f"reinterpret_cast<std::uintptr_t>(&{wrapper_symbol(method)})" if safe_wrapper(method) else "0"}'
        "}"
    )


def input_statement(method: dict, parameter: dict, callback_names: set[str]) -> str:
    name = parameter["name"]
    sensitive = sensitive_parameter(method, parameter)
    callback = callback_name(parameter, callback_names)
    if callback:
        return f'    trace::RecordPointer(call_id, "{name}", reinterpret_cast<const void *>({name}), trace::ArgumentKind::Pointer);'
    if parameter["in_param"] and parameter["string"] and pointer_depth(parameter) >= 2:
        terms = expression_terms(parameter.get("length_is") or parameter.get("size_is"))
        count = terms[0] if terms else "0"
        maximum = terms[1] if len(terms) > 1 else "0"
        count_parameter = next((candidate for candidate in method["parameters"] if candidate["name"] == count), None)
        if count_parameter and "*" in count_parameter["ctype"]:
            count_expression = (
                f'reinterpret_cast<const void *>({count_parameter["name"]}), '
                f'sizeof(*{count_parameter["name"]})'
            )
            recorder = "RecordInputStringArrayFromCountPointer"
        else:
            count_expression = f'static_cast<std::size_t>({count})'
            recorder = "RecordInputStringArray"
        return (
            f'    trace::{recorder}(call_id, "{name}", reinterpret_cast<const void *>({name}), '
            f'{count_expression}, static_cast<std::size_t>({maximum}), '
            f'{"true" if "WCHAR" in parameter["ctype"] or "wchar_t" in parameter["ctype"] else "false"}, '
            f'{"true" if sensitive else "false"});'
        )
    if "XAsyncBlock" in parameter["ctype"] or name.lower() == "async":
        return f'    trace::RecordAsyncBlock(call_id, "{name}", {name});'
    if is_handle_type(parameter) and not parameter["out_param"]:
        return f'    trace::RecordHandleArgumentValue(call_id, "{name}", {name}, "{cpp_quote(parameter["ctype"])}");'
    if parameter["in_param"] and (parameter.get("size_is") or parameter.get("length_is")):
        size, _ = parameter_size_expression(parameter)
        if size:
            return (
                f'    trace::RecordInputBuffer(call_id, "{name}", reinterpret_cast<const void *>({name}), '
                f'{size}, "{cpp_quote(parameter["ctype"])}", {"true" if sensitive else "false"});'
            )
    if parameter["in_param"] and parameter["string"]:
        kind = "StringSensitive" if sensitive else "String"
        return f'    trace::RecordInputString(call_id, "{name}", {name}, trace::ArgumentKind::{kind});'
    if parameter["out_param"] and not parameter["in_param"]:
        return f'    trace::RecordPointer(call_id, "{name}", reinterpret_cast<const void *>({name}), trace::ArgumentKind::Out);'
    if "*" in parameter["ctype"]:
        return f'    trace::RecordPointer(call_id, "{name}", reinterpret_cast<const void *>({name}), trace::ArgumentKind::Pointer);'
    return f'    trace::RecordScalar(call_id, "{name}", {name});'


def output_statement(method: dict, parameter: dict) -> str:
    if not parameter["out_param"]:
        return ""
    name = parameter["name"]
    sensitive = sensitive_parameter(method, parameter)
    if "XAsyncBlock" in parameter["ctype"] or name.lower() == "async":
        return ""
    # A handle typedef is already a pointer value.  Legacy source IDL marks
    # one const input handle as [in, out], but dereferencing it here would
    # instantiate a sizeof() operation on the SDK's incomplete handle type.
    if is_handle_type(parameter) and pointer_depth(parameter) == 0 and "const " in parameter["ctype"]:
        return ""
    if parameter["string"] and pointer_depth(parameter) >= 2:
        terms = expression_terms(parameter.get("length_is") or parameter.get("size_is"))
        count = terms[0] if terms else "0"
        maximum = terms[1] if len(terms) > 1 else "0"
        return (
            f'    trace::RecordOutputStringArray(call_id, "{name}", reinterpret_cast<const void *>({name}), '
            f'static_cast<std::size_t>({count}), static_cast<std::size_t>({maximum}), '
            f'{"true" if "WCHAR" in parameter["ctype"] or "wchar_t" in parameter["ctype"] else "false"}, '
            f'{"true" if sensitive else "false"});'
        )
    if parameter.get("size_is") or parameter.get("length_is"):
        size, unit = parameter_size_expression(parameter)
        if size:
            used = matching_used_parameter(method, parameter)
            used_expression = used["name"] if used else "nullptr"
            used_width = f"sizeof(*{used['name']})" if used else "0"
            unit_expression = element_size_expression(parameter) if unit == 0 else "1"
            encoding = "Utf16" if "WCHAR" in parameter["ctype"] or "wchar_t" in parameter["ctype"] else ("Ansi" if parameter["string"] else "Binary")
            return (
                f'    trace::RecordOutputBuffer(call_id, "{name}", reinterpret_cast<const void *>({name}), '
                f'{size}, reinterpret_cast<const void *>({used_expression}), {used_width}, {unit_expression}, '
                f'"{cpp_quote(parameter["ctype"])}", trace::OutputEncoding::{encoding}, '
                f'{"true" if sensitive else "false"});'
            )
    if pointer_depth(parameter) >= 2:
        return (
            f'    trace::RecordOutputPointeeValue(call_id, "{name}", reinterpret_cast<const void *>({name}), '
            f'sizeof(*{name}), sizeof(**{name}), "{cpp_quote(parameter["ctype"])}", '
            f'{"true" if sensitive else "false"});'
        )
    if is_handle_type(parameter):
        lines = [f'    trace::RecordOutputHandleObject(call_id, "{name}", {name}, "{cpp_quote(parameter["ctype"])}");']
        if "RegistrationToken" in parameter["ctype"]:
            lines.append(f'    trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>({name}), sizeof(*{name}));')
        return "\n".join(lines)
    if "*" in parameter["ctype"]:
        return (
            f'    trace::RecordOutputObject(call_id, "{name}", {name}, '
            f'"{cpp_quote(parameter["ctype"])}", {"true" if sensitive else "false"});'
        )
    return ""


def async_end_statements(method: dict) -> List[str]:
    async_parameter = next(
        (parameter for parameter in method["parameters"] if "XAsyncBlock" in parameter["ctype"] or parameter["name"].lower() == "async"),
        None,
    )
    if not async_parameter:
        return []
    name = async_parameter["name"]
    statements = []
    if method["method_name"] == "XAsyncComplete":
        result_parameter = next((parameter for parameter in method["parameters"] if parameter["name"].lower() == "result"), None)
        if result_parameter:
            statements.append(f'trace::RecordAsyncCompletionResult(call_id, {name}, {result_parameter["name"]});')
    if method["return_type"] == "void":
        statements.append(f'trace::RecordAsyncCallEnd(call_id, {name}, S_OK, false);')
    else:
        statements.append(f'trace::RecordAsyncCallEnd(call_id, {name}, call_result, true);')
    return statements


def callback_unregistration_statement(method: dict, success_expression: str) -> Optional[str]:
    if "unregister" not in method["method_name"].lower():
        return None
    token = next((parameter for parameter in method["parameters"] if "RegistrationToken" in parameter["ctype"]), None)
    if not token:
        return None
    name = token["name"]
    if "*" in token["ctype"]:
        storage = f"reinterpret_cast<const void *>({name})"
        width = f"sizeof(*{name})"
    else:
        storage = f"reinterpret_cast<const void *>(&{name})"
        width = f"sizeof({name})"
    return f'trace::UnregisterCallback(call_id, {storage}, {width}, {success_expression});'


def emit_callback_wrapper(callback: dict, pointer_typedef: bool = False) -> str:
    context = callback_context_parameter(callback)
    if not context:
        return ""
    queue = callback_queue_parameter(callback)
    ret = callback_return_type(callback)
    params = ", ".join(f"{callback_parameter_type(callback, parameter)} {parameter['name']}" for parameter in callback["parameters"])
    calls = ", ".join(parameter["name"] for parameter in callback["parameters"])
    context_value = f"reinterpret_cast<const void *>({context['name']})"
    queue_value = f"reinterpret_cast<const void *>({queue['name']})" if queue else "nullptr"
    callback_type = callback["name"]
    original_type = callback_type if pointer_typedef else f"{callback_type} *"
    missing_return = default_return(ret)
    lines = [
        f"{ret} CALLBACK xgrtrace_callback_{callback['name']}({params})",
        "{",
        f'    auto original = reinterpret_cast<{original_type}>(trace::ResolveCallback("{callback["name"]}", {context_value}));',
        "    try {",
        f'        auto callback_id = trace::BeginCallbackInvocation("{callback["name"]}", reinterpret_cast<const void *>(original), {context_value}, {queue_value});',
    ]
    for parameter in callback["parameters"]:
        lines.append(f'        trace::RecordCallbackArgument(callback_id, "{parameter["name"]}", {parameter["name"]});')
    lines += [
        "        trace::EndCallbackInvocation(callback_id);",
        "    } catch (...) {",
        "        // Callback observation must never change the callback ABI.",
        "    }",
        "    if (!original) {",
    ]
    if missing_return:
        lines.append(f"        return {missing_return};")
    else:
        lines.append("        return;")
    lines += [
        "    }",
    ]
    if missing_return:
        lines.append(f"    return original({calls});")
    else:
        lines.append(f"    original({calls});")
    lines.append("}")
    return "\n".join(lines)


def callback_params(callback: dict) -> str:
    return ", ".join(f"{callback_parameter_type(callback, parameter)} {parameter['name']}" for parameter in callback["parameters"])


def emit_wrapper(method: dict, callback_names: set[str], callback_structs: Dict[str, dict]) -> str:
    ret = method["return_type"]
    params = include_params(method)
    struct_declarations, struct_setup, replacements = callback_struct_setup(method, callback_structs)
    calls = call_params(method, callback_names, replacements)
    call_id = (
        f'trace::BeginCall("{method["interface_iid"]}", {method["vtable_slot"]}, '
        f'"{method["method_name"]}", reinterpret_cast<const void *>(self))'
    )
    args = "\n".join(input_statement(method, parameter, callback_names) for parameter in method["parameters"])
    outputs = "\n".join(filter(None, (output_statement(method, parameter) for parameter in method["parameters"])))
    async_end = async_end_statements(method)
    null_return = default_return(ret)
    unregister = callback_unregistration_statement(method, "true" if ret == "void" else "static_cast<bool>(call_result)")
    fn_type = f"{ret} (WINAPI *)(void *self{', ' if params else ''}{params})"
    original = f"reinterpret_cast<{fn_type}>(trace::OriginalSlot(self, {method['vtable_slot']}))"
    lines = [
        f"{ret} WINAPI {wrapper_symbol(method)}(void *self{', ' if params else ''}{params})",
        "{",
        f"    auto original = {original};",
        "    if (!original) {",
        *(f"        return {null_return};" for _ in [0] if null_return),
        *("        return;" for _ in [0] if not null_return),
        "    }",
        *struct_declarations,
        "    std::uint64_t call_id = 0;",
        "    try {",
        f"        call_id = {call_id};",
        *(f"        {line.strip()}" for line in args.splitlines() if line.strip()),
        *struct_setup,
        "    } catch (...) {",
        "        // Tracing must never prevent the real ABI call.",
        "    }",
    ]
    if ret == "void":
        lines += [
            f"    original(self{', ' if calls else ''}{calls});",
            "    try {",
            *(f"        {line.strip()}" for line in outputs.splitlines() if line.strip()),
            *(f"        {line}" for line in async_end),
            *(f"        {unregister}" for _ in [0] if unregister),
            "        trace::EndCallVoid(call_id);",
            "    } catch (...) {",
            "    }",
            "}",
        ]
    else:
        lines += [
            f"    auto call_result = original(self{', ' if calls else ''}{calls});",
            "    try {",
            *(f"        {line.strip()}" for line in outputs.splitlines() if line.strip()),
            *(f"        {line}" for line in async_end),
            *(f"        {unregister}" for _ in [0] if unregister),
            "        trace::EndCall(call_id, call_result);",
            "    } catch (...) {",
            "    }",
            "    return call_result;",
            "}",
        ]
    return "\n".join(line for line in lines if line != "")


def generate(inventory: dict, output: Path) -> None:
    output.mkdir(parents=True, exist_ok=True)
    defs = interfaces(inventory)
    own = own_methods(inventory)
    callback_defs = [callback for callback in inventory.get("callbacks", []) if callback_context_parameter(callback)]
    # Provider/work callbacks without a registration context are invoked by
    # the async engine itself and cannot be safely resolved from a generic
    # callback registry.  Only callbacks for which we emit a real thunk may
    # be substituted into registration calls.
    callback_names = {callback["name"] for callback in callback_defs}
    callback_pointer_names = {
        callback
        for method in inventory["methods"]
        for parameter in method["parameters"]
        if (callback := callback_name(parameter, callback_names)) and "*" not in parameter["ctype"]
    }
    unique: Dict[Tuple[str, int], dict] = {}
    effective: Dict[str, List[dict]] = {}
    for name in defs:
        effective[name] = effective_methods(name, defs, own)
        for method in effective[name]:
            if safe_wrapper(method):
                unique.setdefault(method_key(method), method)

    header = """// Generated file. Do not edit by hand; rerun scripts/generate_wrappers.py.\n#pragma once\n\n#include <cstdint>\n#include <windows.h>\n#include \"xgrtrace_gdk_abi.h\"\n#include \"interface_metadata.h\"\n\nnamespace xgrtrace::generated {\nusing WrapperAddress = std::uintptr_t;\n\n"""
    header += "\n".join(
        f"{method['return_type']} WINAPI {wrapper_symbol(method)}(void *self{', ' if include_params(method) else ''}{include_params(method)});"
        for method in unique.values()
    )
    header += "\n\n" + "\n".join(
        f"{callback_return_type(callback)} CALLBACK xgrtrace_callback_{callback['name']}({callback_params(callback)});"
        for callback in callback_defs
    )
    header += "\n\nWrapperAddress WrapperFor(const InterfaceMetadata &interface_metadata, std::uint32_t slot);\n}\n"
    (output / "wrappers.h").write_text(header, encoding="utf-8")

    source = """// Generated file. Do not edit by hand; rerun scripts/generate_wrappers.py.\n#include \"xgrtrace_gdk_abi.h\"\n#include \"wrappers.h\"\n#include \"trace_core.h\"\n\nnamespace xgrtrace::generated {\n\n"""
    source += "\n\n".join(
        item
        for item in [*(emit_callback_wrapper(callback, callback["name"] in callback_pointer_names) for callback in callback_defs), *(emit_wrapper(method, callback_names, {item["name"]: item for item in inventory.get("callback_structs", [])}) for method in unique.values())]
        if item
    )
    source += "\n\nstruct WrapperEntry { std::uint32_t slot; WrapperAddress address; };\n\n"
    for name, methods in effective.items():
        source += f"static const WrapperEntry wrappers_{clean_identifier(name)}[] = {{\n"
        for method in methods:
            if safe_wrapper(method):
                source += f"    {{{method['vtable_slot']}, reinterpret_cast<WrapperAddress>(&{wrapper_symbol(method)})}},\n"
        source += "};\n"
    source += "\nWrapperAddress WrapperFor(const InterfaceMetadata &interface_metadata, std::uint32_t slot)\n{\n    switch (interface_metadata.interface_index)\n    {\n"
    for index, name in enumerate(sorted(effective)):
        source += f"    case {index}: for (const auto &entry : wrappers_{clean_identifier(name)}) if (entry.slot == slot) return entry.address; break;\n"
    source += "    default: break;\n    }\n    return 0;\n}\n\n}\n"
    (output / "wrappers.cpp").write_text(source, encoding="utf-8")

    meta_header = """// Generated file. Do not edit by hand.\n#pragma once\n#include <cstdint>\n\nnamespace xgrtrace::generated {\nstruct MethodMetadata {\n    const char *name;\n    const char *iid;\n    std::uint32_t slot;\n    const char *signature;\n    const char *implementation_state;\n    const char *documentation_url;\n    std::uintptr_t wrapper;\n};\nstruct InterfaceMetadata {\n    const char *name;\n    const char *iid;\n    const char *parent;\n    std::uint32_t interface_index;\n    std::uint32_t vtable_slots;\n    const MethodMetadata *methods;\n    std::uint32_t method_count;\n};\nconst InterfaceMetadata *FindInterface(const char *iid);\nconst MethodMetadata *FindMethod(const InterfaceMetadata &metadata, std::uint32_t slot);\n}\n"""
    (output / "interface_metadata.h").write_text(meta_header, encoding="utf-8")

    meta_source = """// Generated file. Do not edit by hand.\n#include \"interface_metadata.h\"\n#include \"wrappers.h\"\n#include <cstring>\n\nnamespace xgrtrace::generated {\n\n"""
    for name in sorted(effective):
        meta_source += f"static const MethodMetadata methods_{clean_identifier(name)}[] = {{\n"
        for method in effective[name]:
            meta_source += f"    {method_metadata(method)},\n"
        meta_source += "};\n"
    meta_source += "\nstatic const InterfaceMetadata interfaces[] = {\n"
    for index, name in enumerate(sorted(effective)):
        interface = defs[name]
        iid = interface["iid"] or ""
        meta_source += f'    {{"{name}", "{iid}", "{interface["parent"]}", {index}, {interface["vtable_slots"]}, methods_{clean_identifier(name)}, static_cast<std::uint32_t>(sizeof(methods_{clean_identifier(name)}) / sizeof(methods_{clean_identifier(name)}[0]))}},\n'
    meta_source += "};\n\nconst InterfaceMetadata *FindInterface(const char *iid)\n{\n    if (!iid) return nullptr;\n    for (const auto &item : interfaces) if (std::strcmp(item.iid, iid) == 0) return &item;\n    return nullptr;\n}\n\nconst MethodMetadata *FindMethod(const InterfaceMetadata &metadata, std::uint32_t slot)\n{\n    for (std::uint32_t index = 0; index < metadata.method_count; ++index)\n        if (metadata.methods[index].slot == slot) return &metadata.methods[index];\n    return nullptr;\n}\n\n}\n"
    (output / "interface_metadata.cpp").write_text(meta_source, encoding="utf-8")

    abi = """// Build-local ABI include point. This file is intentionally not populated\n// with Microsoft SDK content. CMake substitutes the locally supplied public\n// GDK umbrella header (or a diagnostic #error) at configure time.\n#pragma once\n#include <windows.h>\n#include <XAsyncProvider.h>\n@XGRTRACE_GDK_ABI_INCLUDE@\n"""
    (output / "xgrtrace_gdk_abi.h.in").write_text(abi, encoding="utf-8")


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--inventory", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args(argv)
    generate(load(args.inventory), args.output)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
