#include "ruby.h"
#include "rbosl_move.h"
#include <osl/move.h>

VALUE cMove;

using namespace osl;

void
rb_move_free(Move* ptr)
{
  ptr->~Move();
  ruby_xfree(ptr);
}

static VALUE
rb_move_s_new(VALUE self)
{
  Move* ptr = new Move();
  return Data_Wrap_Struct(self, NULL, rb_move_free, ptr);
}

#ifdef __cplusplus
extern "C" {
#endif
void
Init_move(VALUE mOsl)
{
  cMove = rb_define_class_under(mOsl, "Move", rb_cObject);
  rb_define_singleton_method(cMove, "new", RUBY_METHOD_FUNC(rb_move_s_new), 0);
}
#ifdef __cplusplus
} /* extern "C" */
#endif
