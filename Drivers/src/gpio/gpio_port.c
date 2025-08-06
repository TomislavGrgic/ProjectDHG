#include "gpio_port.h"
#include "gpio_types.h"

#define GPIO_GET_PORT(x)    ( (x>>3)&0x07 )
#define GPIO_GET_PIN(x)     (x&0x07)

void gpio_port_pin_mode(void *self, int pin, int mode) {
    (void)self;
    const uint8_t ll_port = GPIO_GET_PORT(pin);
    const uint8_t ll_pin = GPIO_GET_PIN(pin);
    tm4c_gpio_mode(ll_port, ll_pin, mode);
}


int gpio_port_read(void *self, int pin) {
    (void)self;
    const uint8_t ll_port = GPIO_GET_PORT(pin);
    const uint8_t ll_pin = GPIO_GET_PIN(pin);

    uint8_t pin_state = 0;
    tm4c_gpio_read(ll_port, ll_pin, &pin_state);
    return pin_state;
}


void gpio_port_write(void *self, int pin, int mode) {
    (void)self; 
    const uint8_t ll_port = GPIO_GET_PORT(pin);
    const uint8_t ll_pin = GPIO_GET_PIN(pin);
    tm4c_gpio_write(ll_port, ll_pin, mode);
}


void gpio_port_pull_mode(void *self, int pin, int mode) {
    (void)self; 
    const uint8_t ll_port = GPIO_GET_PORT(pin);
    const uint8_t ll_pin = GPIO_GET_PIN(pin);
    tm4c_gpio_pull(ll_port, ll_pin, mode);
}