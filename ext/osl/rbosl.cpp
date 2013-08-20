#include "ruby.h"
#include "rbosl_state.h"
#include "rbosl_move.h"

#ifdef __cplusplus
extern "C" {
#endif
void
Init_osl(void)
{
  static VALUE mOsl;
  mOsl = rb_define_module("Osl");
  rbosl_state_init(mOsl);
  rbosl_move_init(mOsl);
}
#ifdef __cplusplus
} /* extern "C" */
#endif
