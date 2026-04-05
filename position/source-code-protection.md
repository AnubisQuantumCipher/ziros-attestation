# ZirOS Public Boundary

This repository publishes evidence without publishing implementation.

## Public Here

- attestation JSON
- theorem metadata
- conformance summaries
- binary manifests
- deployment manifests
- sealed-source census summary
- claim-source graph
- hostile-audit verdict

## Not Public Here

- source code
- headers
- examples
- SDK/API signatures
- private theorem evidence paths
- private logs and stack traces

## Permanent Rules

1. The public repo publishes evidence, not implementation.
2. Sanitization happens before a file crosses the boundary.
3. Headline theorem counts exclude hypothesis-carried rows.
4. External evidence stays separate from mathematical claims.
5. CI rejects any push that violates the sealed-source boundary.
