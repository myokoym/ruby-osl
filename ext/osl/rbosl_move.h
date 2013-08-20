#ifndef RBOSL_MOVE_H
#define RBOSL_MOVE_H

#include "ruby.h"
#include <osl/move.h>

extern  VALUE cMove;

using namespace osl;

void rb_move_free(Move* ptr);
static VALUE rb_move_s_new(VALUE self);

void Init_move(void);

#endif /* RBOSL_MOVE_H */
