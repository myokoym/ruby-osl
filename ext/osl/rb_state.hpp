#include "ruby.h"
#include "rb_state_simpleState.hpp"

#ifdef __cplusplus
extern "C" {
#endif
void
Init_state(VALUE mOsl)
{
  static VALUE mState;
  mState = rb_define_module_under(mOsl, "State");
  Init_simpleState(mState);
}
#ifdef __cplusplus
} /* extern "C" */
#endif
