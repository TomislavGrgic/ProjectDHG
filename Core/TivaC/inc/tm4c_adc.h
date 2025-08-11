#ifndef _TM4C_ADC_H__
#define _TM4C_ADC_H__

#include "TM4C123.h"
#include <stdint.h>

enum {
    AIN0 = 0,
    AIN1,
    AIN2,
    AIN3,
    AIN4,
    AIN5,
    AIN6,
    AIN7,
    AIN8,
    AIN9,
    AIN10,
    AIN11,
    AIN_MAX
};

#ifdef __cplusplus
extern "C" {
#endif

int64_t tm4c_adc0_init(uint8_t channel);
uint32_t tm4c_adc0_read(uint8_t channel);

#ifdef __cplusplus
}
#endif

#endif /*_TM4C_ADC_H__*/