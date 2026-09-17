#!/usr/bin/env python3
"""Create coverage.json and coverage.md from a single trace session."""

from __future__ import annotations

import argparse
import json
from collections import Counter
from pathlib import Path
from pathlib import PurePosixPath, PureWindowsPath
from typing import Dict, Iterable, Optional, Sequence


def read_jsonl(path: Path) -> Iterable[dict]:
    if not path.exists():
        return
    with path.open(encoding="utf-8", errors="replace") as handle:
        for line in handle:
            try:
                value = json.loads(line)
            except json.JSONDecodeError:
                continue
            if isinstance(value, dict):
                yield value


def method_key(event: dict) -> str:
    return f"{event.get('iid', '')}|{event.get('slot', '')}|{event.get('method', '')}"


def safe_basename(value: str) -> str:
    """Keep reports useful without copying a complete local path or host."""
    if "\\" in value or (len(value) >= 2 and value[1] == ":"):
        return PureWindowsPath(value).name
    return PurePosixPath(value).name


def event_count(events: Iterable[dict]) -> int:
    """Count logical async events while retaining records without an ID."""
    events = list(events)
    identifiers = {str(event.get("async_id")) for event in events if event.get("async_id")}
    return len(identifiers) + sum(1 for event in events if not event.get("async_id"))


def hresult_failed(value: object) -> bool:
    """Apply the Win32 HRESULT failure-bit rule, not a nonzero test."""
    try:
        raw = int(str(value), 0) & 0xFFFFFFFF
    except (TypeError, ValueError):
        # Unknown textual codes are not success evidence.  Keep the report
        # conservative while allowing the standard zero representation.
        return str(value).upper() not in {"0", "0X0", "0X00000000", "S_OK"}
    return bool(raw & 0x80000000)


def safe_side_effect(event: dict) -> dict:
    """Prevent legacy/raw side-effect targets from leaking into coverage.json."""
    result = dict(event)
    target = result.get("target")
    kind = str(result.get("kind", "")).lower()
    if kind in {"network", "registry"}:
        if target is not None:
            result["target"] = {"redacted": True}
        for key in list(result):
            if key.lower() in {"host", "hostname", "url", "uri", "endpoint", "destination"}:
                result[key] = {"redacted": True}
    elif isinstance(target, str):
        result["target"] = {"basename": safe_basename(target)}
    elif isinstance(target, dict):
        target_copy = dict(target)
        for key, value in list(target_copy.items()):
            if isinstance(value, str) and key.lower() in {"name", "path", "full_path", "filename", "host", "hostname"}:
                target_copy[key] = safe_basename(value)
        result["target"] = target_copy
    return result


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--inventory", type=Path, required=True)
    parser.add_argument("--session", type=Path, required=True)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args(argv)
    inventory = json.loads(args.inventory.read_text(encoding="utf-8"))
    output = args.output or args.session
    output.mkdir(parents=True, exist_ok=True)

    calls = list(read_jsonl(args.session / "calls.jsonl"))
    callbacks = list(read_jsonl(args.session / "callbacks.jsonl"))
    side_effects = list(read_jsonl(args.session / "sideeffects.jsonl"))
    markers = list(read_jsonl(args.session / "markers.jsonl"))
    metadata = {}
    metadata_path = args.session / "metadata.json"
    if metadata_path.exists():
        try:
            metadata = json.loads(metadata_path.read_text(encoding="utf-8"))
        except json.JSONDecodeError:
            metadata = {}
    call_order: Dict[int, int] = {}
    returns: Dict[int, dict] = {}
    call_events = [event for event in calls if event.get("event") == "call"]
    call_by_id = {
        event.get("call_id"): event
        for event in call_events
        if isinstance(event.get("call_id"), int)
    }
    output_by_call = Counter(
        event.get("call_id")
        for event in calls
        if event.get("event") == "output" and isinstance(event.get("call_id"), int)
    )
    for order, event in enumerate(call_events, 1):
        if isinstance(event.get("call_id"), int):
            call_order[event["call_id"]] = order
    for event in calls:
        if event.get("event") == "return" and isinstance(event.get("call_id"), int):
            returns[event["call_id"]] = event

    observed: Dict[str, dict] = {}
    for event in call_events:
        key = method_key(event)
        entry = observed.setdefault(key, {
            "iid": event.get("iid"),
            "slot": event.get("slot"),
            "method": event.get("method"),
            "count": 0,
            "first_timestamp_ns": event.get("timestamp_ns"),
            "last_timestamp_ns": event.get("timestamp_ns"),
            "first_call_order": call_order.get(event.get("call_id")),
            "error_count": 0,
            "async_count": 0,
            "callback_count": 0,
            "output_count": 0,
            "return_codes": Counter(),
        })
        entry["count"] += 1
        entry["last_timestamp_ns"] = event.get("timestamp_ns")
        entry["output_count"] += output_by_call.get(event.get("call_id"), 0)
        result = returns.get(event.get("call_id"), {})
        if result.get("hresult"):
            entry["return_codes"][result["hresult"]] += 1
            if hresult_failed(result["hresult"]):
                entry["error_count"] += 1

    async_by_call: Dict[int, list[dict]] = {}
    for event in callbacks:
        if event.get("event") == "async_start" and isinstance(event.get("call_id"), int):
            async_by_call.setdefault(event["call_id"], []).append(event)
    callback_invocations = [
        event for event in callbacks
        if event.get("event") == "callback" and event.get("phase") == "invoke"
    ]
    callback_names = Counter(event.get("kind", "unknown") for event in callback_invocations)
    async_results = [event for event in callbacks if event.get("event") == "async_result"]
    async_cancels = [event for event in callbacks if event.get("event") == "async_cancel"]
    async_completion_callbacks = [event for event in callbacks if event.get("event") == "async_completion_callback"]
    callback_by_registration = Counter(
        event.get("registration_call_id")
        for event in callback_invocations
        if isinstance(event.get("registration_call_id"), int)
    )
    for call_id, async_events in async_by_call.items():
        call_event = call_by_id.get(call_id)
        if call_event:
            observed[method_key(call_event)]["async_count"] += len(async_events)
    for registration_call_id, count in callback_by_registration.items():
        call_event = call_by_id.get(registration_call_id)
        if call_event:
            observed[method_key(call_event)]["callback_count"] += count

    inventory_by_key = {
        f"{item.get('interface_iid', '')}|{item.get('vtable_slot', '')}|{item.get('method_name', '')}": item
        for item in inventory.get("methods", [])
        if item.get("kind") == "interface_method"
    }
    game_name_value = metadata.get("executable_filename") or args.session.parent.name
    game_name = safe_basename(str(game_name_value)) or "unknown-game"
    partial_start = metadata.get("partial_start")
    method_rows = []
    blockers = []
    for key, item in inventory_by_key.items():
        seen = observed.get(key)
        row = {
            "subsystem": item.get("subsystem"),
            "interface": item.get("interface_name"),
            "iid": item.get("interface_iid"),
            "slot": item.get("vtable_slot"),
            "method": item.get("method_name"),
            "state": item.get("current_xodus_implementation_state"),
            "invoked": bool(seen),
            "count": seen["count"] if seen else 0,
            "first_timestamp_ns": seen["first_timestamp_ns"] if seen else None,
            "last_timestamp_ns": seen["last_timestamp_ns"] if seen else None,
            "first_call_order": seen["first_call_order"] if seen else None,
            "error_count": seen["error_count"] if seen else 0,
            "error_rate": (seen["error_count"] / seen["count"]) if seen else 0,
            "async_count": seen["async_count"] if seen else 0,
            "callbacks_observed": seen["callback_count"] if seen else 0,
            "output_count": seen["output_count"] if seen else 0,
            "return_codes": dict(seen["return_codes"]) if seen else {},
            "games_seen_in": [game_name] if seen else [],
            "documentation_url": item.get("public_microsoft_documentation_url"),
        }
        method_rows.append(row)
        if seen and item.get("current_xodus_implementation_state") in {"stubbed_or_incomplete", "unknown_padding", "not_found_in_current_source"}:
            blockers.append({
                **row,
                "startup_or_pre_failure_candidate": bool(
                    partial_start is False and (seen.get("first_call_order") or 999999) <= 100
                ),
            })

    query_interfaces = sorted({event.get("iid") for event in calls if event.get("event") == "query_interface" and event.get("iid")})
    coverage = {
        "schema_version": 2,
        # Do not put the caller's absolute filesystem path into a report that
        # is intended to be sanitized/shared.  The trace directory name is
        # already the stable session identifier.
        "session": args.session.name,
        "game": game_name,
        "partial_start": partial_start,
        "interfaces_requested": query_interfaces,
        "interface_revisions_requested": query_interfaces,
        "methods_invoked": [row for row in method_rows if row["invoked"]],
        "methods_never_invoked": [row for row in method_rows if not row["invoked"]],
        "xodus_blocker_candidates": sorted(blockers, key=lambda row: (row["first_call_order"] or 999999, row["subsystem"], row["method"])),
        "invocation_counts": {
            f"{row['iid']}|{row['slot']}|{row['method']}": row["count"]
            for row in method_rows if row["invoked"]
        },
        "callbacks_observed": dict(callback_names),
        "markers": [
            marker for marker in markers if marker.get("event") == "marker"
        ],
        "side_effects": [safe_side_effect(event) for event in side_effects if event.get("event") == "side_effect"],
        "summary": {
            "calls": len(call_events),
            "methods_invoked": sum(row["invoked"] for row in method_rows),
            "methods_never_invoked": sum(not row["invoked"] for row in method_rows),
            "xodus_blocker_candidates": len(blockers),
            "callbacks": sum(callback_names.values()),
            "errors": sum(row["error_count"] for row in method_rows),
            "outputs": sum(row["output_count"] for row in method_rows),
            "async_started": event_count(event for events in async_by_call.values() for event in events),
            "async_results": event_count(async_results),
            "async_completed": event_count(event for event in callbacks if event.get("event") == "async_complete"),
            "async_completion_callbacks": event_count(async_completion_callbacks),
            "async_cancelled": event_count(async_cancels),
            "side_effects": sum(event.get("event") == "side_effect" for event in side_effects),
            "markers": sum(event.get("event") == "marker" for event in markers),
        },
    }
    (output / "coverage.json").write_text(json.dumps(coverage, indent=2, ensure_ascii=False, default=lambda value: dict(value)) + "\n", encoding="utf-8")

    lines = [
        "# Trace coverage",
        "",
        f"Game: {game_name}",
        f"Partial start: {coverage['partial_start']}",
        f"Calls: {coverage['summary']['calls']}",
        f"Methods invoked: {coverage['summary']['methods_invoked']} / {len(method_rows)}",
        f"Callbacks observed: {coverage['summary']['callbacks']}",
        f"Async started/results/completed/completion-callbacks/cancelled: {coverage['summary']['async_started']} / {coverage['summary']['async_results']} / {coverage['summary']['async_completed']} / {coverage['summary']['async_completion_callbacks']} / {coverage['summary']['async_cancelled']}",
        f"Side effects: {coverage['summary']['side_effects']}",
        f"User markers: {coverage['summary']['markers']}",
        "",
        "## XODUS BLOCKER CANDIDATES",
        "",
        "Sorted by first occurrence. Startup candidates are only marked for a complete (non-late-attach) session and the first 100 intercepted calls; confirm with user markers before treating one as a boot blocker.",
        "",
        "| First call | Subsystem | Interface | Slot | Method | State | Errors |",
        "|---:|---|---|---:|---|---|---:|",
    ]
    for row in coverage["xodus_blocker_candidates"]:
        lines.append(f"| {row['first_call_order'] or '—'} | {row['subsystem']} | {row['interface']} | {row['slot']} | {row['method']} | {row['state']} | {row['error_count']} |")
    lines += ["", "## Invoked methods", "", "| Subsystem | Interface | Slot | Method | Count | Error rate | Async | Outputs | Callbacks |", "|---|---|---:|---|---:|---:|---:|---:|---:|"]
    for row in sorted((item for item in method_rows if item["invoked"]), key=lambda item: (item["first_call_order"] or 999999, item["method"])):
        lines.append(f"| {row['subsystem']} | {row['interface']} | {row['slot']} | {row['method']} | {row['count']} | {row['error_rate']:.1%} | {row['async_count']} | {row['output_count']} | {row['callbacks_observed']} |")
    (output / "coverage.md").write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(json.dumps(coverage["summary"], indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
