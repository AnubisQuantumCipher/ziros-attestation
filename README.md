# ZirOS

### The Zero-Knowledge Operating System

<!-- BEGIN GENERATED PUBLIC SUMMARY -->
This repository is evidence-only. It publishes no implementation source, headers, examples, or public SDK surface.

| Surface | Published state |
| --- | --- |
| Public release | `v0.7.2` via [publication/manifest.json](publication/manifest.json) |
| Headline theorem count | **160 implementation-bound mechanized rows** |
| Disclosed hypotheses | 9 hypothesis-carried rows, published separately in [attestation/latest.json](attestation/latest.json) and [evidence/protocol-proof-registry.json](evidence/protocol-proof-registry.json) |
| Public conformance | 24/24 tests passed across `plonky3`, `halo2`, `nova`, and `hypernova` |
| Sealed-source census | 1581 tracked files classified; zero unclassified = `True` |
| Midnight readiness | full universal path for `0.7.2`: status=`ready`, local_operator=`True`, live_submit=`False` via [midnight/readiness.json](midnight/readiness.json) |
| EVM readiness | secondary deploy-capable lane for `0.7.2`: status=`secondary-ready` via [evm/readiness.json](evm/readiness.json) |
| Midnight evidence | 5 published Midnight preprod deployment manifests; explorer verification 0/5 on 2026-04-05 |
| Hostile-audit verdict | [hostile-audit-verdict.json](hostile-audit-verdict.json) and [claim-source-graph.json](claim-source-graph.json) |
<!-- END GENERATED PUBLIC SUMMARY -->

## Public Contract

This repository is evidence-only.

- No implementation source
- No headers
- No examples
- No public SDK surface
- No signature-bearing API documentation

Public trust here comes from machine-readable evidence and replayable claim edges, not from source publication.

## Current Attestation

- Latest attestation: [attestation/latest.json](attestation/latest.json)
- Evidence bundle: [evidence/evidence-package.json](evidence/evidence-package.json)
- Publication manifest: [publication/manifest.json](publication/manifest.json)
- Claim graph: [claim-source-graph.json](claim-source-graph.json)
- Hostile-audit verdict: [hostile-audit-verdict.json](hostile-audit-verdict.json)
- Sealed-source census summary: [workspace-census-summary.json](workspace-census-summary.json)

<!-- BEGIN GENERATED WEEKLY STATUS -->
| What It Publishes | How | Current Status |
| --- | --- | --- |
| Headline theorem count | Implementation-bound machine-checked rows only | **160 implementation-bound rows** |
| Hypothesis registry | Explicit assumptions for non-headline theorem rows | **9 rows disclosed separately** |
| Public backend conformance | Compile -> prove -> verify across 4 published backends | **24/24 tests passed** |
| Sealed-source census | Opaque private-file census summarized publicly | **1581 files; zero unclassified = True** |
| Binary integrity | Published release manifest `binary-manifest/v0.7.2/manifest.json` | **SHA-256 verified for `aarch64-apple-darwin`** |
| Midnight operator path | Full universal path for `0.7.2` | **status=ready local_operator=True live_submit=False** |
| EVM operator path | Secondary deploy-capable lane for `0.7.2` | **status=secondary-ready** |
| Midnight deployment evidence | Published deployment manifest plus live explorer recheck | **0/5 explorer-verified on 2026-04-05** |
<!-- END GENERATED WEEKLY STATUS -->

## Published Evidence Surface

| Artifact | Purpose |
| --- | --- |
| [attestation/latest.json](attestation/latest.json) | Current public attestation with headline counts, provenance, and claim digests |
| [evidence/evidence-package.json](evidence/evidence-package.json) | Public evidence bundle and replay contract |
| [publication/manifest.json](publication/manifest.json) | Canonical published release/version provenance |
| [ledger/verification-ledger.json](ledger/verification-ledger.json) | Public theorem metadata with assurance classes |
| [ledger/ledger-summary.json](ledger/ledger-summary.json) | Public theorem totals and assurance-class counts |
| [ledger/ledger-sha256.txt](ledger/ledger-sha256.txt) | File SHA-256 for the published public ledger artifact |
| [evidence/conformance-summary.json](evidence/conformance-summary.json) | Generated summary of the public compile-prove-verify conformance set |
| [evidence/capability-summary.json](evidence/capability-summary.json) | Generated counts for the published backend, frontend, gadget, and PQ surfaces |
| [evidence/proof-file-inventory.json](evidence/proof-file-inventory.json) | Sealed proof-language inventory and checker counts exported from the private tree |
| [evidence/protocol-proof-registry.json](evidence/protocol-proof-registry.json) | Public digest-pinned registry for the 9 protocol hypothesis rows |
| [conformance/latest/](conformance/latest/) | Public compile-prove-verify results for the attested backends |
| [binary-manifest/v0.7.2/manifest.json](binary-manifest/v0.7.2/manifest.json) | SHA-256 integrity manifest for the published release artifacts |
| [binary-manifest/v0.7.2/installer-manifest.json](binary-manifest/v0.7.2/installer-manifest.json) | Public installer manifest binding the npm wrapper to the attested binary bundle |
| [workspace-census-summary.json](workspace-census-summary.json) | Opaque sealed-source census totals and zero-unclassified verdict |
| [claim-source-graph.json](claim-source-graph.json) | Machine-readable map from public claims to public source artifacts |
| [hostile-audit-verdict.json](hostile-audit-verdict.json) | Public hostile-audit summary derived from the claim graph and census summary |
| [midnight/explorer-status.json](midnight/explorer-status.json) | Current explorer verification state for published Midnight manifests |
| [proof-server/endpoint-spec.md](proof-server/endpoint-spec.md) | Public proof-server behavior contract |

## Public Replay

Any external reviewer or agent should treat this repository as an artifact-only verification surface.

The intended replay path is:

1. Read [attestation/latest.json](attestation/latest.json).
2. Verify the linked [claim-source-graph.json](claim-source-graph.json) digest.
3. Follow each claim edge to the referenced public artifact.
4. Verify [hostile-audit-verdict.json](hostile-audit-verdict.json) against the claim graph and [workspace-census-summary.json](workspace-census-summary.json).
5. Verify [ledger/ledger-sha256.txt](ledger/ledger-sha256.txt) against [ledger/verification-ledger.json](ledger/verification-ledger.json).
6. Verify the public binary manifest, [evidence/conformance-summary.json](evidence/conformance-summary.json), and [evidence/capability-summary.json](evidence/capability-summary.json) directly.

The same public replay checks run automatically on every push and pull request via [.github/workflows/validate-attestation.yml](.github/workflows/validate-attestation.yml).

## Midnight Evidence

Midnight deployment material is published as manifest evidence plus a fresh explorer recheck. It is never upgraded into a mathematical claim.

<!-- BEGIN GENERATED MIDNIGHT STATUS -->
This block is generated from `midnight/sed-deployment-manifest.json` and a live explorer recheck.

| Contract | Transaction Hash | Explorer status | Explorer |
| --- | --- | --- | --- |
| cooperative-treasury | `f99edfaf4ec0d46ea405e2e98d03c9fa40803a36555a5fa362a3879a54590d02` | `unverified_not_found` | [Open](https://explorer.preprod.midnight.network/transactions/f99edfaf4ec0d46ea405e2e98d03c9fa40803a36555a5fa362a3879a54590d02) |
| community-land-trust | `2f9f43543953478a7d8d409edee16f7ee6acab196be45c26c834b7e69036dda1` | `unverified_not_found` | [Open](https://explorer.preprod.midnight.network/transactions/2f9f43543953478a7d8d409edee16f7ee6acab196be45c26c834b7e69036dda1) |
| anti-extraction-shield | `c147265a99848e16cbcebef7fcdb1069185f201f9d169b455af628f5eefa02c3` | `unverified_not_found` | [Open](https://explorer.preprod.midnight.network/transactions/c147265a99848e16cbcebef7fcdb1069185f201f9d169b455af628f5eefa02c3) |
| wealth-trajectory | `37c7aa632cf57ee72149b67daa6bf6055139f39331bb26c33229bef282f3b35f` | `unverified_not_found` | [Open](https://explorer.preprod.midnight.network/transactions/37c7aa632cf57ee72149b67daa6bf6055139f39331bb26c33229bef282f3b35f) |
| sovereignty-score | `1a6564f27868866ba9d6a0593029f42026b0687e113bc4ce9373c5662eb687cf` | `unverified_not_found` | [Open](https://explorer.preprod.midnight.network/transactions/1a6564f27868866ba9d6a0593029f42026b0687e113bc4ce9373c5662eb687cf) |

Explorer verification summary: `0/5` verified on `2026-04-05`.
<!-- END GENERATED MIDNIGHT STATUS -->

## Sealed-Source Boundary

This repository intentionally does not publish the ZirOS core implementation. The release boundary is:

- sealed-source binaries distributed separately
- public theorem metadata
- public conformance evidence
- public integrity manifests
- public claim graph and hostile-audit verdicts

See [SECURITY.md](SECURITY.md), [position/source-code-protection.md](position/source-code-protection.md), and [report/ziros-system-technical-report.md](report/ziros-system-technical-report.md).
