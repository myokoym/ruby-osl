#ifndef RBOSL_PIECE_H
#define RBOSL_PIECE_H

#include "ruby.h"
#include <osl/piece.h>
#include <osl/record/csa.h>

extern  VALUE cPiece;

#ifdef __cplusplus
extern "C" {
#endif
void rbosl_piece_init(VALUE mOsl);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* RBOSL_PIECE_H */
