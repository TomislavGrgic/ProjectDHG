#include "gpio.h"
#include "gpio_port.h"
#include "gpio_types.h"

static GPIO_Object_S GPIO_object = {
    ._public = {
        .self = (void*)&GPIO_object,
        .pin_mode = gpio_port_pin_mode,
        .read = gpio_port_read,
        .write = gpio_port_write
    },

    ._private = {
        .dummy = 25 //Private test 
    }   
};
GPIO_S* GPIO = (GPIO_S*)&GPIO_object;


inline void gpio_mode(GPIO_S* object, int pin, int mode) {
    object->pin_mode(object->self, pin, mode);
}

inline void gpio_write(GPIO_S* object, int pin, int state) {
    object->write(object->self, pin, state); 
}

inline int gpio_read(GPIO_S* object, int pin) {
    return object->read(object->self, pin);
}