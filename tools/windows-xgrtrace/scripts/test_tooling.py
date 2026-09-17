#!/usr/bin/env python3
"""Regression checks for the source-derived inventory and trace tooling."""

from __future__ import annotations

import json
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(ROOT / "tools" / "windows-xgrtrace" / "scripts"))

from tools.api_inventory.inventory import build_inventory
import coverage_report
import generate_wrappers
import sanitize_trace


SOURCE = ROOT / "work" / "xgameruntime"
DOCS = ROOT / "work" / "xgameruntime-docs"
INVENTORY_PATH = ROOT / "artifacts" / "api_inventory.json"
TEST_FIXTURES = ROOT / "fixtures" / "tooling-regression"


class ToolingRegressionTests(unittest.TestCase):
    def test_inventory_is_complete_and_relative(self) -> None:
        inventory = build_inventory(SOURCE, DOCS, ROOT)
        self.assertEqual(inventory["summary"]["interfaces"], 60)
        self.assertEqual(inventory["summary"]["interface_methods"], 418)
        self.assertEqual(inventory["summary"]["runtime_exports"], 7)
        self.assertEqual(inventory["summary"]["callbacks"], 43)
        self.assertEqual(inventory["summary"]["callback_structs"], 2)
        self.assertEqual(inventory["summary"]["size_or_length_annotated_parameters"], 67)
        self.assertEqual(inventory["source"]["root"], "work/xgameruntime")
        self.assertTrue(all(":\\" not in json.dumps(item) for item in inventory["methods"]))
        runtime_exports = {item["method_name"] for item in inventory["methods"] if item["kind"] == "runtime_export"}
        self.assertEqual(runtime_exports, {
            "DllCanUnloadNow", "InitializeApiImpl", "InitializeApiImplEx",
            "InitializeApiImplEx2", "QueryApiImpl", "UninitializeApiImpl", "XErrorReport",
        })
        priorities = {
            item["subsystem"]: item["priority_tier"]
            for item in inventory["methods"]
            if item["kind"] == "interface_method"
        }
        self.assertEqual(priorities["XSystem"], 1)
        self.assertEqual(priorities["XStore"], 2)
        self.assertFalse(any(item["queryinterface_e_no_interface"] for item in inventory["methods"]))
        self.assertTrue(any(item["queryinterface_e_no_interface"] for item in inventory["interfaces"]))

    def test_generated_wrappers_have_safe_callback_and_result_shapes(self) -> None:
        inventory = json.loads(INVENTORY_PATH.read_text(encoding="utf-8"))
        output = ROOT / "tools" / "windows-xgrtrace" / "generated"
        generate_wrappers.generate(inventory, output)
        source = (output / "wrappers.cpp").read_text(encoding="utf-8")
        self.assertIn("CopyFromTarget", source)
        self.assertIn("XGameUiUiCallbacks callbacks_callback_copy", source)
        self.assertIn("XUserPlatformRemoteConnectEventHandlers handlers_callback_copy", source)
        self.assertNotIn("xgrtrace_callback_XAsyncProvider", source)
        self.assertNotIn("xgrtrace_callback_XAsyncWork", source)
        self.assertNotIn("auto result = original", source)
        self.assertNotRegex(source, r"RecordAsyncCallEnd\([^\n]*\bresult\b|static_cast<bool>\(result\)")
        self.assertRegex(
            source,
            r'RecordOutputBuffer\(call_id, "blobData"[^\n]*static_cast<std::size_t>\(blobsSize\), reinterpret_cast',
        )
        for method_name in (
            "XStoreQueryLicenseTokenResult",
            "XUserGetTokenAndSignatureResult",
            "XUserGetTokenAndSignatureUtf16Result",
            "XUserGetMsaTokenSilentlyResult",
            "XGameUiShowWebAuthenticationResult",
        ):
            method_start = source.index(method_name)
            method_end = source.index("\n}\n", method_start)
            self.assertIn("RecordOutput", source[method_start:method_end])
            self.assertRegex(source[method_start:method_end], r", true\);")
        core = (ROOT / "tools" / "windows-xgrtrace" / "trace-common" / "trace_core.cpp").read_text(encoding="utf-8")
        self.assertIn('lowered == "xasyncgetresult"', core)
        self.assertNotIn('lowered.find("result") != std::string::npos', core)
        self.assertIn("canonical_handle_type", core)
        self.assertIn("completed_by_callback", core)
        self.assertIn("callback_wrap_ambiguous", core)
        self.assertNotIn('event.string_value("token", key)', core)
        hooks = (ROOT / "tools" / "windows-xgrtrace" / "xgrtrace-dll" / "runtime_hooks.cpp").read_text(encoding="utf-8")
        for export in ("DllCanUnloadNow", "UninitializeApiImpl", "XErrorReport"):
            self.assertIn(f'GetProcAddress(module, "{export}")', hooks)

    def test_coverage_counts_invocations_outputs_and_async_completion(self) -> None:
        inventory = json.loads(INVENTORY_PATH.read_text(encoding="utf-8"))
        async_method = next(item for item in inventory["methods"] if item.get("method_name") == "XAsyncGetStatus")
        callback_method = next(item for item in inventory["methods"] if item.get("method_name") == "XUserRegisterForChangeEvent")
        session = TEST_FIXTURES / "coverage-session"
        calls = [
            {"event": "call", "call_id": 1, "iid": async_method["interface_iid"], "slot": async_method["vtable_slot"], "method": async_method["method_name"], "timestamp_ns": 1},
            {"event": "output", "call_id": 1, "name": "buffer", "value": {}},
            {"event": "return", "call_id": 1, "hresult": "0x00000001"},
            {"event": "call", "call_id": 2, "iid": callback_method["interface_iid"], "slot": callback_method["vtable_slot"], "method": callback_method["method_name"], "timestamp_ns": 2},
            {"event": "return", "call_id": 2, "hresult": "0x00000000"},
        ]
        callbacks = [
            {"event": "async_start", "call_id": 1, "async_id": "async#1"},
            {"event": "async_result", "call_id": 1, "async_id": "async#1", "hresult": "0x00000000"},
            {"event": "async_complete", "call_id": 1, "async_id": "async#1", "hresult": "0x00000000"},
            {"event": "callback", "phase": "invoke", "registration_call_id": 2, "kind": "XUserChangeEventCallback"},
        ]
        (session / "calls.jsonl").write_text("\n".join(json.dumps(item) for item in calls) + "\n", encoding="utf-8")
        (session / "callbacks.jsonl").write_text("\n".join(json.dumps(item) for item in callbacks) + "\n", encoding="utf-8")
        (session / "sideeffects.jsonl").write_text("\n".join([
            json.dumps({"event": "side_effect", "kind": "file"}),
            json.dumps({
                "event": "side_effect", "kind": "network",
                "target": "https://api.example.com/private", "host": "api.example.com",
            }),
        ]) + "\n", encoding="utf-8")
        (session / "metadata.json").write_text(json.dumps({"partial_start": False, "executable_filename": "Title.exe"}), encoding="utf-8")
        self.assertEqual(coverage_report.main(["--inventory", str(INVENTORY_PATH), "--session", str(session)]), 0)
        coverage = json.loads((session / "coverage.json").read_text(encoding="utf-8"))
        self.assertEqual(coverage["schema_version"], 2)
        self.assertEqual(coverage["summary"]["async_started"], 1)
        self.assertEqual(coverage["summary"]["async_results"], 1)
        self.assertEqual(coverage["summary"]["async_completed"], 1)
        self.assertEqual(coverage["summary"]["side_effects"], 2)
        network = next(item for item in coverage["side_effects"] if item.get("kind") == "network")
        self.assertEqual(network["target"], {"redacted": True})
        self.assertEqual(network["host"], {"redacted": True})
        async_row = next(row for row in coverage["methods_invoked"] if row["method"] == "XAsyncGetStatus")
        self.assertEqual(async_row["output_count"], 1)
        self.assertEqual(async_row["error_count"], 0)
        callback_row = next(row for row in coverage["methods_invoked"] if row["method"] == "XUserRegisterForChangeEvent")
        self.assertEqual(callback_row["callbacks_observed"], 1)

    def test_sanitizer_removes_machine_and_absolute_path_values(self) -> None:
        session = TEST_FIXTURES / "sanitizer-input"
        output = TEST_FIXTURES / "sanitizer-output"
        (session / "metadata.json").write_text(json.dumps({
            "computer": "SYNTHETIC-HOST", "executable_filename": "Title.exe",
            "xgameruntime_path": r"C:\\dev\\example-user\\Game\\xgameruntime.dll",
        }), encoding="utf-8")
        (session / "calls.jsonl").write_text("\n".join([
            json.dumps({"token": "secret", "path": r"C:\\dev\\example-user\\Game\\save.dat"}),
            json.dumps({"event": "output", "name": "path", "value": {"value": r"C:\\dev\\example-user\\Game\\nested.dat"}}),
            json.dumps({"event": "argument", "name": "requestUri", "value": "https://api.example.com/private"}),
            json.dumps({"event": "call", "call_id": 10, "method": "XStoreQueryLicenseTokenResult"}),
            json.dumps({"event": "output", "call_id": 10, "name": "result", "value": {
                "type": "char *", "value": "XBL3.0 x=123;ABCDEF", "bytes_hex": "58424c332e3020783d3132333b414243444546"
            }}),
            json.dumps({"event": "call", "call_id": 11, "method": "XUserGetTokenAndSignatureResult"}),
            json.dumps({"event": "output", "call_id": 11, "name": "buffer", "value": {
                "type": "void *", "bytes_hex": "00112233445566778899aabbccddeeff"
            }}),
            json.dumps({"event": "call", "call_id": 12, "method": "XGameUiShowWebAuthenticationResult"}),
            json.dumps({"event": "output", "call_id": 12, "name": "result", "value": "fake-license-token"}),
        ]) + "\n", encoding="utf-8")
        (session / "sideeffects.jsonl").write_text("\n".join([
            json.dumps({
                "event": "side_effect", "kind": "network", "target": {"name": "api.example.com"},
                "host": "SYNTHETIC-HOST",
            }),
            json.dumps({
                "event": "side_effect", "kind": "network", "target": "https://api.example.com/private",
            }),
            json.dumps({
                "event": "side_effect", "kind": "registry", "target": r"HKCU\\Software\\example-user\\Secret",
            }),
        ]) + "\n", encoding="utf-8")
        self.assertEqual(sanitize_trace.main(["--session", str(session), "--output", str(output)]), 0)
        text = "\n".join(path.read_text(encoding="utf-8") for path in output.iterdir())
        self.assertNotIn("SYNTHETIC-HOST", text)
        self.assertNotIn(r"C:\\dev\\example-user", text)
        self.assertNotIn(r"C:\\dev\\example-user\\Game\\nested.dat", text)
        self.assertNotIn("api.example.com", text)
        self.assertNotIn("XBL3.0", text)
        self.assertNotIn("fake-license-token", text)
        self.assertNotIn("58424c332e3020783d3132333b414243444546", text)
        self.assertNotIn("00112233445566778899aabbccddeeff", text)
        self.assertIn("basename", text)
        self.assertIn("redacted", text)
        self.assertNotIn("Secret", text)


if __name__ == "__main__":
    unittest.main()
