#include "pwm.h"
#include "pwm_port.h"
#include "pwm_types.h"

PWM_Object_S PWM_Object = {
    ._public = {
        .self = (void*)&PWM_Object,
        .init = pwm_port_tm4c_init,
        .set_period = pwm_port_tm4c_set_period,
        .set_duty = pwm_port_tm4c_set_duty
    },
    ._private = {
        .duty = 0,
        .period = 0
    }
};
PWM_S *PWM = (PWM_S*)&PWM_Object;


PWM_Object_S PWM2_Object = {
    ._public = {
        .self = (void*)&PWM2_Object,
        .init = pwm_port_tm4c_ch2_init,
        .set_period = pwm_port_tm4c_ch2_set_period,
        .set_duty = pwm_port_tm4c_ch2_set_duty
    },
    ._private = {
        .duty = 0,
        .period = 0
    }
};
PWM_S *PWM2 = (PWM_S*)&PWM2_Object;


PWM_Object_S PWM4_Object = {
    ._public = {
        .self = (void*)&PWM4_Object,
        .init = pwm_port_tm4c_ch4_init,
        .set_period = pwm_port_tm4c_ch4_set_period,
        .set_duty = pwm_port_tm4c_ch4_set_duty
    },
    ._private = {
        .duty = 0,
        .period = 0
    }
};
PWM_S *PWM4 = (PWM_S*)&PWM4_Object;


inline void pwm_init(PWM_S *object) {
    object->init(object->self);
}


inline void pwm_set_period(PWM_S *object, uint16_t period) {
    object->set_period(object->self, period);
}


inline void pwm_set_duty(PWM_S *object, uint16_t duty) {
    object->set_duty(object->self, duty);
}