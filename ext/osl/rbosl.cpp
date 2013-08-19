#include "ruby.h"
#include "rbosl_state.hpp"

#ifdef __cplusplus
extern "C" {
#endif
void
Init_osl(void)
{
  static VALUE mOsl;
  mOsl = rb_define_module("Osl");
  Init_state(mOsl);
}
#ifdef __cplusplus
} /* extern "C" */
#endif
