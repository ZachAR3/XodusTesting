# Trace coverage

Game: Title.exe
Partial start: False
Calls: 2
Methods invoked: 2 / 418
Callbacks observed: 1
Async started/results/completed/completion-callbacks/cancelled: 1 / 1 / 1 / 0 / 0
Side effects: 2
User markers: 0

## XODUS BLOCKER CANDIDATES

Sorted by first occurrence. Startup candidates are only marked for a complete (non-late-attach) session and the first 100 intercepted calls; confirm with user markers before treating one as a boot blocker.

| First call | Subsystem | Interface | Slot | Method | State | Errors |
|---:|---|---|---:|---|---|---:|
| 1 | XThreading | IXThreadingImpl | 3 | XAsyncGetStatus | stubbed_or_incomplete | 0 |
| 2 | XUser | IXUserImpl | 33 | XUserRegisterForChangeEvent | stubbed_or_incomplete | 0 |

## Invoked methods

| Subsystem | Interface | Slot | Method | Count | Error rate | Async | Outputs | Callbacks |
|---|---|---:|---|---:|---:|---:|---:|---:|
| XThreading | IXThreadingImpl | 3 | XAsyncGetStatus | 1 | 0.0% | 1 | 1 | 0 |
| XUser | IXUserImpl | 33 | XUserRegisterForChangeEvent | 1 | 0.0% | 0 | 0 | 1 |
