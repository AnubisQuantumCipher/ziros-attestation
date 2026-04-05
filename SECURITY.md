# Public Attestation Security Boundary

This repository is the sealed-source public evidence boundary for ZirOS.

## Allowed Here

- attestation JSON
- theorem metadata
- conformance results
- binary manifests
- deployment manifests
- claim graphs
- hostile-audit verdicts
- verification instructions

## Forbidden Here

- implementation source
- headers
- examples
- signature-bearing SDK or API docs
- private theorem evidence paths
- absolute private filesystem paths
- raw stack traces and private logs
- unpublished release payloads

## Enforcement

1. Public bundle generation fails closed on forbidden file types and forbidden phrases.
2. Public bundle generation fails closed on unsanitized private paths and private theorem evidence fields.
3. Public bundle generation fails closed if the headline theorem count includes hypothesis-carried rows.
4. Public bundle generation fails closed if the sealed-source census reports any unclassified files.
5. Public replay must validate the attestation hash, claim-source graph digest, and hostile-audit verdict.

The public repo is useful only if it stays narrower than the private truth surface and mechanically honest about that boundary.
