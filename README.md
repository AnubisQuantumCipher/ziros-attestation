# ZirOS

### *The Zero-Knowledge Operating System*

![Mechanized Theorems](https://img.shields.io/badge/Mechanized%20Theorems-169-0b6e4f)
![Backends](https://img.shields.io/badge/Proving%20Backends-9-1f4f99)
![Post-Quantum](https://img.shields.io/badge/Post--Quantum-ML--DSA--87%20Level%205-5a3ec8)
![Midnight](https://img.shields.io/badge/Midnight%20Network-5%20Live%20Contracts-5b4b3a)
![GPU](https://img.shields.io/badge/GPU-Apple%20Metal%2050%20Kernels-7a1f1f)
![Lines](https://img.shields.io/badge/Rust-290%2C000%20Lines-orange)

---

> *"I prove that something is true without revealing why it is true. The math is the authority. The proofs are mechanized. The system fails closed."*

---

## What Is ZirOS

**ZirOS is not a library.** It is not a framework. It is not a wrapper around someone else's proving system.

**ZirOS is a zero-knowledge operating system** — the system layer between what you want to prove and the raw cryptographic machinery that proves it. It owns the *entire path* from your statement to a verified, signed, post-quantum proof artifact.

**290,000 lines of Rust** across **30 workspace crates**. **9 proving backends** across **7 finite fields**. **7 circuit frontends**. **63 Metal GPU shaders** with **50 kernel entrypoints**. **169 mechanized theorems** across **5 formal proof languages** with **zero pending claims**. **Post-quantum signatures** (ML-DSA-87, NIST Level 5) on every artifact. **Apple Silicon native** — shaped around the M4 Max unified memory architecture, Metal GPU, Neural Engine, Secure Enclave, and iCloud Drive.

One person built this. The contracts are live on Midnight. The proofs verify. The code is invisible.

| | |
|---|---|
| **Scale** | 290,000 lines of Rust, 30 crates, 1,047 tests passing |
| **Proving** | 9 backends, 7 fields, 7 frontends, 11 gadgets |
| **GPU** | 63 Metal shaders, 50 kernels, 8 accelerators, 14 prewarmed pipelines |
| **AI Control Plane** | 6 CoreML Neural Engine model lanes (38 TOPS on M4 Max) |
| **Formal Verification** | 169 mechanized theorems (Lean 4, Rocq, Verus, F*, Kani), 0 pending |
| **Post-Quantum** | ML-DSA-87 (FIPS 204), ML-KEM-1024 (FIPS 203), CNSA 2.0 Level 5 |
| **Midnight Network** | Native GPU-accelerated proof server, 5 live Compact contracts |
| **Ethereum** | 128-byte Groth16 proofs, ~210K gas verification, Solidity export |
| **Defense** | Swarm anomaly detection, attack genome sequencing, honeypot traps |
| **Agentic** | Designed for Claude Code (Opus 4.6) and Codex autonomous operation |

---

## Download & Install

**[Download ZirOS v0.4.0 for Apple Silicon](https://github.com/AnubisQuantumCipher/ziros-attestation/releases/download/v0.4.0/zkf-aarch64-apple-darwin-v0.4.0.tar.gz)** — *85 MB, aarch64-apple-darwin, stripped release binary with LTO*

```bash
# Download and install
curl -LO https://github.com/AnubisQuantumCipher/ziros-attestation/releases/download/v0.4.0/zkf-aarch64-apple-darwin-v0.4.0.tar.gz
tar xzf zkf-aarch64-apple-darwin-v0.4.0.tar.gz
sudo cp aarch64-apple-darwin/zkf /usr/local/bin/

# Verify installation
zkf doctor --json

# Build and prove your first circuit in 30 seconds
zkf emit-example --field goldilocks --out example.json
echo '{"x": "3", "y": "5"}' > inputs.json
zkf prove --program example.json --inputs inputs.json --backend plonky3 --out proof.json
zkf verify --program example.json --artifact proof.json --backend plonky3
# → verification: OK
```

**What's in the download:**

| File | Size | What It Does |
|------|------|-------------|
| `zkf` | 33 MB | CLI binary — 38 commands: compile, prove, verify, deploy, wrap, fold, benchmark, audit, and more |
| `libzkf_ffi.dylib` | 12 MB | Dynamic library — the entire proving engine as a callable C ABI with opaque handles |
| `libzkf_ffi.a` | 170 MB | Static library — same engine, all dependencies included |
| `zkf.h` | 2 KB | C header — [56 lines, opaque handles](binary-manifest/v0.4.0/zkf.h), 14 extern functions |
| `manifest.json` | 544 B | [SHA-256 hashes](binary-manifest/v0.4.0/manifest.json) of all binaries for integrity verification |

**Verify integrity:**
```bash
shasum -a 256 aarch64-apple-darwin/zkf
# Expected: 6af0cefa7c3fbcff5df266fea031fbab0a72d3927f7634561d1de306ac29547c
```

**Releases:** [All releases](https://github.com/AnubisQuantumCipher/ziros-attestation/releases) | **License:** ZirOS Core Proprietary — free to use, [commercial license](https://github.com/AnubisQuantumCipher) required for production deployment and managed services

---

## What You Can Build

ZirOS generates complete subsystem applications from domain specifications. Your code is yours — your license, your contracts, your product. ZirOS's engine stays invisible.

| Domain | What You Can Prove | Example |
|--------|-------------------|---------|
| **DeFi / Ethereum** | 128-byte Groth16 proofs verifiable on-chain for ~$15 gas | Solidity verifier contracts for any circuit |
| **Cooperative Governance** | Treasury compliance, lending fairness, equity distribution | [5 live contracts on Midnight](midnight/explorer-links.md) |
| **Aerospace** | Reentry thermal envelopes, powered descent, orbital dynamics | 256-step RK4 reentry certificate |
| **Private Identity** | Age verification, KYC compliance without revealing identity | ML-DSA-87 signed credentials |
| **Midnight Network** | Compact smart contracts with selective disclosure | Native GPU-accelerated proof server |
| **Scientific** | Thermochemical equilibrium, Navier-Stokes, combustion instability | 22 built-in templates |

**The developer experience:**

```rust
// Your code — you own it, whatever license you want
use zkf_sdk::{ProgramBuilder, FieldId, Expr, compile_default, prove, verify};

let mut builder = ProgramBuilder::new("my_circuit", FieldId::Bn254);
builder.private_input("secret")?;
builder.public_output("commitment")?;
builder.constrain_equal(Expr::signal("commitment"), Expr::signal("secret"))?;

let program = builder.build()?;
// builder.build() calls into libzkf.dylib — you never see the internals
```

Or use the CLI directly — no Rust required:

```bash
# Define your circuit in JSON
zkf compile --spec zirapp.json --backend plonky3 --out compiled.json
zkf prove --program zirapp.json --inputs inputs.json --backend plonky3 --out proof.json
zkf verify --program zirapp.json --artifact proof.json --backend plonky3

# Deploy a Solidity verifier to Ethereum
zkf deploy --artifact proof.json --backend arkworks-groth16 --out Verifier.sol --evm-target ethereum

# Scaffold a complete app from a template
zkf app init my-app --template range-proof --style colored
cd my-app && cargo run
```

**Full SDK API:** [sdk/api-surface.md](sdk/api-surface.md) | **Example circuit:** [sdk/example-circuit.rs](sdk/example-circuit.rs) | **Proof server endpoints:** [proof-server/endpoint-spec.md](proof-server/endpoint-spec.md)

---

## Agentic Operation — Best With Claude Code or Codex

ZirOS is an agentic system. It is designed to be operated by AI — not just used as a tool, but driven autonomously by a language model that understands zero-knowledge proving, circuit construction, and proof verification.

**Recommended:** [Claude Code](https://claude.com/claude-code) with Claude Opus 4.6 (1M context) or [Codex](https://openai.com/codex) for scheduled automation.

### Why Agentic

Traditional ZK frameworks require you to manually write circuits, configure backends, manage witnesses, run provers, and verify artifacts. ZirOS is built so an AI agent can do all of this autonomously:

- **"Prove this circuit"** — the agent selects the backend, compiles, generates the witness, proves, and verifies
- **"Deploy a Solidity verifier"** — the agent picks Groth16, generates the proof, exports the contract, estimates gas
- **"Run conformance across all backends"** — the agent runs Plonky3, Halo2, Nova, HyperNova, compares outputs
- **"Scaffold me a range proof app"** — the agent runs `zkf app init`, sets up the project, runs the smoke tests
- **"Wrap this STARK to Groth16"** — the agent plans the wrapping pipeline, monitors memory, handles the Nova IVC decomposition
- **"Check system health"** — the agent runs `zkf doctor`, `zkf metal-doctor`, inspects GPU readiness, reports anomalies

### How To Use With Claude Code

```bash
# Install ZirOS, then start Claude Code in your project directory
claude

# Tell it what you want
> Build me a circuit that proves a value is within a 32-bit range,
  prove it with Plonky3, and verify the proof.

# Claude Code calls zkf directly:
#   zkf emit-example → zkf prove → zkf verify → done
```

Claude Code with Opus 4.6 has a 1M token context window — large enough to hold the entire ZirOS CLI reference, understand all 38 commands, and chain multi-step proving workflows without losing track of state.

### How To Use With Codex (Scheduled Automation)

Codex can run ZirOS tasks on a schedule — weekly attestations, daily conformance tests, automated proof generation:

```
Codex Scheduled Task (weekly, Monday 2:00 AM):

"Run ZirOS conformance across all backends. If all pass, generate a fresh
attestation witness, prove it locally, and save the report. If any backend
fails, stop and report which test failed."
```

### Agentic Architecture

ZirOS supports five agent patterns:

| Agent Type | What It Does | Trigger |
|-----------|-------------|---------|
| **Proving Agent** | Selects backend, compiles, proves, verifies | On demand |
| **Testing Agent** | Runs conformance, soak tests, formal verification | Scheduled or on demand |
| **Healing Agent** | Monitors system health, restarts crashed services, reroutes failed backends | Every 15 minutes |
| **Blueprint Executor** | Executes multi-week plans with checkpointing and error recovery | Scheduled |
| **Daemon Agent** | Background event loop — spawns other agents when events occur | Continuous |

Every `zkf` command supports `--json` output for machine parsing. Every error includes a remediation suggestion. The system is built to be operated by AI from the ground up.

---

## Public Attestation Repository

This repository is public, evidence-only, and intentionally source-free. It publishes machine-verifiable attestation data and interface-level architecture documentation for the private ZirOS core.

Nothing here contains ZirOS implementation source, proof construction files, GPU kernels, Cargo manifests, build scripts, or private workspace paths. The publication boundary and leak-prevention rules are documented in [SECURITY.md](SECURITY.md) and [position/source-code-protection.md](position/source-code-protection.md).

| Evidence | Link |
|----------|------|
| Weekly attestation | [attestation/latest.json](attestation/latest.json) |
| Verification ledger (169 theorems) | [ledger/verification-ledger.json](ledger/verification-ledger.json) |
| Backend conformance | [conformance/latest/](conformance/latest/) |
| Binary integrity (SHA-256) | [binary-manifest/v0.4.0/manifest.json](binary-manifest/v0.4.0/manifest.json) |
| SDK API surface | [sdk/api-surface.md](sdk/api-surface.md) |
| Proof server spec | [proof-server/endpoint-spec.md](proof-server/endpoint-spec.md) |
| Evidence package | [evidence/evidence-package.json](evidence/evidence-package.json) |
| Midnight deployments | [midnight/explorer-links.md](midnight/explorer-links.md) |

## The Proving Engine

The table below is the disclosed proving-lane architecture. Live binary/backend readiness and compatibility policy are published separately in [capability-matrix/backends.json](capability-matrix/backends.json). Public conformance evidence in this repo currently covers Plonky3, Halo2, Nova, and HyperNova.

| Backend | Field | Setup Type | Proof Size | Post-Quantum | GPU Stages | Notes |
|---------|-------|------------|------------|--------------|------------|-------|
| Plonky3 STARK | Goldilocks, BabyBear, Mersenne31 | Transparent | 1-10 KB | Yes | NTT + Merkle | Default transparent proof lane |
| Groth16 | BN254 | Trusted setup | 128 bytes | No | MSM + NTT + QAP | Smallest proof, EVM-verifiable |
| Halo2 IPA | Pasta Fp | Transparent | ~3 KB | No | MSM | Transparent Plonkish lane |
| Halo2 KZG | BLS12-381 | Trusted setup | ~3 KB | No | None | BLS12-381 Plonkish lane |
| Nova | BN254 | Transparent | ~1.77 MB | No | None | IVC folding |
| HyperNova | BN254 | Transparent | Variable | No | None | CCS multifolding |
| SP1 | Delegated to Plonky3 | Delegated | ~1 KB | Delegated PQ | None | Compatibility lane |
| RISC Zero | Delegated to Plonky3 | Delegated | ~1 KB | Delegated PQ | None | Compatibility lane |
| STARK-to-SNARK | Goldilocks inner to BN254 outer | Hybrid | 128 bytes outer proof | Inner yes, outer no | Full wrapper path | Nova IVC decomposition for wrapper lane |

### Live Conformance Published Here

| Backend | Tests Run | Tests Passed | Evidence |
|---------|-----------|--------------|----------|
| Plonky3 | 6 | 6 | [conformance/latest/plonky3.json](conformance/latest/plonky3.json) |
| Halo2 | 6 | 6 | [conformance/latest/halo2.json](conformance/latest/halo2.json) |
| Nova | 6 | 6 | [conformance/latest/nova.json](conformance/latest/nova.json) |
| HyperNova | 6 | 6 | [conformance/latest/hypernova.json](conformance/latest/hypernova.json) |

## Circuit Frontends

Seven import surfaces are documented for the private core. After import, programs pass through one compile/prove/verify pipeline.

| Frontend | Input Formats | Status |
|----------|---------------|--------|
| Noir | ACIR artifact JSON, ACIR program JSON | Ready |
| Circom | snarkjs-style R1CS JSON, ZKF program JSON, frontend descriptor JSON | Ready |
| Cairo | Sierra JSON, Cairo descriptor JSON, ZKF program JSON, ZIR JSON | Limited |
| Compact | Midnight ZKIR v2.0, Compact descriptor JSON, ZKF program JSON, Compact source | Ready |
| Halo2-Rust | Halo2 export JSON, Halo2 export descriptor JSON | Ready |
| Plonky3-AIR | Plonky3 AIR export JSON, AIR export descriptor JSON | Ready |
| zkVM | SP1 and RISC Zero descriptor JSON, ZKF program JSON | Ready |

See [capability-matrix/frontends.json](capability-matrix/frontends.json).

## Gadgets

| Gadget | Field Support | Status |
|--------|---------------|--------|
| blake3 | BN254, BLS12-381, Pasta Fp, Pasta Fq, Goldilocks | Ready |
| boolean | BN254, BLS12-381, Pasta Fp, Pasta Fq, Goldilocks, BabyBear, Mersenne31 | Ready |
| comparison | BN254, BLS12-381, Pasta Fp, Pasta Fq, Goldilocks, BabyBear, Mersenne31 | Ready |
| ecdsa | BN254 | Limited |
| kzg | BN254, BLS12-381 | Limited |
| merkle | BN254, BLS12-381, Pasta Fp, Goldilocks, BabyBear, Mersenne31 | Ready |
| plonk_gate | All 7 fields | Ready |
| poseidon | BN254, BLS12-381, Pasta Fp, Goldilocks, BabyBear, Mersenne31 | Ready |
| range | All 7 fields | Ready |
| schnorr | BN254 | Limited |
| sha256 | BN254, BLS12-381, Pasta Fp, Goldilocks, BabyBear, Mersenne31 | Ready |

See [capability-matrix/gadgets.json](capability-matrix/gadgets.json).

## Seven Fields

| Field | Bit Width | Modulus | Primary Backend |
|-------|-----------|---------|-----------------|
| BN254 | 254-bit | 21888242871839275222246405745257275088548364400416034343698204186575808495617 | Groth16, Nova, HyperNova |
| BLS12-381 | 255-bit | 52435875175126190479447740508185965837690552500527637822603658699938581184513 | Halo2 KZG |
| Pasta Fp | 255-bit | 28948022309329048855892746252171976963363056481941560715954676764349967630337 | Halo2 IPA |
| Pasta Fq | 255-bit | 28948022309329048855892746252171976963363056481941647379679742748393362948097 | Midnight Compact |
| Goldilocks | 64-bit | 18446744069414584321 | Plonky3 |
| BabyBear | 32-bit | 2013265921 | Plonky3 |
| Mersenne31 | 31-bit | 2147483647 | Plonky3 |

## Apple Metal GPU Acceleration

The disclosed GPU lane covers 63 Metal shader sources, 50 kernel entrypoints, 8 active accelerators, 14 prewarmed pipelines, and a fail-closed 4-digest attestation chain. The public evidence package also publishes the current attested accelerator set and pipeline count.

| Accelerator | Scope |
|-------------|-------|
| MSM | BN254, Pallas, Vesta multi-scalar multiplication |
| NTT | Goldilocks, BabyBear, BN254 number-theoretic transforms |
| Poseidon2 | Algebraic hash permutation |
| SHA-256 | Batch hash lane |
| FRI | Folding for STARK proof flow |
| Constraint Evaluation | Polynomial constraint evaluation |
| Field Arithmetic | Batched field operations |
| Polynomial Operations | Polynomial evaluation and quotient work |

| Property | Value |
|----------|-------|
| Metal shader sources | 63 |
| Kernel entrypoints | 50 |
| Active accelerators | 8 |
| Prewarmed pipelines | 14 |
| Attestation manifests | 9 |
| Attestation chain | Metallib digest, reflection digest, pipeline descriptor digest, toolchain identity |
| Fallback policy | CPU fallback on attestation failure; never silent degradation |
| Adaptive tuning | EMA convergence over 20 observations per operation per device |
| Target GPU busy ratio | 25% |
| MSM arithmetic optimization | Montgomery `mulhi()` path with documented 66% throughput improvement |

See [evidence/evidence-package.json](evidence/evidence-package.json).

## Neural Engine Control Plane

ZirOS documents six CoreML lanes running on the Apple Neural Engine on M4 Max class hardware. This control plane is advisory only. Proof truth never depends on model output. If model integrity, feature shape, or bundle hash checks fail, bundles are quarantined and heuristic scheduling takes over.

| Lane | Purpose |
|------|---------|
| Scheduler | Parallel job scheduling optimization |
| Backend Recommender | Backend selection guidance |
| Duration Estimator | Proving-time prediction |
| Anomaly Detector | Behavioral anomaly scoring |
| Security Detector | Security-relevant pattern detection |
| ThresholdOptimizer | Adaptive GPU busy-ratio tuning |

| Control-Plane Rule | Contract |
|--------------------|----------|
| Hardware target | Apple Neural Engine, 38 TOPS on M4 Max |
| Feature surface | Circuit, hardware, and thermal telemetry vectors |
| Supply-chain integrity | SHA-256 manifest pinning, quarantine markers, model-integrity verification |
| Failure mode | Advisory-only quarantine, never proof-plane corruption |

## Unified Memory Prover Graph (UMPG)

UMPG plans, materializes, executes, and certifies proving jobs across CPU, GPU, and the advisory Neural Engine surface. The public architectural contract exposes three memory classes, three execution modes, and three trust lanes.

| Memory Class | Role |
|--------------|------|
| HotResident | Proving keys, twiddle tables, MSM bases |
| EphemeralScratch | Intermediate NTT stages, partial buckets, batched hash outputs |
| Spillable | Large traces, archived polynomial chunks, old Merkle layers |

| Execution Mode | Behavior |
|----------------|----------|
| Deterministic | Strict topological order on CPU; reproducible |
| Adaptive | Device placement chosen per node |
| Benchmark | Detailed timing and resource collection |

| Trust Lane | Meaning |
|------------|---------|
| StrictCryptographic | Only cryptographic in-circuit proofs admitted |
| AllowAttestation | Host-validated attestation lanes may be admitted |
| AllowMetadataOnly | Metadata-only markers may be admitted |

UnifiedBufferPool lives in unified CPU/GPU memory, tracks per-slot metadata and liveness, and uses FNV-1a content digests for integrity on the spill/reload boundary.

## Swarm Defense System

The disclosed swarm architecture has seven components and a hard non-interference boundary: it may affect scheduling, peer selection, or escalation state, but never proof truth.

| Component | Role |
|-----------|------|
| Queen | Escalation state machine with exponential decay and predictive lookahead |
| Sentinel | 6-dimensional anomaly detection with Welford variance and Mahalanobis distance |
| Warrior | Multi-backend quorum verification, diversity enforcement, containment policy |
| Builder | Rule lifecycle, shadow deployment, attack-genome sequencing, signed audit trail |
| Diplomat | ML-KEM-1024 encrypted gossip |
| Identity | Ed25519 + ML-DSA-87 dual signing |
| Reputation | 0-1 peer score with 10% hourly change cap |

| Swarm Fact | Published Contract |
|------------|--------------------|
| Escalation states | Dormant, Alert, Active, Emergency |
| Side-channel probes | ARM cache-flush timing probes |
| Threat signal types | 24 |
| Security actions | 11 |
| Risk levels | 5 |
| Non-interference claim | Swarm affects scheduling, never artifact truth |
| Published bounded claim | `controller_artifact_mutation_surface_count() -> 0` |

## Post-Quantum Cryptographic Surface

| Component | Classification | Mathematical Basis |
|-----------|----------------|--------------------|
| ML-DSA-87 | Post-quantum | NIST FIPS 204 Level 5, lattice-based signatures |
| ML-KEM-1024 | Post-quantum | NIST FIPS 203 Level 5, lattice-based key exchange |
| HKDF-SHA384 | Post-quantum-compatible derivation | CNSA 2.0 key derivation surface |
| ChaCha20-Poly1305 | Symmetric PQ-safe | 256-bit symmetric encryption; Grover reduces effective strength to 128-bit |
| Plonky3 STARK | Post-quantum | FRI is hash-based, no elliptic curves |
| Groth16 | Classical | BN254 pairings are Shor-vulnerable |
| Halo2 IPA | Classical | Pasta-curve discrete-log assumptions |
| Halo2 KZG | Classical | BLS12-381 pairing assumptions |
| Nova / HyperNova | Classical | Pallas/Vesta discrete-log assumptions |
| STARK-to-SNARK wrapper | Mixed | Inner STARK remains PQ; outer Groth16 wrapper is classical |

The system documents CNSA 2.0 Level 5 alignment for the signature and key-establishment lanes. See [capability-matrix/post-quantum.json](capability-matrix/post-quantum.json).

## Formal Verification

The live public theorem ledger in this repository contains 169 mechanized entries, 0 pending entries, and 0 model-only claims. The bounded-check and proof-tool inventory described below is part of the documented verification surface, even though this repository deliberately omits the proof files themselves.

| Domain | Theorems |
|--------|----------|
| zkf-runtime | 70 |
| zkf-backends | 24 |
| zkf-distributed | 24 |
| zkf-core | 23 |
| zkf-lib | 15 |
| zkf-metal | 9 |
| zkf-ir-spec | 3 |
| zkf-frontends | 1 |

| Proof Surface | Published Inventory | Domain |
|---------------|---------------------|--------|
| Lean 4 | 19 files | GPU kernel correctness, protocol soundness |
| Rocq/Coq | 69+ files | IR semantics, witness correctness, runtime pipeline |
| Verus | 28 files | Runtime execution, swarm, aerospace surfaces |
| F* | 10 files, 6,049 lines | Constant-time properties |
| Kani | 90 harnesses across 6 crates | Bounded state-space exploration across core crates |

Constitutional rule: verification coverage is a one-way ratchet. It may increase. It is not weakened.

## Eight Defense Layers

| Layer | What It Covers | Evidence Surface |
|-------|----------------|------------------|
| Mechanized theorems | Logic correctness | [ledger/verification-ledger.json](ledger/verification-ledger.json) |
| F* constant-time proofs | Timing side channels | Published proof inventory and position docs |
| Kani model checking | Bounded state space | Documented bounded-check surface |
| Fail-closed audit | Underconstrained signals | Published weekly attestation contract and evidence |
| 12-hour soak test | Sustained load behavior | Operational evidence package |
| Security supervisor | Live runtime threats | Swarm and security position docs |
| GPU attestation chain | Kernel supply chain | Manifested attestation contract |
| ML-DSA-87 signatures | Artifact integrity | Binary and evidence manifests |

An audit firm reviews a snapshot. ZirOS publishes a continuously updated verification surface.

## Midnight Network Integration

ZirOS exposes a Midnight-compatible proof server and documents five deployed Compact contracts on Midnight preprod.

### Proof Server

| Endpoint | Method | Purpose |
|----------|--------|---------|
| `/prove` | POST | Generate a Midnight-compatible proof |
| `/check` | POST | Validate a proof; byte-equivalent verification surface |
| `/health` | GET | Liveness |
| `/ready` | GET | Queue depth and backpressure; returns 503 when saturated |
| `/prove-tx` | POST | Prove a Midnight transaction |
| `/version` | GET | Server version |
| `/proof-versions` | GET | Supported proof-format versions |
| `/k` | GET | Security parameter |
| `/fetch-params` | GET | Download proving parameters |

See [proof-server/endpoint-spec.md](proof-server/endpoint-spec.md).

### Live Midnight Preprod Contracts

| Contract | Explorer |
|----------|----------|
| Cooperative Treasury | [f99edfaf4ec0d46ea405e2e98d03c9fa40803a36555a5fa362a3879a54590d02](https://explorer.preprod.midnight.network/transactions/f99edfaf4ec0d46ea405e2e98d03c9fa40803a36555a5fa362a3879a54590d02) |
| Community Land Trust | [2f9f43543953478a7d8d409edee16f7ee6acab196be45c26c834b7e69036dda1](https://explorer.preprod.midnight.network/transactions/2f9f43543953478a7d8d409edee16f7ee6acab196be45c26c834b7e69036dda1) |
| Anti-Extraction Shield | [c147265a99848e16cbcebef7fcdb1069185f201f9d169b455af628f5eefa02c3](https://explorer.preprod.midnight.network/transactions/c147265a99848e16cbcebef7fcdb1069185f201f9d169b455af628f5eefa02c3) |
| Wealth Trajectory | [37c7aa632cf57ee72149b67daa6bf6055139f39331bb26c33229bef282f3b35f](https://explorer.preprod.midnight.network/transactions/37c7aa632cf57ee72149b67daa6bf6055139f39331bb26c33229bef282f3b35f) |
| Sovereignty Score | [1a6564f27868866ba9d6a0593029f42026b0687e113bc4ce9373c5662eb687cf](https://explorer.preprod.midnight.network/transactions/1a6564f27868866ba9d6a0593029f42026b0687e113bc4ce9373c5662eb687cf) |

Additional deployment details are published in [midnight/sed-deployment-manifest.json](midnight/sed-deployment-manifest.json), [midnight/explorer-links.md](midnight/explorer-links.md), and [midnight/attestation-contracts.md](midnight/attestation-contracts.md).

## Proof Wrapping (STARK-to-Groth16)

The public wrapping contract is a Nova IVC decomposition of the FRI verifier, not a monolithic direct wrap.

| Wrapper Stage | Published Scale |
|---------------|-----------------|
| Step circuit target | 100K-500K R1CS constraints per step |
| Step-circuit memory | ~200 MB |
| Folding steady state | ~165 MB |
| Final Groth16 wrapper | ~1M-2M constraints |
| Final wrapper memory | ~1 GB |
| Output | 128-byte Groth16 proof |
| Ethereum verification | ~210K gas |
| Verification time | 20 ms |

The trust boundary is explicit: the inner STARK is post-quantum; the outer Groth16 wrapper is not.

## Solidity Verifier Export

Groth16 artifacts can be exported to Solidity verifiers for EVM deployment.

| Target | Meaning |
|--------|---------|
| Ethereum mainnet | Default EVM publication target |
| Optimism / Arbitrum | L2 rollup target |
| Generic EVM | Portable EVM-compatible chain target |

| Cost Surface | Published Figure |
|--------------|------------------|
| Deploy gas | ~1.5M gas |
| Verify gas | ~210K gas per proof |

## Credential System

The disclosed credential surface is ML-DSA-87 signed, supports hybrid Ed25519 + ML-DSA-87 issuance, and proves policy satisfaction without revealing subject identity.

| Component | Contract |
|-----------|----------|
| Signature lanes | Ed25519, ML-DSA-87, HybridEd25519MlDsa87 |
| Zero-knowledge claim | Prove age `>= 21` or status policy satisfaction without revealing identity |
| Membership structure | Poseidon Merkle membership proofs |
| Encrypted file-key KDF | Argon2id, 4 GiB memory, 3 iterations, 1 lane |

## Binary Distribution

No binaries are published in this repository. Only their hashes and the opaque C header are published.

| Artifact | Size | Public Evidence |
|----------|------|-----------------|
| `zkf` | 33 MB | [binary-manifest/v0.4.0/manifest.json](binary-manifest/v0.4.0/manifest.json) |
| `libzkf_ffi.dylib` | 12 MB | [binary-manifest/v0.4.0/manifest.json](binary-manifest/v0.4.0/manifest.json) |
| `libzkf_ffi.a` | 170 MB | [binary-manifest/v0.4.0/manifest.json](binary-manifest/v0.4.0/manifest.json) |
| `zkf.h` | 56 lines | [binary-manifest/v0.4.0/zkf.h](binary-manifest/v0.4.0/zkf.h) |
| Distribution tarball | 85 MB | Hash only, not distributed here |

Opaque-handle excerpt from the published header:

```c
typedef struct ZkfProgramBuilderHandle { uint8_t _private[0]; } ZkfProgramBuilderHandle;
typedef struct ZkfProgramHandle { uint8_t _private[0]; } ZkfProgramHandle;
typedef struct ZkfCompiledProgramHandle { uint8_t _private[0]; } ZkfCompiledProgramHandle;
typedef struct ZkfProofArtifactHandle { uint8_t _private[0]; } ZkfProofArtifactHandle;
```

## Public SDK (Apache 2.0)

The SDK interface is the only open programming surface documented here. It is intentionally narrow: 29 lines, zero function bodies, public type and function signatures only.

| File | Purpose |
|------|---------|
| [sdk/api-surface.md](sdk/api-surface.md) | Exported types and functions |
| [sdk/example-circuit.rs](sdk/example-circuit.rs) | Safe multiply example using the public SDK only |
| [sdk/constraint-kinds.md](sdk/constraint-kinds.md) | Constraint taxonomy |

Subsystem developers build on ZirOS. They own their app, license, and domain logic. The ZirOS engine remains private.

## Subsystem Architecture

ZirOS generates complete subsystem surfaces from domain specifications. The subsystem developer owns the subsystem. ZirOS owns the operating system beneath it.

| Subsystem Boundary | Ownership |
|--------------------|-----------|
| App logic, domain model, contracts, UI, license | Developer-owned |
| Proving internals, GPU kernels, runtime scheduler, verification layer | ZirOS-owned and private |

This is the operating-system model: you own the application, not the kernel.

## Weekly Attestation

This repository is intended to update weekly with fresh machine-verifiable evidence:

| Published Weekly Surface | Location |
|--------------------------|----------|
| Attestation report | [attestation/latest.json](attestation/latest.json) |
| Dated attestation history | [attestation/](attestation/) |
| Backend conformance | [conformance/latest/](conformance/latest/) |
| Verification ledger summary | [ledger/ledger-summary.json](ledger/ledger-summary.json) |
| Evidence package | [evidence/evidence-package.json](evidence/evidence-package.json) |
| Binary hash manifest | [binary-manifest/v0.4.0/manifest.json](binary-manifest/v0.4.0/manifest.json) |

When the Midnight attestation contracts are live on-chain, the same boundary will extend to public on-chain verification.

## What Is Not In This Repository

This repository does not contain:

- ZirOS source code
- TypeScript, Rust, Metal, Lean, Rocq, Verus, or F* implementation files
- Proof construction source
- GPU kernels or shader libraries
- Runtime scheduler internals
- Swarm implementation source
- Neural Engine model bundles
- Key material, tokens, mnemonics, or wallets
- Build scripts
- Cargo files
- Test source
- Binaries or compiled libraries

ZirOS core remains proprietary. This repository publishes evidence and interfaces only.

## How To Use ZirOS

This repository proves ZirOS works. To actually **use** ZirOS, you need:

| Component | What It Is | How To Get It | License |
|-----------|-----------|---------------|---------|
| **`zkf` binary** | 33 MB CLI — the operator tool. Compile, prove, verify, deploy, wrap, fold, benchmark, audit. 38 top-level commands. | Distributed separately under commercial license. Contact [AnubisQuantumCipher](https://github.com/AnubisQuantumCipher) for access. | ZirOS Core Proprietary |
| **`libzkf_ffi.dylib`** | 12 MB dynamic library — the entire proving engine as a callable C ABI. Opaque handles. 14 extern functions. | Distributed separately under commercial license. Bundled with `zkf.h` (56-line C header). | ZirOS Core Proprietary |
| **`libzkf_ffi.a`** | 170 MB static library — same engine, statically linked. All dependencies included. | Distributed with the dynamic library. | ZirOS Core Proprietary |
| **`zkf-sdk`** | 29-line Rust crate — the public API surface. Types, traits, function signatures. Zero implementation bodies. Build your own circuits with `ProgramBuilder`. | Coming to [crates.io](https://crates.io) as `zkf-sdk`. | Apache 2.0 (open) |
| **`zkf.h`** | 56-line C header — opaque handle API for C/C++/Swift/Python FFI integration. | Included in this repo at [binary-manifest/v0.4.0/zkf.h](binary-manifest/v0.4.0/zkf.h). | Apache 2.0 (open) |

### What You Can Build

With the SDK and binary, you can build **subsystem applications** — complete ZK-powered products that run on top of ZirOS:

- **Cooperative governance systems** (treasury compliance, land trust equity, lending fairness)
- **Aerospace mission assurance** (reentry thermal envelopes, powered descent, orbital dynamics)
- **Private identity credentials** (age verification, KYC compliance without revealing identity)
- **On-chain verification** (128-byte Groth16 proofs on Ethereum for ~$15)
- **Midnight Network DApps** (Compact smart contracts with selective disclosure)
- **Scientific certificates** (thermochemical equilibrium, Navier-Stokes, combustion instability)

Your subsystem code belongs to you. Your license, your contracts, your product. ZirOS's engine stays invisible — you link against the binary, you never see the source.

### The Developer Experience

```rust
// Your code — you own it
use zkf_sdk::{ProgramBuilder, FieldId, Expr, compile_default, prove, verify};

let mut builder = ProgramBuilder::new("my_circuit", FieldId::Bn254);
builder.private_input("secret")?;
builder.public_output("commitment")?;
builder.constrain_equal(Expr::signal("commitment"), Expr::signal("secret"))?;

let program = builder.build()?;
// builder.build() calls into libzkf.dylib — you never see the internals
```

Or via CLI:
```bash
zkf prove --program circuit.json --inputs inputs.json --backend plonky3 --out proof.json
zkf verify --program circuit.json --artifact proof.json --backend plonky3
# verification: OK
```

Full SDK API: [sdk/api-surface.md](sdk/api-surface.md) | Example: [sdk/example-circuit.rs](sdk/example-circuit.rs)

## Application Templates

The public architecture documentation lists 22 built-in ready templates. The in-development `sovereign-economic-defense` template is excluded from the table below because it is not part of the ready built-in set.

| Template | Description |
|----------|-------------|
| poseidon-commitment | BN254 Poseidon commitment from secret and blinding |
| merkle-membership | Poseidon Merkle root and authentication path |
| range-proof | Private value inside a bit range |
| private-vote | Three-candidate private vote commitment |
| sha256-preimage | SHA-256 preimage knowledge |
| private-identity | Private-identity KYC policy compliance |
| gnc-6dof-core | Aerospace 6-DOF guidance and navigation |
| tower-catch-geometry | Tower-catch arm-clearance and catch-box certificate |
| barge-terminal-profile | Barge terminal-profile and deck-motion certificate |
| planetary-terminal-profile | Planetary pad terminal-profile certificate |
| gust-robustness-batch | Monte-Carlo gust robustness batch |
| private-starship-flip-catch | Starship flip-and-catch certification |
| private-powered-descent | Powered-descent guidance showcase |
| private-reentry-thermal-envelope | Reentry mission-assurance certificate |
| private-satellite-conjunction | Two-spacecraft conjunction-avoidance |
| private-multi-satellite-base32 | Multi-satellite conjunction base scenario |
| private-multi-satellite-stress64 | Multi-satellite conjunction stress scenario |
| private-nbody-orbital | Orbital dynamics with committed positions |
| thermochemical-equilibrium | Gas-phase thermochemical equilibrium certificate |
| real-gas-state | Real-gas cubic EOS certificate |
| navier-stokes-structured | Structured-grid Navier-Stokes step |
| combustion-instability-rayleigh | Rayleigh-window combustion-instability certificate |

## Distributed Cluster

The disclosed distributed proving architecture supports multi-node execution over TCP with graph partitioning and swarm-defended coordination.

| Surface | Contract |
|---------|----------|
| Transport | TCP-based remote execution |
| Partitioning | UMPG graph partitioning and subgraph assignment |
| Worker payload | `DistributedExecutionBundle` with version, source digests, optimization objective, output slots, serialized graph nodes, execution context |
| Heartbeat payload | `ThreatIntelPayload` with digest set, activation level, intelligence root, local pressure, network pressure |
| Gossip encryption | ML-KEM-1024 epoch keys |

## Measured Performance

| Metric | Published Figure |
|--------|------------------|
| Groth16 proof size | 128 bytes |
| On-chain verification | ~210K gas |
| Verification time | 20 ms |
| GPU busy-ratio target | 25% |
| M4 Max unified-memory budget, Nova fold | <= 4 GB |
| M4 Max unified-memory budget, Groth16 wrap | <= 8 GB |
| M4 Max unified-memory budget, proving key | <= 2 GB |
| M4 Max unified-memory budget, UMPG buffer pool | <= 4 GB cycling |
| Folding steady-state memory | ~165 MB |
| 200-step reentry proof | ~9 minutes |

## Verification

1. Read the latest attestation: [attestation/latest.json](attestation/latest.json)
2. Check theorem metadata and counts: [ledger/verification-ledger.json](ledger/verification-ledger.json), [ledger/ledger-summary.json](ledger/ledger-summary.json)
3. Review backend conformance: [conformance/latest/](conformance/latest/)
4. Review binary hashes and the opaque C header: [binary-manifest/v0.4.0/](binary-manifest/v0.4.0/)
5. Review the public evidence package: [evidence/evidence-package.json](evidence/evidence-package.json)
6. Review the Midnight deployment manifest: [midnight/sed-deployment-manifest.json](midnight/sed-deployment-manifest.json)

## License

This repository is licensed under Apache 2.0.

The ZirOS core software is not distributed here and remains proprietary.
