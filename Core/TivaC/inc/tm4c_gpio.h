#ifndef __TM4C_GPIO_DRIVER__
#define __TM4C_GPIO_DRIVER__

#include "TM4C123.h"
#include <stdint.h>

typedef enum {
    TM4C_PORTA,
    TM4C_PORTB,
    TM4C_PORTC,
    TM4C_PORTD,
    TM4C_PORTE,
    TM4C_PORTF,
    TM4C_PORT_MAX
} TM4C_Port_E;

typedef enum {
    TM4C_PIN0,
    TM4C_PIN1,
    TM4C_PIN2,
    TM4C_PIN3,
    TM4C_PIN4,
    TM4C_PIN5,
    TM4C_PIN6,
    TM4C_PIN7,
    TM4C_PIN_MAX,
} TM4C_Pin_E;

#define TM4C_GPIO_OUTPUT        1
#define TM4C_GPIO_INPUT         0

#define TM4C_GPIO_PIN_BIT(pin)          (1u<<pin)
#define TM4C_GPIO_MODE_BIT(mode,pin)   (mode<<pin)
#define TM4C_GPIO_PORT_BIT(port)        (1u<<port)

void tm4c_gpio_mode(uint8_t port, uint8_t pin, uint8_t mode);
void tm4c_gpio_read(uint8_t port, uint8_t pin, uint8_t* output);
void tm4c_gpio_write(uint8_t port, uint8_t pin, uint8_t input);
void tm4c_gpio_pull(uint8_t port, uint8_t pin, uint8_t mode);

#endif /*__TM4C_GPIO_DRIVER__*/