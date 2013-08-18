#include "ruby.h"
#include "rb_simpleState.hpp"

#ifdef __cplusplus
extern "C" {
#endif
void
Init_osl(void)
{
  static VALUE mOsl;
  mOsl = rb_define_module("Osl");
  Init_simpleState(mOsl);
}
#ifdef __cplusplus
} /* extern "C" */
#endif
