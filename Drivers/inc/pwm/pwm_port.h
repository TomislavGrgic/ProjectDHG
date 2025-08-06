#ifndef _PWM_DRIVER_PORT_H__
#define _PWM_DRIVER_PORT_H__

#include "tm4c_pwm.h"
#include "pwm.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void pwm_port_tm4c_init(void *self);
void pwm_port_tm4c_set_period(void *self, uint32_t value);
void pwm_port_tm4c_set_duty(void *self, uint32_t value);

void pwm_port_tm4c_ch2_init(void *self);
void pwm_port_tm4c_ch2_set_period(void *self, uint32_t value);
void pwm_port_tm4c_ch2_set_duty(void *self, uint32_t value);

void pwm_port_tm4c_ch4_init(void *self);
void pwm_port_tm4c_ch4_set_period(void *self, uint32_t value);
void pwm_port_tm4c_ch4_set_duty(void *self, uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /*_PWM_DRIVER_PORT_H__*/