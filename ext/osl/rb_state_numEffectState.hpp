#include "ruby.h"
#include <osl/state/numEffectState.h>
#include <osl/handicap.h>
#include <iostream>

using namespace osl;

void
rb_NumEffectState_free(state::NumEffectState* ptr)
{
  ptr->~NumEffectState();
  ruby_xfree(ptr);
}

static VALUE
rb_NumEffectState_s_new(VALUE self)
{
  state::NumEffectState* ptr = new state::NumEffectState(state::SimpleState(HIRATE));
  // TODO: support GC
  //return Data_Wrap_Struct(self, NULL, rb_NumEffectState_free, ptr);
  return Data_Wrap_Struct(self, NULL, NULL, ptr);
}

static VALUE
rb_NumEffectState_show(VALUE self)
{
  state::NumEffectState* p;
  Data_Get_Struct(self, state::NumEffectState, p);
  std::cout << *p << std::endl;
  return Qnil;
}

#ifdef __cplusplus
extern "C" {
#endif
void
Init_numEffectState(VALUE mState)
{
  VALUE cNumEffectState;
  cNumEffectState = rb_define_class_under(mState, "NumEffectState", rb_cObject);
  rb_define_singleton_method(cNumEffectState, "new", RUBY_METHOD_FUNC(rb_NumEffectState_s_new), 0);
  rb_define_method(cNumEffectState, "show", RUBY_METHOD_FUNC(rb_NumEffectState_show), 0);
}
#ifdef __cplusplus
} /* extern "C" */
#endif
