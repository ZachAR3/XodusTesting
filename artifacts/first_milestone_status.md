# First milestone status

## Completed in this workspace

- Cloned and pinned the current main branches of xgameruntime, xodus, and
  xgameruntime-docs.
- Recorded the Windows/Gaming Services baseline and repository SHAs.
- Added a regenerable IDL/C/header-aware inventory generator.
- Generated JSON, CSV, and Markdown inventories with inherited COM slots,
  IUnknown slot accounting, implementation markers, public documentation URLs,
  issue references, dependency priorities, callback typedefs, and callback
  carrying-struct metadata.  Runtime exports are complete and inventory paths
  are project-relative and reproducible.
- Generated typed wrapper source and interface metadata from the inventory.
- Added the x64 launcher, attach/watch modes, all-seven-export runtime
  observation hooks, optional Detours hook layer, per-instance vtable wrapping, IUnknown
  forwarding, safe unknown/padding-slot handling, async/handle lifecycle
  tracking, JSONL writing, bounded input/output decoding, callback invocation
  thunks, file/registry/WinHTTP side-effect hooks, method-aware credential
  redaction, ambiguity-safe callback registration, and exception
  containment around tracer work.
- Added coverage, observation-note, sanitizer, privacy-safe environment
  snapshot, active-session marker, and non-destructive central API probe
  tooling. Coverage now distinguishes late attach, real callback invocations,
  async completion, bounded outputs, and collected side effects.
- Ran Python syntax checks, deterministic inventory/wrapper regeneration, and
  four regression tests covering inventory completeness, wrapper safety,
  output/async/callback/side-effect report correlation, HRESULT failure-bit
  handling, credential fixtures, and trace sanitization.

## Not yet verified on this host

- Native C++ compilation and link.
- Microsoft Detours hook installation.
- Loading the tracer into Microsoft's xgameruntime.dll.
- A real WinGDK/Game Pass game trace from startup to main menu.
- Three-repeat structural trace comparison.
- Per-method Windows behavioral notes and sanitized fixtures based on actual
  game observations.
- Native probe execution on Windows, including the newly added lifecycle,
  invalid-argument, repeat-query, task-queue, and async-invalid cases.

The blocker is environmental, not an inferred runtime failure: this host has
no CMake, MSVC/Visual Studio build tools, Detours checkout, installed public
GDK headers, or target WinGDK game. The native project records these as
explicit prerequisites and will refuse to present a no-Detours build as a
working game tracer.

No Linux API implementation was attempted.
