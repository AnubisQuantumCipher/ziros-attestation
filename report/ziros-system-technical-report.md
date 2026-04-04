# ZirOS System: Technical Report

## The Zero-Knowledge Operating System

### Publication state: ZirOS v0.4.1, public attestation generated 2026-04-04
### 24/24 published conformance tests passed. 160 verification-ledger rows (160 mechanized, 0 pending). 60-cycle Metal GPU soak certified. 5 Midnight preprod contracts live. 7 Midnight developer commands shipped. midnight-probe 1.0.1 on npm. Public repository is evidence-only by design.

---

## 1. What ZirOS Is

The easiest way to misunderstand ZirOS is to call it a library. That is wrong.

ZirOS is a system layer. It sits between a developer's statement and the cryptographic machinery that proves the statement. It owns the compile, prove, verify, export, deployment, attestation, and boundary-discipline path. That is why the repository calls it a zero-knowledge operating system instead of a framework.

The public claim is not subtle:

- 496,000 lines of Rust
- 30 workspace crates
- 9 proving backends
- 7 circuit frontends
- 63 Metal GPU shaders with 50 kernel entrypoints and 5 soak-certified accelerators
- 160 mechanized theorem rows (plus 9 hypothesis-stated protocol entries in development)
- 0 pending ledger rows
- 60-cycle Metal GPU soak certification (zero degraded, 12 hours sustained)
- Apple Silicon native release artifacts
- 7 shipped Midnight developer commands (proof-server, gateway, doctor, disclosure, resolve, templates, init)
- midnight-probe diagnostic toolkit published on npm
- Halo2 BLS12-381 versioned params cache (10x cold-to-warm improvement)
- MSM Metal segmentation for large constraint wrap paths
- Native Midnight wallet with FFI-enforced approval chain, quantum encrypted messaging, and DUST-first UX (built, not publicly released)

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
| GPU acceleration | Apple Metal lane with 63 shaders, 50 kernel entrypoints, 5 soak-certified accelerators (constraint_eval, field_ops, fri, hash, msm) |
| Artifact security | ML-DSA-87 post-quantum signing policy and binary hash manifests |
| Deployment/export | Solidity verifier export, Midnight proof-server compatibility, Compact contract evidence |
| Midnight toolchain | Resolver (version drift auto-fix), disclosure analyzer (Compact boundary taint tracking), doctor (environment readiness), 6 DApp templates, midnight-probe on npm |
| Soak certification | 60-cycle sustained proving with Metal GPU, zero degraded runs, 12 hours on Falcon Heavy physics workload |
| Cache infrastructure | Halo2 BLS12-381 versioned on-disk params cache with atomic writes and corrupt-cache regeneration (1,362s cold to 132s warm) |
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

- 160 total public ledger rows (160 mechanized local, 0 pending; plus 9 hypothesis-stated protocol entries excluded from the public ledger)
- checker split of 59 Rocq, 86 Verus, 13 Lean, 2 F*

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

## 8. Metal GPU Soak Certification

The soak certification is a 12-hour sustained proving test that validates Metal GPU acceleration under continuous load. This is not a benchmark. It is a reliability certification.

**Results:** 60 cycles completed, zero degraded, 12 hours 10 minutes elapsed, Falcon Heavy ascent trajectory workload (187 Goldilocks steps, 3,569 signals, 4,879 constraints).

**What it proved:**
- Metal NTT acceleration is realized and stable in the Plonky3 STARK proving path
- Memory usage is constant across all 60 cycles (16.9 MB per cycle, no leaks)
- No GPU dispatch failures, no watchdog timeouts, no attestation chain breaks
- 5 active accelerators confirmed: constraint_eval, field_ops, fri, hash, msm
- Hash-merkle stage falls back to CPU when trace width exceeds the current MMCS Metal limit (documented limitation, not a failure)

**What it did not prove:**
- The STARK-to-Groth16 wrap path was not soak-certified on the M4 Max 48GB. The 27.5M constraint wrap requires approximately 66 GB peak memory footprint, which exceeds the 48 GB physical memory. Wrap soak certification is pending fleet hardware (192 GB Mac Studio Ultra machines).

The full soak report is published at [evidence/soak-certification-v0.4.1-20260403.json](../evidence/soak-certification-v0.4.1-20260403.json).

## 9. Midnight Developer Toolchain

The Midnight integration has expanded from a proof-server compatibility surface to a complete developer toolchain. Seven shipped commands now live under `zkf midnight`:

| Command | What it does |
| --- | --- |
| `zkf midnight proof-server serve` | Native Halo2-KZG proof server on port 6300 with 10 HTTP endpoints. No Docker dependency. Apple Silicon first-class. UMPG engine routing. |
| `zkf midnight resolve` | Reads a project's `package.json`, compares all `@midnight-ntwrk/*` dependencies against the 22-package embedded manifest, identifies version mismatches, and rewrites the file with compatible versions. Optionally runs `npm install`, compiles Compact contracts, and validates artifacts. |
| `zkf midnight disclosure` | Taint-tracks witness flow through the Compact constraint graph and classifies every public signal as disclosed-public, commitment-public-hash, private-only, or uncertain. Fails closed on untracked public exposure. |
| `zkf midnight doctor` | Reports toolchain (Node, npm, compactc), package pin, network reachability, proof server health, wallet detection, Lace status, and DUST readiness in one check. |
| `zkf midnight init` | Scaffolds a pinned, production-mode Midnight DApp project from one of 6 verified templates. |
| `zkf midnight templates` | Lists the 6 shipped Midnight DApp templates with backend lanes and package pin counts. |
| `zkf midnight gateway serve` | Fail-closed Compact admission gateway on port 6311 with ML-DSA-87 attestations and compactc 0.30.0 enforcement. |

**midnight-probe** is a separate free, MIT-licensed npm package published at version 1.0.1. It provides diagnostic commands (`fingerprint`, `test-deploy`, `canary`, `matrix`) that identify chain-level issues, SDK version mismatches, and validator health. Every diagnostic output points developers to `zkf midnight resolve` as the fix. The probe creates demand. The binary fulfills it.

The embedded manifest pins 22 `@midnight-ntwrk/*` packages at versions known to be compatible with specVersion 22000:

- compactc 0.30.0, compact-runtime 0.15.0, compact-js 2.5.0
- midnight-js-* 4.0.2 across contracts, types, compact, and provider surfaces
- ledger-v8 8.0.3, wallet-sdk-facade 3.0.0, dapp-connector-api 4.0.1
- Required Node: 22

## 10. Halo2 BLS12-381 Cache and MSM Segmentation

Two infrastructure improvements were shipped in v0.4.1 that materially affect proving performance:

**Halo2 BLS12-381 versioned params cache:** KZG proving parameters now persist to disk at `~/.zkf/cache` with atomic writes and SHA-256 version keys. The first cold run generates deterministic params (can take 22+ minutes for k=18). Subsequent runs hit the disk cache and load in seconds. Corrupt or unreadable cache files are silently regenerated instead of failing the prove path. Cold-to-warm improvement: 1,362 seconds to 132 seconds (10x).

**MSM Metal segmentation:** The BN254 MSM (multi-scalar multiplication) Metal kernel now segments large problem sizes instead of attempting a single monolithic dispatch. This eliminates the Metal command buffer watchdog timeout that previously killed the STARK-to-Groth16 wrap admission gate on the M4 Max. The segmentation fix is structural, not a workaround -- it allows the GPU to process the MSM in bounded chunks within the watchdog window.

## 11. Post-Quantum Encrypted Channel Infrastructure

ZirOS includes a hybrid post-quantum encrypted messaging channel implementation in the distributed cluster and wallet subsystem layers. The cryptographic construction is production-grade and tested:

- **Key exchange:** ML-KEM-1024 (FIPS 203, Level 5) combined with X25519 in a hybrid construction. Both classical and post-quantum legs must succeed. The combined shared secret is fed into HKDF-SHA384 to derive a 32-byte symmetric key.
- **Symmetric encryption:** ChaCha20-Poly1305 with random 12-byte nonces and 5-field associated data binding (message kind, sender, receiver, sequence, epoch).
- **Envelope signing:** ML-DSA-87 (FIPS 204, Level 5) signatures on every encrypted envelope. The sender's identity is cryptographically bound to the envelope via a Poseidon fingerprint of their ML-DSA-87 verification key.
- **Forward secrecy:** Epoch-based key rotation (hourly). Keys for the current and previous epoch are retained; all older keys are dropped. Compromising the current key does not decrypt messages from two or more hours ago.
- **Conversation storage:** Encrypted at rest with ChaCha20-Poly1305 using a domain-separated storage key derived from the same root material.
- **Message types:** text, transfer receipt, credential request, credential response.
- **Tests:** Bidirectional key derivation, bilateral encryption round-trips, epoch grace window acceptance, stale epoch rejection, ciphertext tampering detection, peer identity impersonation rejection.

This infrastructure is relevant to the architectural claims because it demonstrates that ZirOS's post-quantum cryptographic surface extends beyond proof signing into real-time communication channels. The epoch rotation pattern originated in the swarm defense Diplomat component (`zkf-distributed/src/swarm/epoch.rs`) and was adapted for wallet-to-wallet messaging.

## 12. FFI-Enforced Approval Chain

ZirOS includes a two-phase approval chain enforced entirely in compiled Rust behind opaque FFI handles. This architecture is designed for any external application that consumes the ZirOS proving engine through the C ABI:

- **Phase 1 (ApprovalToken):** A biometric authentication (Touch ID / Face ID via Secure Enclave) mints a single-use token bound to origin, network, method, transaction digest, and expiry.
- **Phase 2 (SubmissionGrant):** The approval token is consumed to mint a submission grant -- a second single-use artifact that authorizes a helper process to finalize and submit a transaction.
- **Enforcement:** The Rust core rejects any submit path that lacks a valid, unexpired, unconsumed grant with matching origin, network, method, and digest bindings. A compromised UI layer cannot bypass the policy because the enforcement is in compiled Rust, not in the application code.
- **Lifecycle:** All approval state (tokens, grants, pending approvals) is cleared on lock, background, or idle timeout. Nothing survives a session boundary.

This pattern is not specific to any single application. It is a general-purpose approval architecture for any system that needs hardware-enforced transaction authorization with the proving engine.

## 13. Updated Formal Coverage State

The public ledger now contains 160 mechanized entries (previously 169). The change reflects an honest reclassification:

- 160 entries remain `mechanized_local` with corresponding proof files in the private repository
- 9 entries were reclassified from `mechanized_local` to `hypothesis_stated` because their referenced Lean 4 proof files (`Groth16Exact.lean`, `FriExact.lean`, `NovaExact.lean`, `HyperNovaExact.lean`) do not exist in the current checkout
- The 9 hypothesis-stated entries are protocol-level soundness theorems (completeness, knowledge soundness, zero knowledge) with explicitly stated mathematical hypotheses (KEA, Reed-Solomon completeness, commitment binding)
- These entries are excluded from the public ledger because the CI validation requires all published entries to be `mechanized_local`
- The theorem statements and hypotheses are specified in the private verification ledger; the Lean 4 proof files are planned but not yet written

This reclassification follows the constitutional guarantee: the ledger distinguishes between what is proven and what is not. The 9 entries will return to the public ledger when the Lean 4 files exist.

Updated checker distribution for the 160 public entries: 59 Rocq, 86 Verus, 13 Lean, 2 F*.

## 14. Why This Report Matters (unchanged from original)

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

## 15. Verdict

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

## 16. Recommended Reading Order

For a first pass through the public repo, read these in order:

1. [README.md](../README.md)
2. [attestation/latest.json](../attestation/latest.json)
3. [evidence/soak-certification-v0.4.1-20260403.json](../evidence/soak-certification-v0.4.1-20260403.json)
4. [ledger/ledger-summary.json](../ledger/ledger-summary.json)
5. [proof-server/endpoint-spec.md](../proof-server/endpoint-spec.md)
6. [midnight/explorer-links.md](../midnight/explorer-links.md)
7. [midnight/attestation-contracts.md](../midnight/attestation-contracts.md)
8. [evidence/evidence-package.json](../evidence/evidence-package.json)
9. [position/coverage-gaps-and-mitigations.md](../position/coverage-gaps-and-mitigations.md)
10. [position/source-code-protection.md](../position/source-code-protection.md)
11. [position/third-party-audits.md](../position/third-party-audits.md)

That sequence gives the reader the same thing this report is trying to give them: the system, the evidence, the soak certification, the Midnight toolchain, the boundary, and the trust model.
