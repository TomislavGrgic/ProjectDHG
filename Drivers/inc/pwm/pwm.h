#ifndef _PWM_DRIVER_H__
#define _PWM_DRIVER_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


enum {
    PWM_OK,
    PWM_NULL_PTR
};


typedef struct{
    void* self;
    void (*init)(void *self);
    void (*set_period)(void *self, uint32_t value);
    void (*set_duty)(void *self, uint32_t value);
} PWM_S;

extern PWM_S *PWM;
extern PWM_S *PWM2;
extern PWM_S *PWM4;

void pwm_init(PWM_S *object);
void pwm_set_period(PWM_S *object, uint16_t period);
void pwm_set_duty(PWM_S *object, uint16_t duty);

#ifdef __cplusplus
}
#endif

#endif /*_PWM_DRIVER_H__*/