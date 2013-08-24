#ifndef RBOSL_MOVE_H
#define RBOSL_MOVE_H

#include "ruby.h"
#include <osl/move.h>
#include <osl/record/csa.h>

extern  VALUE cMove;

#ifdef __cplusplus
extern "C" {
#endif
void rbosl_move_init(VALUE mOsl);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* RBOSL_MOVE_H */
