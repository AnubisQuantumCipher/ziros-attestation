# zkf-sdk Public API Surface

This document records the public `zkf-sdk` export surface for ZirOS v0.4.0. It contains names, type aliases, enums, and function signatures only. No function bodies are published here.

## Exported Types

| Export | Kind | Purpose |
|--------|------|---------|
| `ProgramBuilder` | Type re-export | Circuit construction surface |
| `Program` | Type re-export | Built circuit representation |
| `Signal` | Type re-export | Named circuit signal |
| `Constraint` | Type re-export | Circuit constraint value |
| `Expr` | Type re-export | Expression tree for constraints |
| `WitnessInputs` | Type re-export | Input map for witness generation |
| `Witness` | Type re-export | Generated witness |
| `FieldId` | Type re-export | Field selector |
| `FieldElement` | Type re-export | Field element value |
| `BackendKind` | Type re-export | Backend selector |
| `CompiledProgram` | Type re-export | Backend-compiled program |
| `ProofArtifact` | Type re-export | Generated proof artifact |
| `BlackBoxOp` | Type re-export | SDK-visible black-box operation selector |
| `SignalType` | Type re-export | Signal kind classifier |
| `ZkfError` | Type re-export | Error type |
| `ZkfResult<T>` | Type re-export | Result alias |
| `CooperativeTreasuryAssuranceRequestV1` | Type re-export | Sovereign Economic Defense request surface |
| `CommunityLandTrustGovernanceRequestV1` | Type re-export | Sovereign Economic Defense request surface |
| `AntiExtractionShieldRequestV1` | Type re-export | Sovereign Economic Defense request surface |
| `WealthTrajectoryAssuranceRequestV1` | Type re-export | Sovereign Economic Defense request surface |
| `RecirculationSovereigntyScoreRequestV1` | Type re-export | Sovereign Economic Defense request surface |
| `SovereignEconomicDefenseRunManifestV1` | Type re-export | Sovereign Economic Defense run manifest |

## Exact Public Alias and Enum

```rust
pub type SignalVisibility = zkf_core::Visibility;

pub enum ConstraintKind {
    Equal,
    Boolean,
    Range,
    BlackBox,
    Lookup,
}
```

## Exact Exported Function Signatures

```rust
pub fn compile(
    program: &Program,
    backend: &str,
    seed: Option<[u8; 32]>,
) -> ZkfResult<CompiledProgram>;

pub fn compile_default(
    program: &Program,
    seed: Option<[u8; 32]>,
) -> ZkfResult<CompiledProgram>;

pub fn witness_from_inputs(
    program: &Program,
    inputs: &WitnessInputs,
    solver: Option<&str>,
) -> ZkfResult<Witness>;

pub fn prove(
    compiled: &CompiledProgram,
    witness: &Witness,
) -> ZkfResult<ProofArtifact>;

pub fn verify(
    compiled: &CompiledProgram,
    artifact: &ProofArtifact,
) -> ZkfResult<bool>;

pub fn build_cooperative_treasury_assurance_program(
    request: &CooperativeTreasuryAssuranceRequestV1,
) -> ZkfResult<Program>;

pub fn cooperative_treasury_assurance_witness_from_request(
    request: &CooperativeTreasuryAssuranceRequestV1,
) -> ZkfResult<Witness>;

pub fn build_community_land_trust_governance_program(
    request: &CommunityLandTrustGovernanceRequestV1,
) -> ZkfResult<Program>;

pub fn community_land_trust_governance_witness_from_request(
    request: &CommunityLandTrustGovernanceRequestV1,
) -> ZkfResult<Witness>;

pub fn build_anti_extraction_shield_program(
    request: &AntiExtractionShieldRequestV1,
) -> ZkfResult<Program>;

pub fn anti_extraction_shield_witness_from_request(
    request: &AntiExtractionShieldRequestV1,
) -> ZkfResult<Witness>;

pub fn build_wealth_trajectory_assurance_program(
    request: &WealthTrajectoryAssuranceRequestV1,
) -> ZkfResult<Program>;

pub fn wealth_trajectory_assurance_witness_from_request(
    request: &WealthTrajectoryAssuranceRequestV1,
) -> ZkfResult<Witness>;

pub fn build_recirculation_sovereignty_score_program(
    request: &RecirculationSovereigntyScoreRequestV1,
) -> ZkfResult<Program>;

pub fn recirculation_sovereignty_score_witness_from_request(
    request: &RecirculationSovereigntyScoreRequestV1,
) -> ZkfResult<Witness>;
```

## Export Policy

The public SDK is the only developer-facing programming surface disclosed here. It is intentionally narrow:

- circuit authoring happens through `ProgramBuilder`
- proving happens through `compile`, `prove`, and `verify`
- subsystem-specific request types stay at the interface layer
- no backend implementation, scheduler logic, GPU kernels, or proof internals are published
