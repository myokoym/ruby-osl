#ifndef RBOSL_STATE_H
#define RBOSL_STATE_H

#include "ruby.h"

#ifdef __cplusplus
extern "C" {
#endif
extern void rbosl_state_init(VALUE mOsl);
extern void rbosl_simpleState_init(VALUE mState);
extern void rbosl_numEffectState_init(VALUE mState);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* RBOSL_STATE_H */
