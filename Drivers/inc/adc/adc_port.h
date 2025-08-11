#ifndef _ADC_PORT_INTERFACE_H__
#define _ADC_PORT_INTERFACE_H__

#include "tm4c_adc.h"
#include "adc.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int64_t tm4c_adc_port_init(void* self);
int64_t tm4c_adc_port_activate_channel(void* self, int64_t channel);
int64_t tm4c_adc_port_read(void* self, int64_t channel);

#ifdef __cplusplus
}
#endif

#endif /*_ADC_PORT_INTERFACE_H__*/