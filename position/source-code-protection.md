# ZirOS Public Boundary

This repository exists to publish evidence without publishing implementation. The private ZirOS source tree and private subsystem source trees are separate repositories with separate git history.

## Public vs Private

| Surface | Public Here | Private Elsewhere |
|---------|-------------|-------------------|
| Attestation JSON | Yes | No |
| Theorem metadata | Yes | Proof files remain private |
| Conformance summaries | Yes | Backend implementations remain private |
| Binary hash manifests | Yes | Binaries remain private |
| Opaque C header | Yes | FFI implementation remains private |
| SDK interface summary | Yes | Core proving internals remain private |
| Runtime scheduler internals | No | Yes |
| GPU kernels and shader libraries | No | Yes |
| Swarm implementation source | No | Yes |
| Neural Engine model bundles | No | Yes |

## Permanent Rules

1. The public repo publishes evidence, not implementation.
2. Sanitization happens before a file crosses the boundary.
3. Operator-local filesystem paths are removed.
4. Personal identifiers inside local paths are removed.
5. Token-like strings are removed.
6. Wallet and dust identifiers are removed unless they are already part of an intended public deployment surface.
7. Private evidence-file paths are removed from theorem metadata.
8. Binaries are represented by hashes, sizes, and manifests only.
9. Proof files are represented by theorem metadata and attestation commitments only.
10. CI rejects any push that violates these rules.

## Sanitization Contract

Before publication, attestation artifacts are scrubbed to remove:

- operator home-directory paths
- private repository paths
- temporary build paths
- token-like credentials
- wallet and dust identifiers that are not meant for public disclosure
- theorem `evidence_path` fields and similar private trace fields

The published result is documentation, metadata, and machine-verifiable evidence only.

## Why the Repositories Are Separate

The private ZirOS repository and this public attestation repository do not share branches. That separation is intentional:

- no shared push target
- no mixed history between private code and public evidence
- no accidental `push --all` from the private workspace
- a single clean CI boundary on the public side

## Enforcement

The publication boundary is enforced three ways:

1. `.gitignore` rejects common source, proof, binary, and build-file classes.
2. `validate-attestation.yml` blocks pushes that contain forbidden files or unsanitized strings.
3. Weekly updates regenerate the public evidence package from private truth surfaces instead of copying private workspace state directly.
