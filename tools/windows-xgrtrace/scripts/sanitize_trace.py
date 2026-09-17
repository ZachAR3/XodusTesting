#!/usr/bin/env python3
"""Produce a shareable trace copy with credential and identity redaction."""

from __future__ import annotations

import argparse
import base64
import binascii
import hashlib
import json
import re
from pathlib import Path, PurePosixPath, PureWindowsPath
from typing import Any, Optional, Sequence

SECRET_KEY = re.compile(r"(authorization|signature|token|ticket|cookie|credential|secret|password|refresh|session)", re.I)
CREDENTIAL_METHOD = re.compile(r"(token|signature|authentication|auth)", re.I)
IDENTITY_KEY = re.compile(r"(xuid|gamertag|local.?id|publisher.?user.?id|user.?id)", re.I)
JWT_PART = re.compile(r"^[A-Za-z0-9_-]+$")
MACHINE_KEY = re.compile(r"^(computer|hostname|host|host_name|machine)(_|$)", re.I)
PATH_KEY = re.compile(r"(path|full.?path|executable|install.?location|session|root|target|destination|url|uri|host|hostname|endpoint|filename|directory)$", re.I)
ABSOLUTE_PATH = re.compile(r"^(?:[A-Za-z]:[\\/]|\\\\|/)")
SENSITIVE_STRUCTURE_KEYS = {
    "event", "name", "type", "call_id", "iid", "slot", "method",
    "readable", "truncated", "capacity", "used", "captured_bytes",
    "used_readable", "string_readable", "string_truncated", "size",
    "width", "pointee_size", "pointer_readable", "pointee_readable",
    "null", "count", "encoding",
}


def digest(value: str) -> str:
    return hashlib.sha256(value.encode("utf-8", "replace")).hexdigest()


def redact(value: str, kind: str) -> dict:
    return {"redacted": True, "length": len(value), "sha256": digest(value), "type": kind}


def path_basename(value: str) -> str:
    """Handle both Windows and POSIX paths regardless of sanitizer host."""
    windows_name = PureWindowsPath(value).name
    posix_name = PurePosixPath(value).name
    return windows_name if windows_name != value or "\\" in value else posix_name


def looks_like_jwt(value: str) -> bool:
    """Recognize compact JWTs without mistaking dotted filenames for tokens."""
    parts = value.split(".")
    if len(parts) != 3 or not all(JWT_PART.fullmatch(part) for part in parts):
        return False
    try:
        padding = lambda part: part + "=" * (-len(part) % 4)
        header = json.loads(base64.urlsafe_b64decode(padding(parts[0])).decode("utf-8"))
        payload = json.loads(base64.urlsafe_b64decode(padding(parts[1])).decode("utf-8"))
    except (binascii.Error, ValueError, UnicodeDecodeError, json.JSONDecodeError):
        return False
    return isinstance(header, dict) and isinstance(payload, dict) and bool(header.get("alg"))


def transform(value: Any, key: str = "") -> Any:
    if isinstance(value, dict):
        result = {child_key: transform(child, child_key) for child_key, child in value.items()}
        kind = str(value.get("kind", "")).lower()
        # Raw traces may store a network host/URL or registry key directly as
        # ``target``.  Redact the complete target for those side-effect kinds;
        # reducing it to a basename would still disclose a host or key.
        if kind in {"network", "registry"} and "target" in value:
            result["target"] = redact(str(value["target"]), "side-effect-target")
        # Older/raw traces can put a path-like API argument in a generic
        # ``value`` field while carrying the semantic parameter name beside
        # it.  Apply the path policy using that parent label as well.
        label = value.get("name")
        if isinstance(label, str) and PATH_KEY.search(label):
            if isinstance(value.get("value"), str):
                result["value"] = transform(value["value"], label)
            elif isinstance(value.get("value"), dict) and isinstance(value["value"].get("value"), str):
                nested = dict(result["value"])
                nested["value"] = transform(value["value"]["value"], label)
                result["value"] = nested
        # Native side-effect records use a nested target object.  Treat its
        # display name as sensitive even when an older/raw trace supplied a
        # hostname, registry key, or complete path instead of the current
        # basename/hash representation.
        if kind not in {"network", "registry"} and key.lower() == "target" and isinstance(value.get("name"), str):
            result["name"] = redact(value["name"], "side-effect-target")
        return result
    if isinstance(value, list):
        return [transform(child, key) for child in value]
    if isinstance(value, str):
        if MACHINE_KEY.search(key):
            return redact(value, "machine")
        if SECRET_KEY.search(key) or looks_like_jwt(value):
            return redact(value, "secret")
        if IDENTITY_KEY.search(key):
            return {"pseudonym": "id#" + digest(value)[:16], "length": len(value)}
        if PATH_KEY.search(key) or ABSOLUTE_PATH.match(value):
            return {"basename": path_basename(value), "sha256": digest(value), "type": "path"}
    return value


def sensitive_payload(value: Any) -> Any:
    """Redact every non-structural value in a credential call record.

    Native tracing already redacts credential buffers.  This second pass is
    for older/raw traces where an output was recorded as ``result`` or
    ``bytes_hex`` without carrying a sensitive parameter label.
    """
    if isinstance(value, dict):
        result = {}
        for child_key, child in value.items():
            if child_key.lower() in SENSITIVE_STRUCTURE_KEYS:
                result[child_key] = child
            elif isinstance(child, str):
                result[child_key] = redact(child, "credential-output")
            else:
                result[child_key] = sensitive_payload(child)
        return result
    if isinstance(value, list):
        return [sensitive_payload(child) for child in value]
    if isinstance(value, str):
        return redact(value, "credential-output")
    return value


def credential_method(value: Any) -> bool:
    return isinstance(value, str) and bool(CREDENTIAL_METHOD.search(value))


def sanitize_calls(source: Path, destination: Path) -> None:
    records = []
    credential_calls = set()
    with source.open(encoding="utf-8", errors="replace") as reader:
        for line in reader:
            try:
                record = json.loads(line)
            except json.JSONDecodeError:
                continue
            if not isinstance(record, dict):
                continue
            records.append(record)
            if record.get("event") == "call" and credential_method(record.get("method")):
                credential_calls.add(record.get("call_id"))
    with destination.open("w", encoding="utf-8") as writer:
        for record in records:
            sanitized = transform(record)
            if (record.get("call_id") in credential_calls and
                    record.get("event") in {"output", "argument"}):
                sanitized = sensitive_payload(sanitized)
            writer.write(json.dumps(sanitized, ensure_ascii=False, separators=(",", ":")) + "\n")


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--session", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args(argv)
    args.output.mkdir(parents=True, exist_ok=True)
    allowed = {"metadata.json", "calls.jsonl", "callbacks.jsonl", "sideeffects.jsonl", "markers.jsonl", "coverage.json"}
    stale = [path.name for path in args.output.iterdir() if path.name not in allowed]
    if stale:
        parser.error("output directory contains unrecognized files; use a new empty directory: " + ", ".join(sorted(stale)))
    for source in args.session.iterdir():
        if source.name not in allowed:
            continue
        destination = args.output / source.name
        if source.suffix == ".jsonl":
            if source.name == "calls.jsonl":
                sanitize_calls(source, destination)
            else:
                with source.open(encoding="utf-8", errors="replace") as reader, destination.open("w", encoding="utf-8") as writer:
                    for line in reader:
                        try:
                            writer.write(json.dumps(transform(json.loads(line)), ensure_ascii=False, separators=(",", ":")) + "\n")
                        except json.JSONDecodeError:
                            continue
        else:
            try:
                destination.write_text(json.dumps(transform(json.loads(source.read_text(encoding="utf-8"))), indent=2) + "\n", encoding="utf-8")
            except json.JSONDecodeError:
                destination.write_text(source.read_text(encoding="utf-8"), encoding="utf-8")
    print(f"Sanitized trace written to {args.output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
