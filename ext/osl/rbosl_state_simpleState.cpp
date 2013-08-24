#include "rbosl_state.h"
#include "rbosl_piece.h"

using namespace osl;

VALUE cSimpleState;

void
rbosl_simpleState_free(state::SimpleState* ptr)
{
  ptr->~SimpleState();
  ruby_xfree(ptr);
}

static VALUE
rbosl_simpleState_s_new(VALUE self)
{
  state::SimpleState* ptr = new state::SimpleState(HIRATE);
  return Data_Wrap_Struct(self, NULL, rbosl_simpleState_free, ptr);
}

static VALUE
rbosl_simpleState_show(VALUE self)
{
  state::SimpleState* ptr;
  Data_Get_Struct(self, state::SimpleState, ptr);
  std::cout << *ptr << std::endl;
  return Qnil;
}

static VALUE
rbosl_simpleState_pieceAt(VALUE self, VALUE rb_square)
{
  state::SimpleState* ptr;
  Data_Get_Struct(self, state::SimpleState, ptr);

  Square* c_square;
  if (TYPE(rb_square) == T_STRING) {
    Square tmp_square = record::csa::strToPos(StringValuePtr(rb_square));
    c_square = &tmp_square;
  } else {
    Data_Get_Struct(rb_square, Square, c_square);
  }

  Piece c_piece = ptr->pieceAt(*c_square);
  VALUE rb_piece = Data_Wrap_Struct(cPiece, NULL, NULL, &c_piece);

  return rb_piece;
}

#ifdef __cplusplus
extern "C" {
#endif
void
rbosl_simpleState_init(VALUE mState)
{
  cSimpleState = rb_define_class_under(mState, "SimpleState", rb_cObject);
  rb_define_singleton_method(cSimpleState, "new", RUBY_METHOD_FUNC(rbosl_simpleState_s_new), 0);
  rb_define_method(cSimpleState, "show", RUBY_METHOD_FUNC(rbosl_simpleState_show), 0);
  rb_define_method(cSimpleState, "pieceAt", RUBY_METHOD_FUNC(rbosl_simpleState_pieceAt), 1);
  rb_define_alias(cSimpleState, "at", "pieceAt");
}
#ifdef __cplusplus
} /* extern "C" */
#endif
