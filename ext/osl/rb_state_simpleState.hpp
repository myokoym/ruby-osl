#include "ruby.h"
#include <osl/state/simpleState.h>
#include <osl/handicap.h>
#include <iostream>

using namespace osl;

void
rb_SimpleState_free(state::SimpleState* ptr)
{
  ptr->~SimpleState();
  ruby_xfree(ptr);
}

static VALUE
rb_SimpleState_s_new(VALUE self)
{
  state::SimpleState* p = new state::SimpleState(HIRATE);
  return Data_Wrap_Struct(self, NULL, rb_SimpleState_free, p);
}

static VALUE
rb_SimpleState_show(VALUE self)
{
  state::SimpleState* p;
  Data_Get_Struct(self, state::SimpleState, p);
  std::cout << *p << std::endl;
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
  rb_define_singleton_method(cSimpleState, "new", RUBY_METHOD_FUNC(rb_SimpleState_s_new), 0);
  rb_define_method(cSimpleState, "show", RUBY_METHOD_FUNC(rb_SimpleState_show), 0);
}
#ifdef __cplusplus
} /* extern "C" */
#endif
