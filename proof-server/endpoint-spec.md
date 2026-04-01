# Midnight Proof Server Endpoint Spec

This document describes the public wire contract of the ZirOS Midnight-compatible proof server.

## Service Contract

| Property | Value |
|----------|-------|
| Default engine | `umpg` |
| Compatibility version | `8.0.3` |
| Root health alias | `GET /` behaves like `GET /health` |
| Backpressure | `GET /ready` returns HTTP 503 when saturated |
| Telemetry lanes | `check`, `prove`, `prove-tx` |
| Compatibility guarantee | `/check` is byte-equivalent across UMPG and upstream engine modes |

## Readiness and Health

### `GET /health`

Returns JSON:

```json
{
  "status": "ok",
  "timestamp": "2026-04-01T00:00:00Z"
}
```

### `GET /ready`

Returns JSON with HTTP `200 OK` when capacity is available and HTTP `503 Service Unavailable` when the queue is saturated.

```json
{
  "status": "ok",
  "jobsProcessing": 0,
  "jobsPending": 0,
  "jobCapacity": 2,
  "timestamp": "2026-04-01T00:00:00Z"
}
```

The same schema is used for the busy case, with `"status": "busy"` and HTTP `503`.

## Proving Endpoints

The proving endpoints use Midnight's tagged serialization format on the wire. They do not use JSON request bodies.

| Endpoint | Method | Request Body | Response Body |
|----------|--------|--------------|---------------|
| `/prove` | `POST` | Tagged-serialized tuple `(ProofPreimageVersioned, Option<ProvingKeyMaterial>, Option<Fr>)` | Tagged-serialized `ProofVersioned` |
| `/check` | `POST` | Tagged-serialized tuple `(ProofPreimageVersioned, Option<WrappedIr>)` | Tagged-serialized `Vec<Option<u64>>` |
| `/prove-tx` | `POST` | Tagged-serialized tuple `(Transaction<Signature, ProofPreimageMarker, PedersenRandomness, InMemoryDB>, HashMap<String, ProvingKeyMaterial>)` | Tagged-serialized transaction proof payload |

### `POST /prove`

- Generates a Midnight-compatible proof.
- Uses the supplied proving key material when present.
- Resolves key material from the configured provider when it is omitted.
- Accepts an optional binding input in the request tuple.

### `POST /check`

- Validates a proof preimage against the supplied or resolved IR.
- Returns the same byte-level result shape as the upstream Midnight engine.

### `POST /prove-tx`

- Proves an entire Midnight transaction using the built-in cost model.
- Expects both the transaction preimage and the proving-key map in the request body.

## Auxiliary Endpoints

| Endpoint | Method | Request | Response | Notes |
|----------|--------|---------|----------|-------|
| `/k` | `POST` | Tagged-serialized `zkir_v2::IrSource` bytes | Plain-text integer | Returns the computed `k` parameter for the IR |
| `/fetch-params/{k}` | `GET` | Path parameter `k` (`0..=25`) | Plain-text `success` | Ensures public parameters for degree `k` are available |
| `/version` | `GET` | None | Plain-text version string | Returns `8.0.3` in the current disclosed build |
| `/proof-versions` | `GET` | None | Plain-text list | Lists supported proof-version identifiers |

## Engine Modes

| Flag | Meaning |
|------|---------|
| `--engine umpg` | ZirOS execution path with Metal GPU scheduling, backpressure, timeout accounting, and per-job telemetry |
| `--engine upstream` | Midnight worker-pool compatibility path for debugging and comparison |

## Operational Notes

- `GET /ready` is the correct load-balancer probe for admission control.
- `GET /health` is the correct liveness probe.
- `POST /check` is the public equivalence surface used to compare UMPG and upstream behavior.
- Public parameter fetching is optional at startup and can be disabled at serve time.
