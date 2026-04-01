# Midnight Attestation Contracts

ZirOS publishes three Compact attestation contracts that prove compliance claims without disclosing source code. The contracts are compiled and locally proven. Public deployment is pending Midnight preprod chain stabilization.

## Compiler Metadata

| Property | Value |
|----------|-------|
| Compact compiler version | `0.30.0` |
| Compact language version | `0.22.0` |
| Compact runtime version | `0.15.0` |
| Deployment status | Compiled and locally proven; public chain deployment pending |

## Contract Overview

| Contract | Circuit | Public Ledger Fields | Public Claim |
|----------|---------|----------------------|-------------|
| `ziros_attestation_backend` | `prove_backend_correctness` | `attestation_commitment`, `verification_count`, `compliance_bit` | Published backend conformance set passed |
| `ziros_attestation_formal` | `prove_formal_coverage` | `attestation_commitment`, `theorem_count`, `compliance_bit` | Verification ledger has the expected mechanized coverage and zero pending entries |
| `ziros_attestation_audit` | `prove_audit_clean` | `attestation_commitment`, `verification_count`, `theorem_count`, `compliance_bit` | Fail-closed audit is clean and upstream commitments agree |

## Witness Surface

### `ziros_attestation_backend`

| Witness | Type |
|---------|------|
| `attestationRoot0` | `Uint(64-bit max)` |
| `attestationRoot1` | `Uint(64-bit max)` |
| `attestationRoot2` | `Uint(64-bit max)` |
| `attestationRoot3` | `Uint(64-bit max)` |
| `plonky3Present` | `Uint(8-bit max)` |
| `plonky3TestsRun` | `Uint(32-bit max)` |
| `plonky3TestsPassed` | `Uint(32-bit max)` |
| `halo2Present` | `Uint(8-bit max)` |
| `halo2TestsRun` | `Uint(32-bit max)` |
| `halo2TestsPassed` | `Uint(32-bit max)` |
| `novaPresent` | `Uint(8-bit max)` |
| `novaTestsRun` | `Uint(32-bit max)` |
| `novaTestsPassed` | `Uint(32-bit max)` |
| `hyperNovaPresent` | `Uint(8-bit max)` |
| `hyperNovaTestsRun` | `Uint(32-bit max)` |
| `hyperNovaTestsPassed` | `Uint(32-bit max)` |

### `ziros_attestation_formal`

| Witness | Type |
|---------|------|
| `attestationRoot0` | `Uint(64-bit max)` |
| `attestationRoot1` | `Uint(64-bit max)` |
| `attestationRoot2` | `Uint(64-bit max)` |
| `attestationRoot3` | `Uint(64-bit max)` |
| `ledgerTotalEntries` | `Uint(32-bit max)` |
| `ledgerMechanizedEntries` | `Uint(32-bit max)` |
| `ledgerPendingEntries` | `Uint(32-bit max)` |

### `ziros_attestation_audit`

| Witness | Type |
|---------|------|
| `attestationRoot0` | `Uint(64-bit max)` |
| `attestationRoot1` | `Uint(64-bit max)` |
| `attestationRoot2` | `Uint(64-bit max)` |
| `attestationRoot3` | `Uint(64-bit max)` |
| `verificationCount` | `Uint(64-bit max)` |
| `theoremCount` | `Uint(64-bit max)` |
| `backendCompliance` | `Uint(8-bit max)` |
| `formalCompliance` | `Uint(8-bit max)` |
| `upstreamCommitmentsAgree` | `Uint(8-bit max)` |
| `auditUnderconstrainedSignals` | `Uint(32-bit max)` |
| `auditTotalChecks` | `Uint(32-bit max)` |
| `auditFailedChecks` | `Uint(32-bit max)` |

## Selective Disclosure Boundary

| Data Class | Public | Notes |
|------------|--------|-------|
| Compliance bit | Yes | Pass/fail surface |
| Attestation commitment | Yes | Commitment binds the private witness |
| Verification count | Yes | Aggregate count only |
| Theorem count | Yes | Aggregate count only |
| Individual backend results | No | Remain in private evidence |
| Full theorem ledger witness | No | Only theorem metadata is published separately |
| Audit signal names | No | Private fail-closed audit detail stays outside the public contract |

## Deployment Status

The attestation circuits are compiled and locally proven. Public Midnight deployment remains pending chain stabilization after a preprod runtime change introduced signed extensions not yet supported by the pinned SDK surface used for deployment. The public evidence in this repository is published independently of that on-chain rollout.
