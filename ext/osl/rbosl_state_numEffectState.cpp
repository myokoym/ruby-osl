#include "ruby.h"
#include "rbosl_state.h"
#include "rbosl_move.h"
#include <osl/state/numEffectState.h>
#include <osl/handicap.h>
#include <osl/container/moveVector.h>
#include <osl/move_generator/legalMoves.h>
#include <osl/record/csa.h>
#include <iostream>

using namespace osl;

void
rbosl_numEffectState_free(state::NumEffectState* ptr)
{
  ptr->~NumEffectState();
  ruby_xfree(ptr);
}

static VALUE
rbosl_numEffectState_s_new(VALUE self)
{
  state::NumEffectState* ptr = new state::NumEffectState(state::SimpleState(HIRATE));
  // TODO: support GC
  //return Data_Wrap_Struct(self, NULL, rbosl_numEffectState_free, ptr);
  return Data_Wrap_Struct(self, NULL, NULL, ptr);
}

static VALUE
rbosl_numEffectState_generate(VALUE self)
{
  state::NumEffectState* p;
  Data_Get_Struct(self, state::NumEffectState, p);
  MoveVector moves;
  LegalMoves::generate(*p, moves);
  VALUE moves_ary = rb_ary_new();
  for (int i = 0; i < (int)moves.size(); i++) {
    // TODO: ruby: munmap_chunk(): invalid pointer
    //VALUE move = Data_Wrap_Struct(cMove, NULL, rbosl_move_free, &moves[i]);
    VALUE move = Data_Wrap_Struct(cMove, NULL, NULL, &moves[i]);
    rb_ary_push(moves_ary, move);
  }
  return moves_ary;
}

static VALUE
rbosl_numEffectState_makeMove(VALUE self, VALUE rb_move)
{
  state::NumEffectState* p;
  Data_Get_Struct(self, state::NumEffectState, p);

  Move* c_move;
  if (TYPE(rb_move) == T_STRING) {
    Move osl_move = record::csa::strToMove(StringValuePtr(rb_move), *p);
    c_move = &osl_move;
  } else {
    Data_Get_Struct(rb_move, Move, c_move);
  }

  p->makeMove(*c_move);

  return Qnil;
}

static VALUE
rbosl_numEffectState_isValidMove(VALUE self, VALUE rb_move)
{
  state::NumEffectState* p;
  Data_Get_Struct(self, state::NumEffectState, p);

  Move* c_move;
  if (TYPE(rb_move) == T_STRING) {
    // TODO: Rescue invalid piece. e.g) +7776XX
    // TODO: Support except for CSA format.
    VALUE format_checked = rb_funcall(rb_move,
                                      rb_intern("match"),
                                      1,
                                      rb_str_new2("[+-][0-9]{4}[A-Z]{2}"));
    if (format_checked == Qnil) {
      return Qnil;
    }
    Move osl_move = record::csa::strToMove(StringValuePtr(rb_move), *p);
    c_move = &osl_move;
  } else {
    Data_Get_Struct(rb_move, Move, c_move);
  }

  if (p->isValidMove(*c_move)) {
    return Qtrue;
  } else {
    return Qfalse;
  }
}

static VALUE
rbosl_numEffectState_inCheck(VALUE self)
{
  state::NumEffectState* p;
  Data_Get_Struct(self, state::NumEffectState, p);

  if (p->inCheck(alt(p->turn()))) {
    return Qtrue;
  } else {
    return Qfalse;
  }
}

#ifdef __cplusplus
extern "C" {
#endif
void
rbosl_numEffectState_init(VALUE mState)
{
  VALUE cNumEffectState;
  cNumEffectState = rb_define_class_under(mState, "NumEffectState", cSimpleState);
  rb_define_singleton_method(cNumEffectState, "new", RUBY_METHOD_FUNC(rbosl_numEffectState_s_new), 0);
  rb_define_method(cNumEffectState, "generate", RUBY_METHOD_FUNC(rbosl_numEffectState_generate), 0);
  rb_define_method(cNumEffectState, "makeMove", RUBY_METHOD_FUNC(rbosl_numEffectState_makeMove), 1);
  rb_define_alias(cNumEffectState,  "move", "makeMove");
  rb_define_method(cNumEffectState, "inCheck", RUBY_METHOD_FUNC(rbosl_numEffectState_inCheck), 0);
  rb_define_alias(cNumEffectState,  "in_check?", "inCheck");
  rb_define_method(cNumEffectState, "isValidMove", RUBY_METHOD_FUNC(rbosl_numEffectState_isValidMove), 1);
  rb_define_alias(cNumEffectState,  "valid?", "isValidMove");
}
#ifdef __cplusplus
} /* extern "C" */
#endif
