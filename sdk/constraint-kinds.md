# SDK Constraint Kinds

`ConstraintKind` is the public taxonomy exposed by `zkf-sdk`. It classifies constraint intent without exposing internal lowering or backend synthesis details.

| Kind | Meaning | Public Use |
|------|---------|------------|
| `Equal` | Two expressions must evaluate to the same field value. | Assignment correctness, invariant enforcement, output binding |
| `Boolean` | A signal is constrained to `{0,1}`. | Flags, selectors, policy bits |
| `Range` | A signal is constrained to fit within a bit width. | Bounded integers, counters, fixed-width values |
| `BlackBox` | A gadget-backed primitive is requested through the public gadget surface. | Poseidon, SHA-256, signatures, Merkle operations, and other exported black-box ops |
| `Lookup` | A tuple of values must match a row in a named lookup table. | Schedules, policy tables, discretized domain rules |

The enum is part of the public SDK surface. The internal compilation strategy for each kind remains private.
