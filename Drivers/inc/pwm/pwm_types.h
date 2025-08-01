#ifndef _PWM_DRIVER_TYPES_PORT_H__
#define _PWM_DRIVER_TYPES_PORT_H__

#include "pwm.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint32_t period;
    uint32_t duty;
} PWM_Private_S;


typedef struct {
    PWM_S _public;
    PWM_Private_S _private;
} PWM_Object_S;

#ifdef __cplusplus
}
#endif

#endif /*_PWM_DRIVER_TYPES_PORT_H__*/