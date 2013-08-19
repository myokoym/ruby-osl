#include "ruby.h"
#include "rbosl_state_simpleState.hpp"
#include "rbosl_state_numEffectState.hpp"

#ifdef __cplusplus
extern "C" {
#endif
void
Init_state(VALUE mOsl)
{
  static VALUE mState;
  mState = rb_define_module_under(mOsl, "State");
  Init_simpleState(mState);
  Init_numEffectState(mState);
}
#ifdef __cplusplus
} /* extern "C" */
#endif
