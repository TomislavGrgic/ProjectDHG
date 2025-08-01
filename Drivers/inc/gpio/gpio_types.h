#ifndef __GPIO_PRIVATE_TYPES__
#define __GPIO_PRIVATE_TYPES__

#include <stdint.h>
#include "gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    unsigned char dummy;
} GPIO_Private_S;


typedef struct {
    GPIO_S _public;
    GPIO_Private_S _private;
} GPIO_Object_S;

#ifdef __cplusplus
}
#endif

#endif /*__GPIO_PRIVATE_TYPES__*/