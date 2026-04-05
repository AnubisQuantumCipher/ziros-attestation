# Third-Party Audits

ZirOS does not treat a static audit PDF as the authority for the public trust surface in this repository.

The public authority here is the machine-readable evidence bundle:

- [attestation/latest.json](../attestation/latest.json)
- [evidence/evidence-package.json](../evidence/evidence-package.json)
- [ledger/ledger-summary.json](../ledger/ledger-summary.json)
- [workspace-census-summary.json](../workspace-census-summary.json)
- [claim-source-graph.json](../claim-source-graph.json)
- [hostile-audit-verdict.json](../hostile-audit-verdict.json)

External audits and public attestation answer different questions.

- External audits review a source snapshot.
- This repository publishes a replayable evidence surface without exposing the private source.

That does not make third-party audits irrelevant. It means the public contract here is narrower: machine-verifiable evidence, explicit assumptions, explicit TCB, and explicit external-evidence boundaries.
