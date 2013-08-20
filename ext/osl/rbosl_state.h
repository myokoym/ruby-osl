#ifndef RBOSL_STATE_H
#define RBOSL_STATE_H

#include "ruby.h"

#ifdef __cplusplus
extern "C" {
#endif
extern void Init_state(VALUE mOsl);
extern void Init_simpleState(VALUE mState);
extern void Init_numEffectState(VALUE mState);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* RBOSL_STATE_H */
