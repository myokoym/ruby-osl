#include "ruby.h"
#include <osl/state/numEffectState.h>
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
rb_SimpleState_allocate(VALUE self)
{
  void* p = ruby_xmalloc(sizeof(state::SimpleState));
  return Data_Wrap_Struct(self, NULL, rb_SimpleState_free, p);
}

static VALUE
rb_SimpleState_initialize(VALUE self)
{
  state::SimpleState* p;
  Data_Get_Struct(self, state::SimpleState, p);
  new (p) state::SimpleState(HIRATE);
  return Qnil;
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
  VALUE c;
  c = rb_define_class_under(mState, "SimpleState", rb_cObject);
  rb_define_alloc_func(c, rb_SimpleState_allocate);
  rb_define_private_method(c, "initialize", (VALUE(*)(...))rb_SimpleState_initialize, 0);
  rb_define_method(c, "show", (VALUE(*)(...))rb_SimpleState_show, 0);
}
#ifdef __cplusplus
} /* extern "C" */
#endif