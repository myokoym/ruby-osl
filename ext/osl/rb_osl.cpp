#include "ruby.h"
#include "rb_simpleState.hpp"

#ifdef __cplusplus
extern "C" {
#endif
void
Init_osl(void)
{
  Init_simpleState();
}
#ifdef __cplusplus
} /* extern "C" */
#endif
