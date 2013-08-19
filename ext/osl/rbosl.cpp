#include "ruby.h"
#include "rbosl_state.hpp"
#include "rbosl_move.hpp"

#ifdef __cplusplus
extern "C" {
#endif
void
Init_osl(void)
{
  static VALUE mOsl;
  mOsl = rb_define_module("Osl");
  Init_state(mOsl);
  Init_move(mOsl);
}
#ifdef __cplusplus
} /* extern "C" */
#endif