# ZirOS System Technical Report

## Evidence-Only Public Release

This report is descriptive, not authoritative. Current machine-checked values live in:

- [attestation/latest.json](../attestation/latest.json)
- [evidence/evidence-package.json](../evidence/evidence-package.json)
- [publication/manifest.json](../publication/manifest.json)
- [ledger/ledger-summary.json](../ledger/ledger-summary.json)
- [workspace-census-summary.json](../workspace-census-summary.json)
- [claim-source-graph.json](../claim-source-graph.json)
- [hostile-audit-verdict.json](../hostile-audit-verdict.json)

## What The Public Repo Is

This repository is a sealed-source attestation boundary for ZirOS. It publishes:

- theorem metadata
- conformance evidence
- binary integrity manifests
- deployment manifests
- sealed-source census totals
- machine-readable claim tracing
- hostile-audit verdicts

It does not publish implementation source, headers, examples, or public SDK/API signatures.

## Headline Claim Discipline

The public headline count is intentionally narrower than the full mechanized ledger total.

- Headline count: implementation-bound machine-checked rows only
- Separate disclosure: hypothesis-carried rows and their explicit assumptions
- Separate disclosure: explicit TCB files, bounded-only files, excluded files, and external evidence

This is the core honesty contract of the repo. Mathematical claims stay separate from assumption-carried rows and external operational evidence.

## Public Replay Surface

An agent or reviewer can audit this repository without source access by checking:

1. the attestation hash in [attestation/latest.json](../attestation/latest.json)
2. the claim graph digest in [claim-source-graph.json](../claim-source-graph.json)
3. the hostile-audit verdict in [hostile-audit-verdict.json](../hostile-audit-verdict.json)
4. the theorem counts in [ledger/ledger-summary.json](../ledger/ledger-summary.json)
5. the public conformance JSON in [conformance/latest/](../conformance/latest/)
6. the binary manifest in [binary-manifest/v0.4.0/manifest.json](../binary-manifest/v0.4.0/manifest.json)
7. the Midnight explorer state in [midnight/explorer-status.json](../midnight/explorer-status.json)

## Midnight Evidence

Midnight material is published as deployment manifests plus an explorer recheck. It is reported as external evidence, never folded into the mathematical headline.

## Sealed-Source Census

The public census summary exposes:

- total tracked private files included in the sealed-source census
- counts by trust band
- counts by coverage state
- zero-unclassified verdict
- opaque census root digest

The full file map remains private.

## Conclusion

The public repository is designed to answer a narrow question well: what can be verified about ZirOS right now without receiving the private implementation source.
