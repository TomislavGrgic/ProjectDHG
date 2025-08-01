#ifndef __WRP_GPIO_PORT_H__
#define __WRP_GPIO_PORT_H__

#include "tm4c_gpio.h"
#include "gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

void gpio_port_pin_mode(void *self, int pin, int mode);
int gpio_port_read(void *self, int pin);
void gpio_port_write(void *self, int pin, int mode);

#ifdef __cplusplus
}
#endif

#endif /*__WRP_GPIO_PORT_H__*/