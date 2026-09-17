#!/usr/bin/env python3
"""Generate a source-derived xgameruntime API inventory.

This scanner deliberately treats the Xodus IDL as the ABI source of truth and
uses the C implementation only to classify the current implementation state.
It does not infer Microsoft's implementation.  The optional docs checkout is
used only for public links, interface inheritance, and issue references.
"""

from __future__ import annotations

import argparse
import csv
import hashlib
import json
import re
import subprocess
from dataclasses import asdict, dataclass, field
from datetime import datetime, timezone
from pathlib import Path
from typing import Dict, Iterable, Iterator, List, Optional, Sequence, Tuple


ISSUES = [
    {
        "number": 11,
        "title": "GDK Integration Progress.",
        "state": "open",
        "url": "https://github.com/xodus-gaming/xgameruntime/issues/11",
        "scope": "all",
    },
    {
        "number": 12,
        "title": "XAsync/XAsyncProvider/XTaskQueue Implementation",
        "state": "open",
        "url": "https://github.com/xodus-gaming/xgameruntime/issues/12",
        "scope": "XThreading",
    },
    {
        "number": 13,
        "title": "XUser Implementation",
        "state": "open",
        "url": "https://github.com/xodus-gaming/xgameruntime/issues/13",
        "scope": "XUser",
    },
    {
        "number": 14,
        "title": "XStore Implementation",
        "state": "open",
        "url": "https://github.com/xodus-gaming/xgameruntime/issues/14",
        "scope": "XStore",
    },
    {
        "number": 15,
        "title": "XGameUi Implementation",
        "state": "open",
        "url": "https://github.com/xodus-gaming/xgameruntime/issues/15",
        "scope": "XGameUI",
    },
    {
        "number": 16,
        "title": "XPackage Implementation",
        "state": "open",
        "url": "https://github.com/xodus-gaming/xgameruntime/issues/16",
        "scope": "XPackage",
    },
    {
        "number": 17,
        "title": "XAccessibility/XSpeechSynthesizer Implementation",
        "state": "open",
        "url": "https://github.com/xodus-gaming/xgameruntime/issues/17",
        "scope": "XAccessibility",
    },
]


PRIMITIVE_TYPES = {
    "void",
    "char",
    "signed char",
    "unsigned char",
    "short",
    "unsigned short",
    "int",
    "unsigned int",
    "long",
    "unsigned long",
    "long long",
    "unsigned long long",
    "float",
    "double",
    "BOOLEAN",
    "BYTE",
    "WORD",
    "DWORD",
    "UINT8",
    "UINT16",
    "UINT32",
    "UINT64",
    "INT8",
    "INT16",
    "INT32",
    "INT64",
    "SIZE_T",
    "ULONG",
    "HRESULT",
    "HANDLE",
    "GUID",
}


@dataclass
class Parameter:
    name: str
    type: str
    ctype: str
    attributes: List[str]
    in_param: bool
    out_param: bool
    optional: bool
    string: bool
    size_is: Optional[str]
    length_is: Optional[str]
    array: Optional[str]
    sensitive: bool


@dataclass
class Marker:
    kind: str
    file: str
    line: int
    text: str


@dataclass
class Method:
    subsystem: str
    source_file: str
    interface_name: Optional[str]
    interface_iid: Optional[str]
    interface_version: Optional[int]
    inherited_interface: Optional[str]
    vtable_slot: Optional[int]
    method_name: str
    complete_signature: str
    return_type: str
    parameters: List[Parameter]
    idl_attributes: List[str]
    current_xodus_implementation_state: str
    implementation_markers: List[Marker] = field(default_factory=list)
    queryinterface_e_no_interface: bool = False
    public_microsoft_documentation_url: Optional[str] = None
    observed_on_windows: bool = False
    games_seen_in: List[str] = field(default_factory=list)
    priority_tier: int = 5
    priority_score: int = 0
    issue_references: List[dict] = field(default_factory=list)
    kind: str = "interface_method"


def strip_comments(text: str) -> str:
    text = re.sub(r"/\*.*?\*/", lambda m: "\n" * m.group(0).count("\n"), text, flags=re.S)
    return re.sub(r"//[^\n]*", "", text)


def line_number(text: str, offset: int) -> int:
    return text.count("\n", 0, offset) + 1


def split_top_level(text: str, separator: str = ",") -> List[str]:
    result: List[str] = []
    start = 0
    square = round_ = curly = 0
    quote: Optional[str] = None
    escaped = False
    for index, char in enumerate(text):
        if quote:
            if escaped:
                escaped = False
            elif char == "\\":
                escaped = True
            elif char == quote:
                quote = None
            continue
        if char in "'\"":
            quote = char
        elif char == "[":
            square += 1
        elif char == "]":
            square -= 1
        elif char == "(":
            round_ += 1
        elif char == ")":
            round_ -= 1
        elif char == "{":
            curly += 1
        elif char == "}":
            curly -= 1
        elif char == separator and square == round_ == curly == 0:
            result.append(text[start:index].strip())
            start = index + 1
    tail = text[start:].strip()
    if tail:
        result.append(tail)
    return result


def split_statements(body: str) -> List[str]:
    result: List[str] = []
    start = 0
    square = round_ = curly = 0
    for index, char in enumerate(body):
        if char == "[":
            square += 1
        elif char == "]":
            square -= 1
        elif char == "(":
            round_ += 1
        elif char == ")":
            round_ -= 1
        elif char == "{":
            curly += 1
        elif char == "}":
            curly -= 1
        elif char == ";" and square == round_ == curly == 0:
            statement = body[start:index].strip()
            if statement:
                result.append(statement)
            start = index + 1
    return result


def parse_attributes(text: str) -> Tuple[List[str], str]:
    attributes: List[str] = []
    while True:
        match = re.match(r"\s*\[([^]]*)\]", text, flags=re.S)
        if not match:
            return attributes, text.strip()
        attributes.extend(part.strip() for part in split_top_level(match.group(1)) if part.strip())
        text = text[match.end():]


def attribute_value(attributes: Sequence[str], name: str) -> Optional[str]:
    pattern = re.compile(rf"^{re.escape(name)}\s*\((.*)\)$", flags=re.S)
    for attribute in attributes:
        match = pattern.match(attribute.strip())
        if match:
            return match.group(1).strip()
    return None


def sensitive_name(name: str) -> bool:
    lowered = name.lower()
    needles = (
        "token",
        "ticket",
        "authorization",
        "signature",
        "cookie",
        "credential",
        "secret",
        "password",
        "refresh",
        "jwt",
        "identity",
    )
    return any(needle in lowered for needle in needles)


def normalize_attribute_expression(value: Optional[str]) -> Optional[str]:
    """Normalize an IDL size/length expression without changing its meaning."""
    if value is None:
        return None
    value = value.strip()
    while value.endswith(","):
        value = value[:-1].rstrip()
    return value or None


def parse_parameter(text: str) -> Parameter:
    attributes, declaration = parse_attributes(text)
    array: Optional[str] = None
    array_match = re.search(r"\[([^]]*)\]\s*$", declaration)
    if array_match:
        array = array_match.group(1).strip()
        declaration = declaration[:array_match.start()].rstrip()
    name_match = re.search(r"(?P<name>[A-Za-z_]\w*)\s*$", declaration)
    if not name_match:
        # Python's hash is process-randomized; malformed declarations must
        # still produce byte-for-byte reproducible inventories.
        stable_id = hashlib.sha256(text.encode("utf-8", "replace")).hexdigest()[:10]
        name = f"arg{int(stable_id, 16) % 100000}"
        ctype = declaration
    else:
        name = name_match.group("name")
        ctype = declaration[:name_match.start()].strip()
    if array is not None:
        ctype = f"{ctype} *".strip()
    type_name = re.sub(r"\s+", " ", ctype.replace("*", " * ")).strip()
    return Parameter(
        name=name,
        type=type_name,
        ctype=ctype,
        attributes=attributes,
        in_param="in" in attributes or not attributes,
        out_param="out" in attributes,
        optional="optional" in attributes,
        string="string" in attributes,
        size_is=normalize_attribute_expression(attribute_value(attributes, "size_is")),
        length_is=normalize_attribute_expression(attribute_value(attributes, "length_is")),
        array=array,
        sensitive=sensitive_name(name) or sensitive_name(type_name) or "sensitive" in attributes,
    )


def matching_close(text: str, open_index: int, opening: str = "{", closing: str = "}") -> int:
    depth = 0
    for index in range(open_index, len(text)):
        if text[index] == opening:
            depth += 1
        elif text[index] == closing:
            depth -= 1
            if depth == 0:
                return index
    return len(text) - 1


def parse_method(statement: str) -> Optional[dict]:
    method_attributes, declaration = parse_attributes(statement)
    open_index = declaration.find("(")
    close_index = declaration.rfind(")")
    if open_index < 0 or close_index < open_index:
        return None
    prefix = declaration[:open_index].strip()
    name_match = re.search(r"(?P<name>[A-Za-z_]\w*)\s*$", prefix)
    if not name_match:
        return None
    name = name_match.group("name")
    return_type = re.sub(r"\s+", " ", prefix[:name_match.start()].strip())
    raw_params = declaration[open_index + 1 : close_index].strip()
    parameters = [] if not raw_params else [parse_parameter(item) for item in split_top_level(raw_params)]
    signature_params = ", ".join(
        f"[{', '.join(param.attributes)}] {param.ctype} {param.name}" if param.attributes else f"{param.ctype} {param.name}"
        for param in parameters
    )
    return {
        "name": name,
        "return_type": return_type,
        "parameters": parameters,
        "idl_attributes": method_attributes,
        "complete_signature": f"{return_type} {name}({signature_params})",
    }


def interface_version(name: str) -> int:
    match = re.search(r"(\d+)$", name)
    return int(match.group(1)) if match else 1


def subsystem_from_interface(name: str) -> str:
    value = re.sub(r"^IX", "X", name)
    value = re.sub(r"Impl\d*$", "", value)
    return {"XGameUi": "XGameUI", "XSystemAnalytics": "XSystemAnalytics"}.get(value, value)


def c_function_prefix(subsystem: str) -> str:
    known = {
        "XGameUI": "x_game_ui",
        "XPersistentLocalStorage": "x_persistent_local_storage",
        "XGameRuntimeFeature": "x_game_runtime_feature",
        "XSystemAnalytics": "x_system_analytics",
        "XUserDevice": "x_user_device",
    }
    if subsystem in known:
        return known[subsystem]
    value = re.sub(r"^X", "", subsystem)
    value = re.sub(r"([a-z0-9])([A-Z])", r"\1_\2", value)
    value = re.sub(r"([A-Z]+)([A-Z][a-z])", r"\1_\2", value)
    return "x_" + value.lower()


def c_function_prefixes(subsystem: str) -> List[str]:
    special = {
        "XAppCapture": ["capture"],
        "XAppCaptureMetadata": ["metadata"],
    }
    return special.get(subsystem, [c_function_prefix(subsystem)])


def implementation_aliases(subsystem: str, method_name: str) -> List[str]:
    aliases = {
        ("XPackage", "XPackageGetKind"): ["XPackageGetPackageKind"],
    }
    return [method_name] + aliases.get((subsystem, method_name), [])

def parse_idl_file(path: Path) -> Tuple[List[dict], Dict[str, dict], Dict[str, str]]:
    original = path.read_text(encoding="utf-8", errors="replace")
    text = strip_comments(original)
    interfaces: List[dict] = []
    coclasses: Dict[str, dict] = {}
    for match in re.finditer(
        r"\[([^]]*)\]\s*interface\s+(\w+)(?:\s*:\s*(\w+))?\s*\{",
        text,
        flags=re.S,
    ):
        attributes = [part.strip() for part in split_top_level(match.group(1)) if part.strip()]
        name = match.group(2)
        parent = match.group(3) or "IUnknown"
        body_start = match.end() - 1
        body_end = matching_close(text, body_start)
        body = text[body_start + 1 : body_end]
        methods = [parsed for parsed in (parse_method(stmt) for stmt in split_statements(body)) if parsed]
        iid = attribute_value(attributes, "uuid")
        interfaces.append(
            {
                "name": name,
                "iid": iid,
                "parent": parent,
                "version": interface_version(name),
                "methods": methods,
                "file": path,
                "line": line_number(original, match.start()),
            }
        )
    for match in re.finditer(r"\[([^]]*)\]\s*coclass\s+(\w+)\s*\{([^}]*)\}", text, flags=re.S):
        attributes = [part.strip() for part in split_top_level(match.group(1)) if part.strip()]
        default_interface = re.search(r"\[default\]\s+interface\s+(\w+)", match.group(3))
        coclasses[match.group(2)] = {
            "name": match.group(2),
            "clsid": attribute_value(attributes, "uuid"),
            "default_interface": default_interface.group(1) if default_interface else None,
        }
    return interfaces, coclasses, {str(path): original}


def git_sha(path: Path) -> Optional[str]:
    try:
        result = subprocess.run(
            ["git", "-C", str(path), "rev-parse", "HEAD"],
            check=True,
            capture_output=True,
            text=True,
        )
        return result.stdout.strip()
    except (OSError, subprocess.CalledProcessError):
        return None


def parse_docs(docs_root: Optional[Path]) -> Tuple[Dict[str, str], Dict[str, dict], Dict[str, str]]:
    method_urls: Dict[str, str] = {}
    interface_docs: Dict[str, dict] = {}
    class_docs: Dict[str, str] = {}
    if not docs_root or not docs_root.exists():
        return method_urls, interface_docs, class_docs
    for page in sorted(docs_root.glob("COM/*/*.md")):
        text = page.read_text(encoding="utf-8", errors="replace")
        interface_match = re.search(r"^#\s+(IX\w+)\s*$", text, flags=re.M)
        if interface_match:
            interface = interface_match.group(1)
            iid_match = re.search(r"Interface Id:\s*`([^`]+)`", text)
            parent_match = re.search(r"Inherits:\s*\[(\w+)\]", text)
            methods = {}
            for name, url in re.findall(r"[-*]\s+\[(\w+)\]\((https?://[^)]+)\)", text):
                methods[name] = url
                method_urls.setdefault(name, url)
            for name in re.findall(r"[-*]\s+(\w+)\s+\(no docs\)", text):
                methods.setdefault(name, None)
            interface_docs[interface] = {
                "iid": iid_match.group(1) if iid_match else None,
                "parent": parent_match.group(1) if parent_match else "IUnknown",
                "methods": methods,
                "path": str(page),
            }
        class_match = re.search(r"^#\s+(\w+Impl)\s*$", text, flags=re.M)
        if class_match:
            class_docs[class_match.group(1)] = str(page)
    return method_urls, interface_docs, class_docs


def parse_callback_typedefs(path: Path) -> List[dict]:
    """Read public C callback typedefs from the checked-in IDL/header surface."""
    original = strip_comments(path.read_text(encoding="utf-8", errors="replace"))
    callbacks: List[dict] = []
    pattern = re.compile(
        r"\btypedef\s+(?P<return>[A-Za-z_][\w\s\*]*?)\s+__stdcall\s+"
        r"(?P<name>[A-Za-z_]\w*)\s*\((?P<parameters>[^)]*)\)\s*;",
        flags=re.S,
    )
    for match in pattern.finditer(original):
        raw_params = match.group("parameters").strip()
        parameters = [] if not raw_params or raw_params == "void" else [
            parse_parameter(item) for item in split_top_level(raw_params)
        ]
        callbacks.append({
            "name": match.group("name"),
            "return_type": re.sub(r"\s+", " ", match.group("return").strip()),
            "parameters": parameters,
            "source_file": path,
            "source_line": line_number(original, match.start()),
        })
    return callbacks


def parse_callback_structs(path: Path, callback_names: Sequence[str]) -> List[dict]:
    """Find ABI structs that carry registered callback function pointers."""
    original = strip_comments(path.read_text(encoding="utf-8", errors="replace"))
    callback_set = set(callback_names)
    structs: List[dict] = []
    for match in re.finditer(r"\bstruct\s+(?P<name>\w+)\s*\{(?P<body>[^{}]*)\}", original, flags=re.S):
        fields = []
        context_field = None
        for statement in split_statements(match.group("body")):
            callback_field = re.match(r"\s*(?P<callback>\w+)\s*\*\s*(?P<name>\w+)\s*$", statement)
            if callback_field and callback_field.group("callback") in callback_set:
                fields.append({"name": callback_field.group("name"), "callback": callback_field.group("callback")})
            context_match = re.match(r"\s*(?:const\s+)?void\s*\*\s*(?P<name>\w+)\s*$", statement)
            if context_match and context_match.group("name").lower() == "context":
                context_field = context_match.group("name")
        if fields and context_field:
            structs.append({
                "name": match.group("name"),
                "fields": fields,
                "context_field": context_field,
                "source_file": path,
                "source_line": line_number(original, match.start()),
            })
    return structs


def extract_c_functions(source_root: Path) -> List[dict]:
    functions: List[dict] = []
    pattern = re.compile(
        r"^[ \t]*(?P<signature>(?:(?:static)\s+)?[A-Za-z_][\w\s\*]*?\s+WINAPI\s+(?P<name>[A-Za-z_]\w*)\s*\([^;{]*\))\s*\{",
        flags=re.M,
    )
    for path in sorted(source_root.rglob("*.c")):
        original = path.read_text(encoding="utf-8", errors="replace")
        original_lines = original.splitlines()
        for match in pattern.finditer(original):
            body_end = matching_close(original, match.end() - 1)
            body = original[match.end() : body_end]
            markers: List[Marker] = []
            for kind, token in (("E_NOTIMPL", "E_NOTIMPL"), ("FIXME", "FIXME"), ("stub", "stub"), ("E_NOINTERFACE", "E_NOINTERFACE")):
                for marker in re.finditer(re.escape(token), body, flags=re.I):
                    absolute = match.end() + marker.start()
                    line = line_number(original, absolute)
                    line_text = original_lines[line - 1].strip() if original_lines else ""
                    markers.append(Marker(kind, str(path), line, line_text))
            markers.sort(key=lambda marker: (marker.line, marker.kind, marker.text))
            functions.append(
                {
                    "name": match.group("name"),
                    "signature": re.sub(r"\s+", " ", match.group("signature")).strip(),
                    "file": path,
                    "line": line_number(original, match.start()),
                    "body": body,
                    "markers": markers,
                }
            )
    return functions


def implementation_for(method_name: str, c_functions: Sequence[dict], subsystem: str) -> Tuple[str, List[Marker]]:
    prefixes = c_function_prefixes(subsystem)
    source_stems = {prefix.replace("_", "") for prefix in prefixes}
    method_names = implementation_aliases(subsystem, method_name)
    candidates = [
        function
        for function in c_functions
        if (
            (
                any(function["name"].startswith(prefix + "_") for prefix in prefixes)
                and any(function["name"].endswith("_" + candidate) for candidate in method_names)
            )
            or (
                method_name.startswith("__PADDING")
                and "PADDING" in function["name"]
                and function["file"].stem.replace("_", "") in source_stems
            )
        )
    ]
    if not candidates:
        return "not_found_in_current_source", []
    function = candidates[0]
    markers = function["markers"]
    lowered = function["body"].lower()
    if "__padding" in function["name"].lower() or "padding" in lowered:
        return "unknown_padding", markers
    if any(marker.kind in {"E_NOTIMPL", "FIXME", "stub"} for marker in markers):
        return "stubbed_or_incomplete", markers
    if re.search(r"\breturn\s+(?:S_OK|S_FALSE|E_[A-Z0-9_]+|TRUE|FALSE|0)\s*;", function["body"]) and not re.search(
        r"\b(?:if|switch|Interlocked|QueryInterface|AddRef|Release|Create|Get|Set|Open|Close)\w*\s*\(", function["body"]
    ):
        return "constant_return_candidate", markers
    return "implemented", markers


def implementation_queryinterface_markers(interface: dict, c_functions: Sequence[dict]) -> List[Marker]:
    expected_names = {
        (prefix + "_QueryInterface").lower()
        for prefix in c_function_prefixes(subsystem_from_interface(interface["name"]))
    }
    results: List[Marker] = []
    for function in c_functions:
        if not function["name"].lower().endswith("queryinterface"):
            continue
        if "E_NOINTERFACE" not in {marker.kind for marker in function["markers"]}:
            continue
        if function["name"].lower() in expected_names:
            results.extend(marker for marker in function["markers"] if marker.kind == "E_NOINTERFACE")
    return sorted(results, key=lambda marker: (marker.file, marker.line, marker.kind, marker.text))


def inherited_interfaces(interface_by_name: Dict[str, dict], name: str) -> List[dict]:
    parent = interface_by_name[name]["parent"]
    if parent == "IUnknown" or parent not in interface_by_name:
        return []
    return inherited_interfaces(interface_by_name, parent) + [interface_by_name[parent]]


def priority_for(subsystem: str, method: str, kind: str) -> int:
    if kind == "runtime_export" or method in {"InitializeApiImpl", "InitializeApiImplEx", "InitializeApiImplEx2", "QueryApiImpl"}:
        return 0
    if subsystem in {"XThreading", "XPersistentLocalStorage", "XSystem"}:
        return 1
    if subsystem in {"XUser", "XNetworking", "XGame", "XGameRuntimeFeature", "XStore"}:
        return 2
    if subsystem in {"XPackage", "XGameSave", "XDisplay", "XLauncher"}:
        return 3
    if subsystem in {"XGameUI", "XGameActivation", "XGameInvite", "XGameProtocol", "XGameEvent"}:
        return 4
    return 5


def issue_refs(subsystem: str) -> List[dict]:
    return [
        {"number": item["number"], "title": item["title"], "url": item["url"]}
        for item in ISSUES
        if item["scope"] in {"all", subsystem}
    ]


def relative_project_path(path: Optional[Path], project_root: Path) -> Optional[str]:
    if path is None:
        return None
    try:
        return path.resolve().relative_to(project_root.resolve()).as_posix()
    except ValueError:
        return path.name.replace("\\", "/")


def git_commit_timestamp(path: Optional[Path]) -> Optional[str]:
    if not path:
        return None
    try:
        result = subprocess.run(
            ["git", "-C", str(path), "show", "-s", "--format=%cI", "HEAD"],
            check=True,
            capture_output=True,
            text=True,
        )
        value = result.stdout.strip()
        return value or None
    except (OSError, subprocess.CalledProcessError):
        return None


def stable_generation_timestamp(source_root: Path, docs_root: Optional[Path]) -> Optional[str]:
    """Use a reproducible timestamp instead of making every regeneration dirty."""
    import os

    source_date_epoch = os.environ.get("SOURCE_DATE_EPOCH")
    if source_date_epoch is not None:
        try:
            return datetime.fromtimestamp(int(source_date_epoch), timezone.utc).isoformat()
        except (TypeError, ValueError, OSError, OverflowError):
            pass
    return git_commit_timestamp(source_root) or git_commit_timestamp(docs_root)


def method_to_dict(method: Method) -> dict:
    value = asdict(method)
    value["parameters"] = [asdict(parameter) for parameter in method.parameters]
    value["implementation_markers"] = [asdict(marker) for marker in method.implementation_markers]
    return value


def build_inventory(source_root: Path, docs_root: Optional[Path], project_root: Optional[Path] = None) -> dict:
    project_root = (project_root or source_root.parent).resolve()
    source_root = source_root.resolve()
    docs_root = docs_root.resolve() if docs_root else None
    interface_defs: List[dict] = []
    coclasses: Dict[str, dict] = {}
    for path in sorted(source_root.rglob("*.idl")):
        parsed, classes, _ = parse_idl_file(path)
        interface_defs.extend(parsed)
        coclasses.update(classes)
    interface_by_name = {item["name"]: item for item in interface_defs}
    method_urls, interface_docs, class_docs = parse_docs(docs_root)
    c_functions = extract_c_functions(source_root)
    callback_defs: Dict[str, dict] = {}
    callback_files = sorted(source_root.rglob("*.idl")) + sorted(source_root.rglob("*.h"))
    for path in callback_files:
        for callback in parse_callback_typedefs(path):
            callback_defs.setdefault(callback["name"], callback)
    callback_struct_defs: Dict[str, dict] = {}
    for path in sorted(source_root.rglob("*.idl")):
        for callback_struct in parse_callback_structs(path, callback_defs.keys()):
            callback_struct_defs.setdefault(callback_struct["name"], callback_struct)
    for function in c_functions:
        function["file"] = function["file"].relative_to(source_root)
        for marker in function["markers"]:
            marker.file = str(Path(marker.file).relative_to(source_root))
    methods: List[Method] = []
    interface_query_markers: Dict[str, List[Marker]] = {
        interface["name"]: implementation_queryinterface_markers(interface, c_functions)
        for interface in interface_defs
    }

    for interface in interface_defs:
        subsystem = subsystem_from_interface(interface["name"])
        parent_methods = sum((parent["methods"] for parent in inherited_interfaces(interface_by_name, interface["name"])), [])
        parent_slots = 3 + len(parent_methods)
        for index, parsed in enumerate(interface["methods"]):
            state, markers = implementation_for(parsed["name"], c_functions, subsystem)
            tier = priority_for(subsystem, parsed["name"], "interface_method")
            score = 1000 - tier * 100
            if state in {"stubbed_or_incomplete", "unknown_padding", "not_found_in_current_source"}:
                score += 20
            docs_methods = interface_docs.get(interface["name"], {}).get("methods", {})
            if parsed["name"] in docs_methods:
                url = docs_methods[parsed["name"]]
            else:
                url = method_urls.get(parsed["name"])
            methods.append(
                Method(
                    subsystem=subsystem,
                    source_file=str(interface["file"].relative_to(source_root)),
                    interface_name=interface["name"],
                    interface_iid=interface["iid"],
                    interface_version=interface["version"],
                    inherited_interface=interface["parent"],
                    vtable_slot=parent_slots + index,
                    method_name=parsed["name"],
                    complete_signature=parsed["complete_signature"],
                    return_type=parsed["return_type"],
                    parameters=parsed["parameters"],
                    idl_attributes=parsed["idl_attributes"],
                    current_xodus_implementation_state=state,
                    implementation_markers=markers,
                    queryinterface_e_no_interface=False,
                    public_microsoft_documentation_url=url,
                    priority_tier=tier,
                    priority_score=score,
                    issue_references=issue_refs(subsystem),
                )
            )

    spec_path = source_root / "xgameruntime.spec"
    if spec_path.exists():
        spec_text = spec_path.read_text(encoding="utf-8", errors="replace")
        for match in re.finditer(
            r"@\s+(?P<kind>stub|stdcall|cdecl)\s+-private\s+(?P<name>\w+)\((?P<params>[^)]*)\)",
            spec_text,
        ):
            name = match.group("name")
            functions = [function for function in c_functions if function["name"] == name]
            markers: List[Marker] = []
            state = "not_found_in_current_source"
            source_file = str(spec_path)
            if functions:
                source_file = str(functions[0]["file"])
                markers = functions[0]["markers"]
                state = "stubbed_or_incomplete" if markers else "implemented"
            methods.append(
                Method(
                    subsystem="runtime",
                source_file=str(Path(source_file).relative_to(source_root)) if Path(source_file).is_absolute() else source_file,
                    interface_name=None,
                    interface_iid=None,
                    interface_version=None,
                    inherited_interface=None,
                    vtable_slot=None,
                    method_name=name,
                    complete_signature=f"export {name}({match.group('params').strip()})",
                    return_type="unknown_from_spec",
                    parameters=[],
                    idl_attributes=[],
                    current_xodus_implementation_state=state,
                    implementation_markers=markers,
                    queryinterface_e_no_interface=False,
                    public_microsoft_documentation_url=(
                        "https://learn.microsoft.com/gaming/gdk/docs/reference/system/initializeapiimpl"
                        if name.startswith("InitializeApiImpl")
                        else None
                    ),
                    priority_tier=0,
                    priority_score=1000,
                    issue_references=issue_refs("runtime"),
                    kind="runtime_export",
                )
            )

    methods.sort(key=lambda item: (item.priority_tier, -item.priority_score, item.subsystem, item.interface_name or "", item.vtable_slot if item.vtable_slot is not None else -1, item.method_name))
    interfaces = []
    for interface in sorted(interface_defs, key=lambda item: item["name"]):
        docs = interface_docs.get(interface["name"], {})
        interfaces.append(
            {
                "name": interface["name"],
                "iid": interface["iid"] or docs.get("iid"),
                "version": interface["version"],
                "parent": interface["parent"] or docs.get("parent"),
                "subsystem": subsystem_from_interface(interface["name"]),
                "source_file": str(interface["file"].relative_to(source_root)),
                "source_line": interface["line"],
                "method_count": len(interface["methods"]),
                "vtable_slots": 3 + len(sum((parent["methods"] for parent in inherited_interfaces(interface_by_name, interface["name"])), [])) + len(interface["methods"]),
                "docs_page": relative_project_path(Path(docs["path"]) if docs.get("path") else None, project_root),
                "queryinterface_e_no_interface": bool(interface_query_markers[interface["name"]]),
                "queryinterface_markers": [asdict(marker) for marker in interface_query_markers[interface["name"]]],
            }
        )
    return {
        "schema_version": 2,
        "generated_at_utc": stable_generation_timestamp(source_root, docs_root),
        "x64_only": True,
        "observed_on_windows": False,
        "source": {
            "repository": "https://github.com/xodus-gaming/xgameruntime",
            "root": relative_project_path(source_root, project_root),
            "commit_sha": git_sha(source_root),
        },
        "docs_source": {
            "repository": "https://github.com/xodus-gaming/xgameruntime-docs",
            "root": relative_project_path(docs_root, project_root),
            "commit_sha": git_sha(docs_root) if docs_root else None,
        },
        "issue_references": ISSUES,
        "interfaces": interfaces,
        "coclasses": [coclasses[key] for key in sorted(coclasses)],
        "callbacks": [
            {
                "name": callback["name"],
                "return_type": callback["return_type"],
                "parameters": [asdict(parameter) for parameter in callback["parameters"]],
                "source_file": relative_project_path(callback["source_file"], project_root),
                "source_line": callback["source_line"],
            }
            for callback in sorted(callback_defs.values(), key=lambda item: item["name"])
        ],
        "callback_structs": [
            {
                "name": callback_struct["name"],
                "fields": callback_struct["fields"],
                "context_field": callback_struct["context_field"],
                "source_file": relative_project_path(callback_struct["source_file"], project_root),
                "source_line": callback_struct["source_line"],
            }
            for callback_struct in sorted(callback_struct_defs.values(), key=lambda item: item["name"])
        ],
        "methods": [method_to_dict(method) for method in methods],
        "summary": {
            "interfaces": len(interfaces),
            "methods": len(methods),
            "interface_methods": sum(method.kind == "interface_method" for method in methods),
            "runtime_exports": sum(method.kind == "runtime_export" for method in methods),
            "stubbed_or_incomplete": sum(method.current_xodus_implementation_state == "stubbed_or_incomplete" for method in methods),
            "unknown_padding": sum(method.current_xodus_implementation_state == "unknown_padding" for method in methods),
            "not_found_in_current_source": sum(method.current_xodus_implementation_state == "not_found_in_current_source" for method in methods),
            "public_documentation_links": sum(bool(method.public_microsoft_documentation_url) for method in methods),
            "callbacks": len(callback_defs),
            "callback_structs": len(callback_struct_defs),
            "size_or_length_annotated_parameters": sum(
                bool(parameter.size_is or parameter.length_is)
                for method in methods
                for parameter in method.parameters
            ),
        },
    }


def write_outputs(inventory: dict, output_root: Path) -> None:
    artifacts = output_root / "artifacts"
    artifacts.mkdir(parents=True, exist_ok=True)
    (artifacts / "api_inventory.json").write_text(json.dumps(inventory, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    methods = inventory["methods"]
    fieldnames = [
        "priority_tier",
        "priority_score",
        "subsystem",
        "source_file",
        "interface_name",
        "interface_iid",
        "interface_version",
        "inherited_interface",
        "vtable_slot",
        "method_name",
        "complete_signature",
        "return_type",
        "parameters",
        "idl_attributes",
        "current_xodus_implementation_state",
        "implementation_markers",
        "queryinterface_e_no_interface",
        "public_microsoft_documentation_url",
        "observed_on_windows",
        "games_seen_in",
        "issue_references",
        "kind",
    ]
    with (artifacts / "api_inventory.csv").open("w", newline="", encoding="utf-8") as handle:
        writer = csv.DictWriter(handle, fieldnames=fieldnames)
        writer.writeheader()
        for method in methods:
            writer.writerow({
                field: json.dumps(method[field], ensure_ascii=False) if isinstance(method[field], (list, dict)) else method[field]
                for field in fieldnames
            })
    by_tier: Dict[int, List[dict]] = {tier: [] for tier in range(6)}
    for method in methods:
        by_tier.setdefault(method["priority_tier"], []).append(method)
    lines = [
        "# Generated xgameruntime API inventory",
        "",
        f"Generated: `{inventory['generated_at_utc']}`",
        f"Source commit: `{inventory['source']['commit_sha']}`",
        f"Docs commit: `{inventory['docs_source']['commit_sha']}`",
        "",
        "This file is generated by `tools/api_inventory/inventory.py`. Re-run it after updating the source checkout; do not edit it by hand.",
        "",
        "## Summary",
        "",
        "| Metric | Count |",
        "|---|---:|",
    ]
    for key, value in inventory["summary"].items():
        lines.append(f"| {key} | {value} |")
    lines += ["", "## Issue references", ""]
    for issue in inventory["issue_references"]:
        lines.append(f"- [#{issue['number']} {issue['title']}]({issue['url']}) — {issue['state']}")
    lines += ["", "## Priority order", ""]
    for tier in range(6):
        tier_methods = by_tier.get(tier, [])
        lines.append(f"### Priority {tier} ({len(tier_methods)} methods)")
        lines.append("")
        lines.append("| Subsystem | Interface | Slot | Method | State | Docs |")
        lines.append("|---|---|---:|---|---|---|")
        for method in tier_methods:
            docs = f"[link]({method['public_microsoft_documentation_url']})" if method["public_microsoft_documentation_url"] else "—"
            lines.append(
                f"| {method['subsystem']} | {method['interface_name'] or 'runtime export'} | "
                f"{method['vtable_slot'] if method['vtable_slot'] is not None else '—'} | "
                f"`{method['method_name']}` | {method['current_xodus_implementation_state']} | {docs} |"
            )
        lines.append("")
    (artifacts / "api_inventory.md").write_text("\n".join(lines).rstrip() + "\n", encoding="utf-8")


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source-root", type=Path, required=True)
    parser.add_argument("--docs-root", type=Path)
    parser.add_argument("--output-root", type=Path, required=True)
    args = parser.parse_args(argv)
    inventory = build_inventory(
        args.source_root.resolve(),
        args.docs_root.resolve() if args.docs_root else None,
        args.output_root.resolve(),
    )
    write_outputs(inventory, args.output_root.resolve())
    print(json.dumps(inventory["summary"], indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
