#include "rbosl_piece.h"

VALUE cPiece;

using namespace osl;

void
rbosl_piece_free(Piece* ptr)
{
  ptr->~Piece();
  ruby_xfree(ptr);
}

static VALUE
rbosl_piece_s_new(VALUE self)
{
  Piece* ptr = new Piece();
  return Data_Wrap_Struct(self, NULL, rbosl_piece_free, ptr);
}

static VALUE
rbosl_piece_to_csa(VALUE self)
{
  Piece* ptr;
  Data_Get_Struct(self, Piece, ptr);
  return rb_str_new2(record::csa::show(*ptr).c_str());
}

#ifdef __cplusplus
extern "C" {
#endif
void
rbosl_piece_init(VALUE mOsl)
{
  cPiece = rb_define_class_under(mOsl, "Piece", rb_cObject);
  rb_define_singleton_method(cPiece, "new", RUBY_METHOD_FUNC(rbosl_piece_s_new), 0);
  rb_define_method(cPiece, "to_csa", RUBY_METHOD_FUNC(rbosl_piece_to_csa), 0);
}
#ifdef __cplusplus
} /* extern "C" */
#endif
