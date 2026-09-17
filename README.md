# Xodus Windows interoperability tracing

This is a clean-room, observer-only Windows tracing project for Xodus. It
forwards execution to Microsoft's installed Gaming Runtime and records public
inputs, bounded output values/buffers, HRESULTs, callback invocations,
queue/async relationships, and observable file/registry/WinHTTP side effects.
It does not decompile or patch the Microsoft runtime, bypass
DRM/anti-cheat, or store SDK files or reusable credentials.

## Official source submodules

The source and documentation checkouts are tracked as official Xodus
submodules:

~~~powershell
git submodule update --init --recursive
~~~

They are kept under `work/` because the inventory and regeneration commands
use those paths directly.

## Current source snapshot

| Checkout | Commit |
|---|---|
| xgameruntime | 791710510d9ba0746bbd60754215eb321800e4f0 |
| xodus | 0670e25aeb0e0e9f800f8f2f4968ae3b681842a7 |
| xgameruntime-docs | 7090008692569aa6081e30dfdd9de58237741e24 |

Regenerate after updating the submodules:

~~~powershell
python tools/api_inventory/inventory.py --source-root work\xgameruntime --docs-root work\xgameruntime-docs --output-root .
python tools/windows-xgrtrace/scripts/generate_wrappers.py --inventory artifacts/api_inventory.json --output tools/windows-xgrtrace/generated
~~~

## Generated inventory

The inventory is source-derived from every IDL and implementation C file. It
computes actual COM slots as three IUnknown slots plus inherited parent
methods, records padding slots without wrapping them, links public Microsoft
documentation when the docs checkout provides a link, and classifies Xodus
implementation markers. See:

- artifacts/api_inventory.json
- artifacts/api_inventory.csv
- artifacts/api_inventory.md
- artifacts/environment_snapshot.json

Issue #11 and the open subsystem issues are recorded in the generated JSON
metadata; issue titles and URLs are not used as implementation evidence.

## Windows tracer layout

tools/windows-xgrtrace contains:

- xgrtrace-launch: suspended spawn, PID attach, and Xbox-app watch mode.
- xgrprobe: non-destructive initialization, lifecycle, export, valid-query,
  invalid-query, repeat-query, task-queue, and async-invalid probes; it never
  performs purchases or service fuzzing.
- xgrtrace-dll: runtime-load detection, export enumeration, optional Detours
  hooks for all seven runtime exports, per-instance COM-vtable wrapping,
  IUnknown tracing, generated typed wrappers, callback thunks, and side-effect
  hooks.
- trace-common: bounded asynchronous JSONL writer, logical pointer/handle IDs,
  HRESULT naming, async lifecycle correlation, bounded output decoding, and
  redaction.
- generated: generated interface metadata and wrappers. Do not edit by hand.
- scripts/coverage_report.py: writes per-session coverage and ranked blocker
  candidates.
- scripts/generate_observations.py: writes notes for methods observed in a
  session.
- scripts/sanitize_trace.py: creates a shareable trace copy with an additional
  recursive credential and identity pass.
- scripts/marker.cpp: the xgrtrace-marker.exe milestone marker helper.

The build is x86-64 only. The launcher refuses non-x64 targets and never tries
to defeat Protected Process Light or anti-cheat restrictions. A late attach
creates partial_start: true in the session metadata.

## Build prerequisites

The native Windows binaries have been built successfully on the current host
with CMake 4.4.3, Visual Studio Build Tools 2022/MSVC x64, the Windows 10 SDK,
Microsoft Detours, and the public GDK 2604.4.7897 NuGet package. The installed
GDK system package still requires one normal Windows reboot to finish its
machine-wide registration; the build uses the extracted public package until
that reboot is available. For another Windows machine, install:

1. Visual Studio/MSVC x64 tools and CMake 3.22+.
2. A local Microsoft Detours checkout passed as
   -DXGRTRACE_DETOURS_ROOT=C:\src\Detours.
3. A local public-GDK umbrella header passed as
   -DXGRTRACE_GDK_ABI_HEADER=XGameRuntime.h, plus its include directory via
   -DXGRTRACE_GDK_INCLUDE_DIR. The header is intentionally not committed.
4. The matching x64 GDK library directory via
   -DXGRTRACE_GDK_LIBRARY_DIR when the umbrella header supplies auto-link
   pragmas.

Example:

~~~powershell
cmake -S tools/windows-xgrtrace -B build/xgrtrace -A x64 -DXGRTRACE_DETOURS_ROOT=C:\src\Detours -DXGRTRACE_GDK_ABI_HEADER=XGameRuntime.h -DXGRTRACE_GDK_INCLUDE_DIR=C:\src\GDK\native\260404\windows\include -DXGRTRACE_GDK_LIBRARY_DIR=C:\src\GDK\native\260404\windows\lib\x64
cmake --build build/xgrtrace --config RelWithDebInfo
~~~

Without Detours, the DLL still builds as a diagnostic shell but records that
the export hooks were unavailable; it must not be treated as a working game
tracer.

For a free, small PC target, use [Killer Instinct](https://www.xbox.com/en-us/games/store/Killer-Instinct/BP4S3XLJG78M).
It is listed as Free+ for Windows PC and supports Xbox Play Anywhere,
achievements, presence, and cloud saves. Halo Infinite is another free option,
but it is a larger and more protected test target.

## Running a session

~~~powershell
.\build\xgrtrace\RelWithDebInfo\xgrtrace-launch.exe --spawn C:\Games\Title\Title.exe --trace-root .\traces
.\build\xgrtrace\RelWithDebInfo\xgrtrace-launch.exe --attach 1234 --trace-root .\traces
.\build\xgrtrace\RelWithDebInfo\xgrtrace-launch.exe --watch Title.exe --trace-root .\traces
.\build\xgrtrace\RelWithDebInfo\xgrtrace-marker.exe --trace-root .\traces --pid 1234 "main menu appeared"
~~~

Each session is written under:

    traces/<game>/<date>-<session>/
      metadata.json
      calls.jsonl
      callbacks.jsonl
      sideeffects.jsonl
      markers.jsonl
      coverage.json
      coverage.md
      notes.md

After a run:

~~~powershell
python tools/windows-xgrtrace/scripts/coverage_report.py --inventory artifacts/api_inventory.json --session traces\Title\<session>
python tools/windows-xgrtrace/scripts/generate_observations.py --inventory artifacts/api_inventory.json --coverage traces\Title\<session>\coverage.json --output-root .
~~~

The tracer forwards every original call and never inspects private
XAsyncBlock bytes. Registered callbacks with a public context parameter are
wrapped so invocation arguments and timing are captured; use
XGRTRACE_NO_WRAP_ASYNC_CALLBACKS=1 (or the launcher's switch) when validating
unmodified callback timing. If a live callback registration reuses the same
kind and context with a different function, the tracer records the ambiguity
and forwards the original registration unwrapped rather than risking callback
misdelivery.

## Data handling

Strings are bounded to 16 KiB. Declared scalar outputs, structures, handles,
and size_is/length_is buffers are captured with safe bounded reads; structure
fields are retained as ABI-sized bytes until an ABI-specific decoder is
available. Credential-producing method families (token, signature, and web
authentication APIs) force all captured inputs/outputs through the sensitive
path, even when an ABI buffer has a generic name such as `result` or `buffer`.
Credentials and token-like values are represented by {redacted, length, sha256,
type}. Side-effect targets are grouped by a hash and safe
basename rather than a complete local path.
Location and URL strings are hashed/redacted as well; file side-effect targets
retain only a safe basename, while network and registry targets are fully
redacted. Shareable traces must additionally pseudonymize XUIDs and gamertags.
Raw traces are excluded by .gitignore.

To create a shareable copy, run
python tools/windows-xgrtrace/scripts/sanitize_trace.py --session traces\Title\<session> --output sanitized\Title\<session>.

This repository documents observed contracts, not Microsoft's internal
implementation. Unknown behavior should be resolved with a controlled probe
before adding a Linux implementation.
