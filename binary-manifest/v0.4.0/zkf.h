#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct ZkfProgramBuilderHandle {
  uint8_t _private[0];
} ZkfProgramBuilderHandle;

typedef struct ZkfProgramHandle {
  uint8_t _private[0];
} ZkfProgramHandle;

typedef struct ZkfCompiledProgramHandle {
  uint8_t _private[0];
} ZkfCompiledProgramHandle;

typedef struct ZkfProofArtifactHandle {
  uint8_t _private[0];
} ZkfProofArtifactHandle;

const char *zkf_last_error_message(void);

struct ZkfProgramBuilderHandle *zkf_program_builder_new(const char *name, const char *field);

int zkf_program_builder_private_input(struct ZkfProgramBuilderHandle *builder, const char *name);

int zkf_program_builder_public_output(struct ZkfProgramBuilderHandle *builder, const char *name);

int zkf_program_builder_add_assignment_json(struct ZkfProgramBuilderHandle *builder,
                                            const char *target,
                                            const char *expr_json);

int zkf_program_builder_constrain_equal_json(struct ZkfProgramBuilderHandle *builder,
                                             const char *lhs_json,
                                             const char *rhs_json);

struct ZkfProgramHandle *zkf_program_builder_build(struct ZkfProgramBuilderHandle *builder);

struct ZkfCompiledProgramHandle *zkf_compile(struct ZkfProgramHandle *program, const char *backend);

struct ZkfProofArtifactHandle *zkf_prove(struct ZkfProgramHandle *program,
                                         const char *inputs_json,
                                         const char *backend);

bool zkf_verify(struct ZkfProgramHandle *program,
                struct ZkfProofArtifactHandle *artifact,
                const char *backend);

void zkf_free_program_builder(struct ZkfProgramBuilderHandle *builder);

void zkf_free_program(struct ZkfProgramHandle *program);

void zkf_free_compiled_program(struct ZkfCompiledProgramHandle *compiled);

void zkf_free_proof_artifact(struct ZkfProofArtifactHandle *artifact);
