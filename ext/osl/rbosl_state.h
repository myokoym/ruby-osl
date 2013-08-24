#ifndef RBOSL_STATE_H
#define RBOSL_STATE_H

#include "ruby.h"

#ifdef __cplusplus
extern "C" {
#endif
void rbosl_state_init(VALUE mOsl);
void rbosl_simpleState_init(VALUE mState);
void rbosl_numEffectState_init(VALUE mState);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* RBOSL_STATE_H */
