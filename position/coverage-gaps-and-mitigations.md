# Coverage Gaps and Mitigations

The public theorem ledger is not the only defense surface ZirOS discloses. Some risks are handled by mechanized theorems, some by bounded checking, and some by operational fail-closed controls. This document states that split directly.

## Published Defense Layers

| Risk Category | Published Mitigation | Public Evidence Surface |
|---------------|----------------------|-------------------------|
| Logic correctness | 169 mechanized theorems, 0 pending, 0 model-only claims | [ledger/verification-ledger.json](../ledger/verification-ledger.json) |
| Timing side channels | F* constant-time proof inventory: 10 files, 6,049 lines | [README.md](../README.md) and public evidence package |
| GPU kernel supply chain | 9 attestation manifests, 4-digest chain, CPU fallback on failure | [evidence/evidence-package.json](../evidence/evidence-package.json) |
| Runtime state-space faults | 90 Kani harnesses across 6 crates | [README.md](../README.md) and public attestation summaries |
| Sustained-load behavior | 12-hour soak-test lane | [attestation/latest.json](../attestation/latest.json) |
| Live threat response | Security supervisor with 24 signal types, 11 actions, 5 risk levels | [README.md](../README.md) |
| Artifact integrity | SHA-256 manifests and ML-DSA-87 signing policy | [binary-manifest/v0.4.1/manifest.json](../binary-manifest/v0.4.1/manifest.json) |
| Swarm non-interference | Mechanized and bounded non-interference claims; mutation surface count published as zero | [README.md](../README.md) and public theorem metadata |

## What the Public Ledger Does and Does Not Mean

The public theorem ledger means:

- the listed claims are mechanized
- the checker, scope, and assurance class are published
- the current public ledger state has zero pending rows

The public theorem ledger does not mean:

- every operational risk is captured as a theorem
- every timing, supply-chain, or load-risk property is represented by a theorem row
- the public repository contains the private proof implementations

## Explicitly Non-Theorem Surfaces

The following surfaces are disclosed as bounded or operational controls rather than theorem-ledger rows:

- F* constant-time proof inventory
- Kani bounded model-check inventory
- soak-test and runtime telemetry evidence
- GPU attestation-chain enforcement
- security-supervisor escalation logic

Those controls are still part of the disclosed assurance posture, but they are not mislabeled as theorem proofs.

## Fail-Closed Rules

Several safety properties are disclosed as fail-closed operational contracts:

| Rule | Publicly Disclosed Contract |
|------|-----------------------------|
| Underconstrained circuits | Rejected by fail-closed audit before proving |
| GPU attestation-chain failure | Falls back to CPU; no silent degradation |
| Strict cryptographic lane mismatch | Request must fail closed, not downgrade silently |
| Neural Engine integrity failure | Advisory lane is quarantined; proof truth is unaffected |

## Summary

The public claim is not that ZirOS has no residual risk. The public claim is that ZirOS publishes a layered defense model and labels each layer honestly:

- mechanized when it is machine-checked theorem coverage
- bounded when it is model checking or bounded exploration
- operational when it is a fail-closed runtime control or attestation surface

That distinction is part of the security model, not a disclaimer added after the fact.
