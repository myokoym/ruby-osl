#include "ruby.h"
#include "rbosl_move.h"
#include <osl/state/numEffectState.h>
#include <osl/handicap.h>
#include <osl/container/moveVector.h>
#include <osl/move_generator/legalMoves.h>
#include <iostream>

using namespace osl;

void
rb_numEffectState_free(state::NumEffectState* ptr)
{
  ptr->~NumEffectState();
  ruby_xfree(ptr);
}

static VALUE
rb_numEffectState_s_new(VALUE self)
{
  state::NumEffectState* ptr = new state::NumEffectState(state::SimpleState(HIRATE));
  // TODO: support GC
  //return Data_Wrap_Struct(self, NULL, rb_numEffectState_free, ptr);
  return Data_Wrap_Struct(self, NULL, NULL, ptr);
}

static VALUE
rb_numEffectState_show(VALUE self)
{
  state::NumEffectState* p;
  Data_Get_Struct(self, state::NumEffectState, p);
  std::cout << *p << std::endl;
  return Qnil;
}

static VALUE
rb_numEffectState_generate(VALUE self)
{
  state::NumEffectState* p;
  Data_Get_Struct(self, state::NumEffectState, p);
  MoveVector moves;
  LegalMoves::generate(*p, moves);
  VALUE moves_ary = rb_ary_new();
  for (int i = 0; i < (int)moves.size(); i++) {
    // TODO: ruby: munmap_chunk(): invalid pointer
    //VALUE move = Data_Wrap_Struct(cMove, NULL, rb_move_free, &moves[i]);
    VALUE move = Data_Wrap_Struct(cMove, NULL, NULL, &moves[i]);
    rb_ary_push(moves_ary, move);
  }
  return moves_ary;
}

#ifdef __cplusplus
extern "C" {
#endif
void
Init_numEffectState(VALUE mState)
{
  VALUE cNumEffectState;
  cNumEffectState = rb_define_class_under(mState, "NumEffectState", rb_cObject);
  rb_define_singleton_method(cNumEffectState, "new", RUBY_METHOD_FUNC(rb_numEffectState_s_new), 0);
  rb_define_method(cNumEffectState, "show", RUBY_METHOD_FUNC(rb_numEffectState_show), 0);
  rb_define_method(cNumEffectState, "generate", RUBY_METHOD_FUNC(rb_numEffectState_generate), 0);
}
#ifdef __cplusplus
} /* extern "C" */
#endif
