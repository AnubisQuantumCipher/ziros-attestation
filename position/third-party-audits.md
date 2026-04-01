# Third-Party Audits

ZirOS does not present a third-party audit PDF as the authority for its security claims in this repository. The public trust surface published here is machine-verifiable evidence: theorem metadata, backend conformance results, fail-closed audit state, binary manifests, and deployment evidence.

## Public Assurance Surface

| Surface | What It Publishes |
|---------|-------------------|
| [attestation/latest.json](../attestation/latest.json) | Current weekly attestation report |
| [ledger/verification-ledger.json](../ledger/verification-ledger.json) | Public theorem metadata only |
| [ledger/ledger-summary.json](../ledger/ledger-summary.json) | Counts by checker, domain, and assurance class |
| [conformance/latest/](../conformance/latest/) | Live compile-prove-verify backend results |
| [evidence/evidence-package.json](../evidence/evidence-package.json) | Sanitized evidence bundle |
| [binary-manifest/v0.4.0/manifest.json](../binary-manifest/v0.4.0/manifest.json) | Binary integrity hashes and sizes |

## Position

Third-party audits and formal evidence answer different questions:

| Question | Audit Snapshot | ZirOS Public Evidence |
|----------|----------------|-----------------------|
| What was reviewed? | A specific source snapshot | A published evidence set and ledger state |
| How long is it current? | Point-in-time | Updated continuously through weekly attestations |
| Is it reproducible? | Limited to the review process | Yes, at the level of published machine-verifiable artifacts |
| Does it expose private source? | Usually yes | No |
| Does it prove every claim? | No | No; published claims are scoped and counted explicitly |

The ZirOS position is not that external audits are useless. It is that a public attestation repository should publish evidence that remains useful after the private source stays private. That is the purpose of this repository.

## What a Reviewer Can Verify Today

1. The public theorem ledger contains 169 mechanized entries and no pending rows.
2. The published conformance suite shows passing results for the four currently attested backends in this repository.
3. The fail-closed publication surface reports zero pending ledger entries and a clean attestation state.
4. The binary manifest exposes hashes, sizes, and the opaque C header without distributing implementation.
5. The Midnight deployment manifest and explorer links expose live public-chain evidence where applicable.

## What This Repository Does Not Claim

- It does not claim that a public evidence repository replaces every form of external review.
- It does not publish private source for line-by-line external code audit.
- It does not collapse mechanized, bounded, and operational evidence into a single undifferentiated claim.

The public claim is narrower and stronger: the published evidence in this repository is machine-readable, continuously updated, and intentionally separated from the proprietary ZirOS implementation.
