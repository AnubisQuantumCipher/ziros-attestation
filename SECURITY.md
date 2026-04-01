# Security Policy

This repository is a public attestation boundary for ZirOS. It is not a source distribution, not a binary distribution, and not a proof-source mirror.

## Non-Negotiable Publication Rules

1. No implementation source is accepted here. That includes Rust, TypeScript, JavaScript, Metal, Lean, Rocq/Coq, Verus, F*, Circom, Noir, Compact, or any other proof or runtime source file.
2. No binaries are accepted here. Dynamic libraries, static libraries, shader libraries, object files, archives, executables, and compiled proof artifacts are rejected.
3. No build manifests or build scripts are accepted here. Cargo manifests, lockfiles, shell build entrypoints, packaging scripts, and similar automation files are rejected.
4. No private workspace paths are accepted here. Public files must not expose operator home directories, local checkout paths, temporary build directories, or internal repository layouts.
5. No key material or secrets are accepted here. Tokens, wallet material, signing keys, seed phrases, and operator credentials are out of scope for publication.
6. No proof implementation payloads are accepted here. Witness files, proving keys, verification-key internals, generated proof source, and recursive proof construction surfaces stay private.
7. No runtime internals are accepted here. Scheduler implementation, GPU kernels, swarm implementation source, Neural Engine model bundles, and proving internals remain private.
8. Only sanitized evidence is published here. JSON evidence, theorem metadata, deployment manifests, capability matrices, interface documentation, and the opaque C header are allowed.
9. Every push is validated. The GitHub Actions workflow blocks forbidden file types, binary payloads, unsanitized path leaks, and JSON contract drift.
10. The public history is the audit trail. Weekly updates append fresh evidence without weakening the publication boundary.

## Continuous Enforcement

The repository validator runs on every push and pull request:

- It rejects forbidden source and proof file extensions.
- It rejects binaries and compiled artifacts.
- It rejects Cargo and build-script surfaces.
- It rejects unsanitized internal paths, operator identifiers, and token-like strings.
- It rejects theorem metadata that still carries private evidence-path fields.
- It validates every published JSON document and confirms the public theorem ledger has no pending entries.

The validator is defined in [.github/workflows/validate-attestation.yml](.github/workflows/validate-attestation.yml).

## Reporting a Leak or Sanitization Failure

If you believe this repository contains sensitive material:

1. Do not open a public issue containing the leaked content.
2. Open a private GitHub security advisory or contact the repository owner privately with the commit, path, and a short description of the issue.
3. If the issue involves credentials or wallet material, rotate the affected material first and then report the leak.

## Scope

This policy covers the public attestation repository only. The private ZirOS source tree, private proofs, and private subsystem workspaces remain outside the scope of this repository and are intentionally not mirrored here.
