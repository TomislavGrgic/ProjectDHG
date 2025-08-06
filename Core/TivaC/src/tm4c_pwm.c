#include "tm4c_pwm.h"

/*
* This part of the code is for PWM0 channel 0. Other parts are for the same PWM0 just other channels.
* Each channel has its own init and functions. I wanted to do it this way to test the upper abstraction layer.
*/
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


/*
* This part of the code is for PWM0 channel 2. Channel 1 is invert of channel 0.
*/
void tm4c_pwm_init_ch2(void) {
    SYSCTL->RCGCPWM |= SYSCTL_RCGCPWM_R0;
    SYSCTL->RCGCGPIO |= SYSCTL_RCGCGPIO_R1;
    SYSCTL->RCC &= ~SYSCTL_RCC_PWMDIV_7;
    SYSCTL->RCC |= (1u<<20);
    SYSCTL->RCC |= SYSCTL_RCC_PWMDIV_7;

    GPIOB->DIR &= ~GPIO_DIR_4;
    GPIOB->DEN |= GPIO_DEN_4;
    GPIOB->AFSEL |= GPIO_AFSEL_4;
    GPIOB->PCTL &= ~GPIO_PCTL_MX4_15;
    GPIOB->PCTL |= GPIO_PCTL_MX4_4;

    //Config PWM logic
    PWM0->_1_GENA = PWM_GENA_ACTLOAD_2 | PWM_GENA_ACTCMPD_3;
    //Load frequency and duty cycle
    PWM0->_1_LOAD = 0;
    PWM0->_1_CMPA = 0;
    //Enable PWM
    PWM0->CTL  |= PWM_CTL_GLOBALSYNC1;
    PWM0->_1_CTL  |= 1;
    PWM0->ENABLE |= PWM_ENABLE_PWM2EN;
}

void tm4c_pwm_set_period_ch2(uint16_t period) {
    PWM0->_1_LOAD = period;
}

void tm4c_pwm_set_duty_ch2(uint16_t duty) {
    PWM0->_1_CMPA = duty;
}


#define PWM_ENABLE_PWM4EN   (1u<<4)


/*
* This part of the code is for PWM0 channel 4. Channel 3 is invert of channel 2.
*/
void tm4c_pwm_init_ch4(void) {
    SYSCTL->RCGCPWM |= SYSCTL_RCGCPWM_R0;
    SYSCTL->RCGCGPIO |= SYSCTL_RCGCGPIO_R4;
    SYSCTL->RCC &= ~SYSCTL_RCC_PWMDIV_7;
    SYSCTL->RCC |= (1u<<20);
    SYSCTL->RCC |= SYSCTL_RCC_PWMDIV_7;

    GPIOE->DIR &= ~GPIO_DIR_4;
    GPIOE->DEN |= GPIO_DEN_4;
    GPIOE->AFSEL |= GPIO_AFSEL_4;
    GPIOE->PCTL &= ~GPIO_PCTL_MX4_15;
    GPIOE->PCTL |= GPIO_PCTL_MX4_4;

    //Config PWM logic
    PWM0->_2_GENA = PWM_GENA_ACTLOAD_2 | PWM_GENA_ACTCMPD_3;
    //Load frequency and duty cycle
    PWM0->_2_LOAD = 0;
    PWM0->_2_CMPA = 0;
    //Enable PWM
    PWM0->CTL  |= PWM_CTL_GLOBALSYNC1;
    PWM0->_2_CTL  |= 1;
    PWM0->ENABLE |= PWM_ENABLE_PWM4EN;
}

void tm4c_pwm_set_period_ch4(uint16_t period) {
    PWM0->_2_LOAD = period;
}

void tm4c_pwm_set_duty_ch4(uint16_t duty) {
    PWM0->_2_CMPA = duty;
}