# Sanitized Windows fixtures

This directory is intentionally empty until a real Windows trace and the
controlled probe have produced deterministic, non-secret outputs. Fixture
generation must redact credentials, pseudonymize XUIDs/gamertags, and preserve
only documented buffer/error/lifecycle behavior.

Use tools/windows-xgrtrace/scripts/coverage_report.py and the session
sanitizer after a trace is complete.
