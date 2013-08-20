#include "rbosl_state.h"

#ifdef __cplusplus
extern "C" {
#endif
void
rbosl_state_init(VALUE mOsl)
{
  static VALUE mState;
  mState = rb_define_module_under(mOsl, "State");
  rbosl_simpleState_init(mState);
  rbosl_numEffectState_init(mState);
}
#ifdef __cplusplus
} /* extern "C" */
#endif
