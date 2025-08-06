#include "pwm_port.h"
#include "pwm_types.h"

static int64_t pwm_port_template_init(PWM_Object_S *object, int64_t (*port_init)(void *f_args), void *args);
static int64_t pwm_port_tm4c_init_cb(void *f_args);
static int64_t pwm_port_tm4c_ch2_init_cb(void *f_args); 
static int64_t pwm_port_tm4c_ch4_init_cb(void *f_args);


static int64_t pwm_port_template_init(PWM_Object_S *object, int64_t (*function_cb)(void *f_args), void *args) {
    int64_t ret = PWM_OK;
    
    if(object->_public.set_duty == NULL) {
        return PWM_NULL_PTR;
    }

    if(object->_public.set_period == NULL) {
        return PWM_NULL_PTR;
    }
    

    if(function_cb != NULL) {
        ret = function_cb(args);
    }

    if( ret != PWM_OK) {
        return ret;
    }

    object->_private.duty = 0;
    object->_public.set_duty(object->_public.self, object->_private.duty);
    object->_private.period = 0;
    object->_public.set_period(object->_public.self, object->_private.period);
    return ret;
}

/**
 * TM4C Channel 0
 */
static int64_t pwm_port_tm4c_init_cb(void *f_args) {
    (void)f_args;
    tm4c_pwm_init();
    return PWM_OK;
}


void pwm_port_tm4c_init(void *self) {
    pwm_port_template_init((PWM_Object_S*)self, pwm_port_tm4c_init_cb, NULL);
}


void pwm_port_tm4c_set_period(void *self, uint32_t value) {
    PWM_Object_S *object = (PWM_Object_S*)self;
    object->_private.period = value;
    tm4c_pwm_set_period(object->_private.period);
}


void pwm_port_tm4c_set_duty(void *self, uint32_t value) {
    PWM_Object_S *object = (PWM_Object_S*)self;
    object->_private.duty = value;
    tm4c_pwm_set_duty(object->_private.duty);
}


/**
 * TM4C Channel 2
 */
static int64_t pwm_port_tm4c_ch2_init_cb(void *f_args) {
    (void)f_args;
    tm4c_pwm_init_ch2();
    return PWM_OK;
}


void pwm_port_tm4c_ch2_init(void *self) {
    pwm_port_template_init((PWM_Object_S*)self, pwm_port_tm4c_ch2_init_cb, NULL);
}


void pwm_port_tm4c_ch2_set_period(void *self, uint32_t value) {
    PWM_Object_S *object = (PWM_Object_S*)self;
    object->_private.period = value;
    tm4c_pwm_set_period_ch2(object->_private.period);
}


void pwm_port_tm4c_ch2_set_duty(void *self, uint32_t value) {
    PWM_Object_S *object = (PWM_Object_S*)self;
    object->_private.duty = value;
    tm4c_pwm_set_duty_ch2(object->_private.duty);
}


/**
 * TM4C Channel 4
 */
static int64_t pwm_port_tm4c_ch4_init_cb(void *f_args) {
    (void)f_args;
    tm4c_pwm_init_ch4();
    return PWM_OK;
}


void pwm_port_tm4c_ch4_init(void *self) {
    pwm_port_template_init((PWM_Object_S*)self, pwm_port_tm4c_ch4_init_cb, NULL);
}


void pwm_port_tm4c_ch4_set_period(void *self, uint32_t value) {
    PWM_Object_S *object = (PWM_Object_S*)self;
    object->_private.period = value;
    tm4c_pwm_set_period_ch4(object->_private.period);
}


void pwm_port_tm4c_ch4_set_duty(void *self, uint32_t value) {
    PWM_Object_S *object = (PWM_Object_S*)self;
    object->_private.duty = value;
    tm4c_pwm_set_duty_ch4(object->_private.duty);
}