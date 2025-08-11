#ifndef _ADC_TYPES_INTERFACE_H__
#define _ADC_TYPES_INTERFACE_H__

#include "adc.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t dummy;
} ADC_Private_S;

typedef struct {
    ADC_S _public;
    ADC_Private_S _private;
} ADC_Object_S;

#ifdef __cplusplus
}
#endif

#endif /*_ADC_TYPES_INTERFACE_H__*/