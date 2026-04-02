# ZirOS System: Technical Report

## The Zero-Knowledge Operating System

### Publication state: ZirOS v0.4.0, public attestation generated 2026-04-01
### 24/24 published conformance tests passed. 169 verification-ledger rows (169 mechanized, 0 pending). 5 Midnight preprod contracts live. Public repository is evidence-only by design.

---

## 1. What ZirOS Is

The easiest way to misunderstand ZirOS is to call it a library. That is wrong.

ZirOS is a system layer. It sits between a developer's statement and the cryptographic machinery that proves the statement. It owns the compile, prove, verify, export, deployment, attestation, and boundary-discipline path. That is why the repository calls it a zero-knowledge operating system instead of a framework.

The public claim is not subtle:

- 290,000 lines of Rust
- 30 workspace crates
- 9 proving backends
- 7 circuit frontends
- 63 Metal GPU shaders with 50 kernel entrypoints
- 169 mechanized theorem rows
- 0 pending ledger rows
- Apple Silicon native release artifacts
- Midnight-compatible proof-server surface

Those numbers are published in [README.md](../README.md), the current attestation in [attestation/latest.json](../attestation/latest.json), and the theorem summary in [ledger/ledger-summary.json](../ledger/ledger-summary.json).

The more important claim is architectural, not numerical: ZirOS treats proof generation as infrastructure. The developer owns the application. ZirOS owns the proving kernel beneath it. The public repository exists so outsiders can inspect evidence of that kernel without receiving the private implementation source.

That separation is the central design decision, and this report is only useful if it states that directly.

## 2. What The Public Repository Actually Publishes

This repository is not a teaser site. It is an evidence boundary.

The publication model is documented in [position/source-code-protection.md](../position/source-code-protection.md). The short version is:

- publish attestation JSON, theorem metadata, conformance summaries, binary hashes, interface-level docs, and deployment manifests
- do not publish proving internals, GPU kernels, scheduler source, swarm implementation source, Neural Engine model bundles, proof construction files, or private workspace paths

The published surfaces break down like this:

| Surface | What is public |
| --- | --- |
| Attestation state | [attestation/latest.json](../attestation/latest.json) and dated history under [attestation/](../attestation/) |
| Formal coverage | [ledger/verification-ledger.json](../ledger/verification-ledger.json) and [ledger/ledger-summary.json](../ledger/ledger-summary.json) |
| Backend conformance | published pass/fail summaries and backend counts |
| Binary integrity | SHA-256 manifests for distributed release artifacts |
| SDK boundary | [sdk/api-surface.md](../sdk/api-surface.md), [sdk/constraint-kinds.md](../sdk/constraint-kinds.md), [sdk/example-circuit.rs](../sdk/example-circuit.rs) |
| Midnight surfaces | [proof-server/endpoint-spec.md](../proof-server/endpoint-spec.md), [midnight/explorer-links.md](../midnight/explorer-links.md), [midnight/attestation-contracts.md](../midnight/attestation-contracts.md) |
| Security posture | [position/coverage-gaps-and-mitigations.md](../position/coverage-gaps-and-mitigations.md), [position/third-party-audits.md](../position/third-party-audits.md) |

This is important because it shows the repo is not pretending to be open source when it is not. It is doing something narrower and more defensible: publishing evidence that remains useful even when the implementation stays private.

## 3. The System Surface In Plain Technical Terms

ZirOS combines several layers that are usually split across separate products:

| Layer | Published claim |
| --- | --- |
| Circuit authoring/import | 7 frontends, including Midnight Compact surfaces |
| Proof generation | 9 documented proving lanes, with public conformance currently published for Plonky3, Halo2, Nova, and HyperNova |
| GPU acceleration | Apple Metal lane with 63 shaders and 50 kernel entrypoints |
| Artifact security | ML-DSA-87 post-quantum signing policy and binary hash manifests |
| Deployment/export | Solidity verifier export, Midnight proof-server compatibility, Compact contract evidence |
| Runtime/control plane | system-oriented CLI, health checks, audit commands, and agent-friendly JSON output |

The public attestation repo does not publish the code that implements those layers. It publishes enough machine-verifiable evidence to make the claims inspectable:

- the current ledger hash and row counts
- the current conformance counts and backend names
- the release artifact hashes
- the public proof-server wire contract
- the public Midnight deployment manifest and explorer links

That makes the system legible without leaking the private kernel.

## 4. Developer Experience

This is the part most ZK systems get wrong.

Most proof systems expose cryptography first. The developer is expected to learn circuit constraints, witness handling, backend differences, proof formats, and deployment ceremony details before they can ship an application. ZirOS is trying to invert that relationship.

The public repo describes three developer-facing modes:

| Mode | What the developer sees |
| --- | --- |
| CLI operator mode | `zkf` commands for compile, prove, verify, deploy, conformance, health, and Midnight operations |
| SDK mode | a thin public API surface for building programs and calling opaque proving functionality |
| Agentic mode | Claude Code or Codex driving the proof workflow end to end through CLI and structured output |

The ownership model is explicit in [README.md](../README.md):

| Developer-owned | ZirOS-owned |
| --- | --- |
| app logic | proving internals |
| domain model | GPU kernels |
| contracts | runtime scheduler |
| UI | verification layer |
| product license | private engine implementation |

That is a stronger statement than "tooling." It means the public promise is not "we open-sourced the proving engine." The promise is "you can build your subsystem on top of it, you keep the subsystem, and the kernel remains private."

There is a trust cost to that model. A private kernel is harder to inspect than an open-source library. ZirOS addresses that trust cost by publishing a source-free evidence repo and by writing down the boundary plainly instead of hiding it in licensing footnotes.

This is where the report matters. Trust does not come from pretending the boundary does not exist. It comes from naming the boundary, publishing evidence across it, and saying exactly what the evidence does and does not prove.

### Agentic operation

The repo is unusually candid that ZirOS is intended to be driven by AI agents. The public README explicitly recommends Claude Code and Codex and describes workflows such as:

- selecting a backend
- compiling a circuit
- generating the witness
- proving and verifying
- exporting Solidity verifiers
- running conformance
- performing health checks

That design choice is not fluff. It implies the command surface has to be structured, machine-readable, and robust under automation. The README makes this explicit by calling out JSON output and agent-oriented operational patterns.

The honest interpretation is:

- ZirOS is not just a proof library with an AI wrapper attached later
- ZirOS is trying to be an operating surface that an agent can drive autonomously
- the public repo gives enough interface documentation to understand that model, but not enough source to reimplement it

## 5. Midnight Network Integration

The public Midnight claim has three separate parts, and they should not be collapsed into one.

### 5.1 Proof-server compatibility

[proof-server/endpoint-spec.md](../proof-server/endpoint-spec.md) publishes the public wire contract for the Midnight-compatible proof server. That matters because it is not marketing language. It is an interface contract.

The documented endpoints include:

- `/prove`
- `/prove-tx`
- `/check`
- `/k`
- `/fetch-params/{k}`
- `/version`
- `/proof-versions`
- `/ready`
- `/health`

The public claim here is not "trust us, it is compatible." The claim is "here is the public endpoint surface and the role of each endpoint."

### 5.2 Live preprod contract evidence

[midnight/explorer-links.md](../midnight/explorer-links.md) publishes five live Midnight preprod transactions:

- Cooperative Treasury
- Community Land Trust
- Anti-Extraction Shield
- Wealth Trajectory
- Sovereignty Score

That is concrete chain evidence. It does not reveal private proving internals, but it does show that the selective-disclosure subsystem surface is not purely hypothetical.

### 5.3 Public attestation contracts

[midnight/attestation-contracts.md](../midnight/attestation-contracts.md) is one of the more important honesty documents in the repo. It states that three attestation contracts are compiled and locally proven, but that public deployment is still pending chain stabilization after a runtime change. That is exactly the kind of sentence more repos should publish and more repos usually avoid.

The trust value of this repo comes partly from documents like that one. It does not say "everything is live." It says:

- these contract surfaces exist
- the witness/public-claim split is defined
- deployment is not yet complete
- here is why

That is how a public evidence repo should talk.

## 6. What The Public Repo Proves

The public repo proves several things well.

### 6.1 Formal coverage state

[attestation/latest.json](../attestation/latest.json) and [ledger/ledger-summary.json](../ledger/ledger-summary.json) show:

- 169 total ledger rows
- 169 mechanized local rows
- 0 pending rows
- checker split of 59 Rocq, 86 Verus, 22 Lean, 2 F*

That proves the current published theorem metadata is not hand-wavy. There is a concrete ledger and a concrete count.

### 6.2 Published conformance state

The current attestation publishes:

- 24/24 conformance tests passed
- across 4 backends
- Plonky3 on Goldilocks
- Halo2 on PastaFp
- Nova on Bn254
- HyperNova on Bn254

That is enough to support a precise claim: the public repo currently exposes passing conformance evidence for those four lanes. It is not enough to support a looser claim such as "all nine backends are publicly conformance-proven in this repo." The report should preserve that distinction.

### 6.3 Binary integrity

The attestation JSON publishes the SHA-256 values for:

- `zkf`
- `libzkf_ffi.dylib`
- `libzkf_ffi.a`

That gives the release lane an auditable integrity surface. Again, the public repo does not publish the binaries themselves as source. It publishes the integrity envelope around them.

### 6.4 Boundary discipline

[position/source-code-protection.md](../position/source-code-protection.md) and [position/coverage-gaps-and-mitigations.md](../position/coverage-gaps-and-mitigations.md) are evidence documents in their own right.

They prove that the repository is not only publishing positive claims; it is also publishing:

- what stays private
- which defenses are theorem-backed
- which defenses are bounded or operational
- which failure modes are meant to fail closed

That is an unusually mature disclosure pattern for a source-private system.

## 7. What The Public Repo Does Not Prove

An honest report is not just a list of strengths. It has to name the missing and bounded surfaces too.

### 7.1 It does not publish the private engine

This repository does not contain:

- ZirOS implementation source
- Cargo files
- build scripts
- GPU shader sources
- scheduler internals
- swarm implementation source
- proof construction files

That means an external reader cannot perform a full line-by-line source audit from this repo alone.

### 7.2 It does not publish conformance for all 9 documented backends

The system documentation names 9 proving backends. The published conformance evidence covers 4. That is not a contradiction, but it is a boundary:

- documented system surface: 9 backends
- publicly attested conformance in this repo: 4 backends

The correct interpretation is "the repo publishes partial live conformance evidence, not exhaustive public conformance evidence for every documented lane."

### 7.3 It does not turn every security property into a theorem

[position/coverage-gaps-and-mitigations.md](../position/coverage-gaps-and-mitigations.md) explicitly says some defenses are:

- mechanized
- bounded
- operational

That means the repo is not claiming theorem coverage for everything. It is claiming a layered assurance model and labeling the layers honestly.

### 7.4 It does not claim the Midnight story is complete

The five subsystem contracts are live on preprod. The three public attestation contracts are compiled and locally proven, but not yet deployed publicly. That distinction matters. It is already documented, and this report should preserve it rather than flatten it.

### 7.5 It does not remove the trust tradeoff of proprietary infrastructure

The repo reduces trust burden by publishing evidence. It does not erase the fact that ZirOS core remains proprietary. Developers still have to decide whether the published evidence, integrity manifests, theorem metadata, and live deployment artifacts are sufficient for their threat model and procurement model.

That is not a flaw in the report. That is the actual decision surface.

## 8. Why This Report Matters

Every other serious ZirOS-adjacent repo having a report is not an aesthetic issue. It is a trust issue.

Long-form reports do something badges and JSON cannot do on their own:

- they explain the system in human terms
- they connect the evidence files to an architectural story
- they name the boundary conditions clearly
- they tell a developer what they are actually buying into

For ZirOS specifically, that matters even more than usual because the system is source-private. If the repo only published badges, counts, and manifests, skeptics would be right to say the system is underspecified. A real report closes that gap by explaining:

- what ZirOS is
- what the evidence repo proves
- what the evidence repo does not prove
- what the developer experience is supposed to look like
- where Midnight fits
- where the public/private line is drawn

The report is part of the trust model.

## 9. Verdict

The public attestation repository makes a strong case for ZirOS, but not because it claims too much.

It makes a strong case because it does three hard things at once:

1. It publishes concrete machine-verifiable evidence.
2. It exposes real interface and deployment surfaces.
3. It states the private boundary and residual gaps directly.

That is the correct way to publish a source-private proving system.

The best reason to read this repository is not the headline numbers. It is the disclosure discipline. The repo gives a developer a complete enough picture to answer the questions that actually matter:

- Is there a real theorem ledger?
- Is there real conformance evidence?
- Is there a real release integrity surface?
- Is there a real Midnight deployment surface?
- Is the developer experience described clearly?
- Are the limitations named instead of hidden?

On the public evidence now available, the answer to all of those is yes.

## 10. Recommended Reading Order

For a first pass through the public repo, read these in order:

1. [README.md](../README.md)
2. [attestation/latest.json](../attestation/latest.json)
3. [ledger/ledger-summary.json](../ledger/ledger-summary.json)
4. [proof-server/endpoint-spec.md](../proof-server/endpoint-spec.md)
5. [midnight/explorer-links.md](../midnight/explorer-links.md)
6. [midnight/attestation-contracts.md](../midnight/attestation-contracts.md)
7. [position/coverage-gaps-and-mitigations.md](../position/coverage-gaps-and-mitigations.md)
8. [position/source-code-protection.md](../position/source-code-protection.md)
9. [position/third-party-audits.md](../position/third-party-audits.md)

That sequence gives the reader the same thing this report is trying to give them: the system, the evidence, the boundary, and the trust model.
