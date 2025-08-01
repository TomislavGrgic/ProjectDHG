#include "tm4c_gpio.h"

static GPIOA_Type* ports[] = {
    GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF 
};


void tm4c_gpio_mode(uint8_t port, uint8_t pin, uint8_t mode) {
    if(port >= TM4C_PORT_MAX) {
        return;
    }

    if(pin >= TM4C_PIN_MAX) {
        return;
    }

    SYSCTL->RCGCGPIO |= TM4C_GPIO_PORT_BIT(port);

    ports[port]->DIR &= ~TM4C_GPIO_PIN_BIT(pin);
    ports[port]->DIR |= TM4C_GPIO_MODE_BIT(mode, pin);
    ports[port]->DEN |= TM4C_GPIO_PIN_BIT(pin);
}


void tm4c_gpio_read(uint8_t port, uint8_t pin, uint8_t* output) {
    if(port >= TM4C_PORT_MAX) {
        return;
    }

    if(pin >= TM4C_PIN_MAX) {
        return;
    }

    *output = ports[port]->DATA & pin;
    *output = !!(*output);
}


void tm4c_gpio_write(uint8_t port, uint8_t pin, uint8_t input) {
    if(port >= TM4C_PORT_MAX) {
        return;
    }

    if(pin >= TM4C_PIN_MAX) {
        return;
    }

    if(!input) {
        ports[port]->DATA &= ~TM4C_GPIO_PIN_BIT(pin);
    } else {
        ports[port]->DATA |= TM4C_GPIO_PIN_BIT(pin);
    }
}


