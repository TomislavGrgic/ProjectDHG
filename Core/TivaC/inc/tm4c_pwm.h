#ifndef _TM4C_PWM_H__
#define _TM4C_PWM_H__

#include "TM4C123.h"
#include <stdint.h>

#define SYSCTL_RCGCPWM_R0   (1u<<0)
#define SYSCTL_RCGCGPIO_R1  (1u<<1)
#define SYSCTL_RCGCGPIO_R4  (1u<<4)
#define SYSCTL_RCC_PWMDIV_0 (0u<<17)
#define SYSCTL_RCC_PWMDIV_7 (7u<<17)

#define GPIO_DIR_4          (1u<<4)
#define GPIO_DEN_4          (1u<<4)
#define GPIO_AFSEL_4        (1u<<4)
#define GPIO_PCTL_MX4_15    (15u<<16)
#define GPIO_PCTL_MX4_4     (4u<<16)
#define GPIO_DIR_6          (1u<<6)
#define GPIO_DEN_6          (1u<<6)
#define GPIO_AFSEL_6        (1u<<6)
#define GPIO_PCTL_MX6_4     (4u<<24)
#define GPIO_PCTL_MX6_15    (15u<<24)

#define PWM_GENA_ACTLOAD_2  (2u<<2)
#define PWM_GENA_ACTLOAD_3  (3u<<2)
#define PWM_GENA_ACTZERO_3  (3u<<0)
#define PWM_GENA_ACTCMPD_2  (2u<<6)
#define PWM_GENA_ACTCMPD_3  (3u<<6)
#define PWM_CTL_GLOBALSYNC0 (1u<<0)
#define PWM_ENABLE_PWM0EN   (1u<<0)
#define PWM_ENABLE_PWM2EN   (1u<<2)
#define PWM_CTL_GLOBALSYNC1 (1u<<1)

#ifdef __cplusplus
extern "C" {
#endif

/*
* This part of the code is for PWM0 channel 0. Other parts are for the same PWM0 just other channels.
* Each channel has its own init and functions. I wanted to do it this way to test the upper abstraction layer.
*/
void tm4c_pwm_init(void);
void tm4c_pwm_set_period(uint16_t period);
void tm4c_pwm_set_duty(uint16_t duty);

/*
* This part of the code is for PWM0 channel 2. Channel 1 is invert of channel 0.
*/
void tm4c_pwm_init_ch2(void);
void tm4c_pwm_set_period_ch2(uint16_t period);
void tm4c_pwm_set_duty_ch2(uint16_t duty);

/*
* This part of the code is for PWM0 channel 4. Channel 3 is invert of channel 2.
*/
void tm4c_pwm_init_ch4(void);
void tm4c_pwm_set_period_ch4(uint16_t period);
void tm4c_pwm_set_duty_ch4(uint16_t duty);


#ifdef __cplusplus
}
#endif

#endif /*_TM4C_PWM_H__*/