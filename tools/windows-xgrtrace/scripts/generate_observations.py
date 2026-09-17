#!/usr/bin/env python3
"""Write per-method behavioral note templates from a coverage report."""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path
from typing import Optional, Sequence


def safe_name(value: str) -> str:
    return re.sub(r"[^A-Za-z0-9_.-]+", "_", value)


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--inventory", type=Path, required=True)
    parser.add_argument("--coverage", type=Path, required=True)
    parser.add_argument("--output-root", type=Path, required=True)
    args = parser.parse_args(argv)
    inventory = json.loads(args.inventory.read_text(encoding="utf-8"))
    coverage = json.loads(args.coverage.read_text(encoding="utf-8"))
    by_key = {
        (row.get("iid"), row.get("slot"), row.get("method")): row
        for row in coverage.get("methods_invoked", [])
    }
    for item in inventory.get("methods", []):
        if item.get("kind") != "interface_method":
            continue
        key = (item.get("interface_iid"), item.get("vtable_slot"), item.get("method_name"))
        row = by_key.get(key)
        if not row:
            continue
        directory = args.output_root / "observations" / safe_name(item["subsystem"])
        directory.mkdir(parents=True, exist_ok=True)
        doc_url = item.get("public_microsoft_documentation_url") or "No public documentation link found in the docs checkout."
        content = f"""# {item['method_name']}

## Public signature

{item['complete_signature']}

## Interfaces / IID / slot

- Interface: {item['interface_name']}
- IID: {item['interface_iid']}
- Version: {item['interface_version']}
- Inherited interface: {item['inherited_interface']}
- Actual vtable slot including IUnknown: {item['vtable_slot']}

## Games observed

- {', '.join(row.get('games_seen_in') or [])}
- Invocation count: {row.get('count', 0)}
- First call order: {row.get('first_call_order')}

## Normal behavior

Observed in the trace session {coverage.get('session')}. This section must be expanded from repeated traces and user markers; no internal implementation is inferred.

## Input validation

Not established by passive real-game tracing. Use xgrprobe.exe for controlled negative tests.

## Return codes

- Error count: {row.get('error_count', 0)}
- Error rate: {row.get('error_rate', 0):.1%}
- Return-code distribution: {json.dumps(row.get('return_codes') or {}, sort_keys=True)}

## Output data

This session recorded {row.get('output_count', 0)} bounded output event(s). Scalar outputs are decoded when their declared width is known; structures and buffers retain bounded bytes/encoding metadata. Field-level structure semantics still require an ABI-specific decoder.

## Handle lifetime

Not established.

## Async behavior

- Async observations: {row.get('async_count', 0)}
- Result/completion ordering: correlate `callbacks.jsonl` `async_result`, `async_complete`, and `async_cancel` events by `async_id`; this note does not infer ordering beyond the captured session.

## Callback behavior

- Callbacks observed: {row.get('callbacks_observed', 0)}
- Callback thread/queue: not established.

## Thread/queue behavior

Not established.

## File/registry/network side effects

See the session's `sideeffects.jsonl`; only events emitted by the file, registry, and WinHTTP collectors are evidence of a side effect.

## Repeated-call behavior

Not established.

## Windows runtime versions tested

See the session's metadata.json.

## Unknowns

- Controlled input-validation behavior is still unknown.
- Repeat-run stability has not been proven by this note alone.

## Linux implementation notes

This note describes the observable contract only. It does not specify or infer Microsoft's internal implementation.

## Public documentation

{doc_url}
"""
        (directory / f"{safe_name(item['method_name'])}.md").write_text(content, encoding="utf-8")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
