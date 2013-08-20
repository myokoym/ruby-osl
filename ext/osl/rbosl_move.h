#ifndef RBOSL_MOVE_H
#define RBOSL_MOVE_H

#include "ruby.h"
#include <osl/move.h>

extern  VALUE cMove;

#ifdef __cplusplus
extern "C" {
#endif
extern void Init_move(VALUE mOsl);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* RBOSL_MOVE_H */
