#include "ruby.h"
#include "rbosl_state.h"
#include <osl/state/simpleState.h>
#include <osl/handicap.h>
#include <iostream>

using namespace osl;

void
rb_simpleState_free(state::SimpleState* ptr)
{
  ptr->~SimpleState();
  ruby_xfree(ptr);
}

static VALUE
rb_simpleState_s_new(VALUE self)
{
  state::SimpleState* ptr = new state::SimpleState(HIRATE);
  return Data_Wrap_Struct(self, NULL, rb_simpleState_free, ptr);
}

static VALUE
rb_simpleState_show(VALUE self)
{
  state::SimpleState* ptr;
  Data_Get_Struct(self, state::SimpleState, ptr);
  std::cout << *ptr << std::endl;
  return Qnil;
}

#ifdef __cplusplus
extern "C" {
#endif
void
Init_simpleState(VALUE mState)
{
  VALUE cSimpleState;
  cSimpleState = rb_define_class_under(mState, "SimpleState", rb_cObject);
  rb_define_singleton_method(cSimpleState, "new", RUBY_METHOD_FUNC(rb_simpleState_s_new), 0);
  rb_define_method(cSimpleState, "show", RUBY_METHOD_FUNC(rb_simpleState_show), 0);
}
#ifdef __cplusplus
} /* extern "C" */
#endif