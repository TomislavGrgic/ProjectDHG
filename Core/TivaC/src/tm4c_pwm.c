#include "tm4c_pwm.h"

void tm4c_pwm_init(void) {
    SYSCTL->RCGCPWM |= SYSCTL_RCGCPWM_R0;
    SYSCTL->RCGCGPIO |= SYSCTL_RCGCGPIO_R1;
    SYSCTL->RCC &= ~SYSCTL_RCC_PWMDIV_7;
    SYSCTL->RCC |= (1u<<20);
    SYSCTL->RCC |= SYSCTL_RCC_PWMDIV_7;

    GPIOB->DIR &= ~GPIO_DIR_6;
    GPIOB->DEN |= GPIO_DEN_6;
    GPIOB->AFSEL |= GPIO_AFSEL_6;
    GPIOB->PCTL &= ~GPIO_PCTL_MX6_15;
    GPIOB->PCTL |= GPIO_PCTL_MX6_4;

    //Config PWM logic
    PWM0->_0_GENA = PWM_GENA_ACTLOAD_2 | PWM_GENA_ACTCMPD_3;
    //Load frequency and duty cycle
    PWM0->_0_LOAD = 0;
    PWM0->_0_CMPA = 0;
    //Enable PWM
    PWM0->CTL  |= PWM_CTL_GLOBALSYNC0;
    PWM0->_0_CTL  |= 1;
    PWM0->ENABLE |= PWM_ENABLE_PWM0EN;
}

void tm4c_pwm_set_period(uint16_t period) {
    PWM0->_0_LOAD = period;
}

void tm4c_pwm_set_duty(uint16_t duty) {
    PWM0->_0_CMPA = duty;
}