#ifndef _ARM_CORTEX_SYSTICK_H__
#define _ARM_CORTEX_SYSTICK_H__

#include "TM4C123.h"

#ifdef __cplusplus
extern "C" {
#endif

void systick_init(void);
int64_t systick_get_ticks(void);
void systick_sleep_ms(int64_t delay);

#ifdef __cplusplus
}
#endif

#endif /*_ARM_CORTEX_SYSTICK_H__*/