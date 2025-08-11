#include "adc.h"
#include "adc_types.h"
#include "adc_port.h"


ADC_Object_S ADC_obj = {
    ._public = {
        .self = (void*)&ADC_obj,
        .init = tm4c_adc_port_init,
        .activate_channel = tm4c_adc_port_activate_channel,
        .read = tm4c_adc_port_read
    },
    ._private = {
        .dummy = 0x12
    }
};
ADC_S *ADC = (ADC_S*)&ADC_obj;


inline int64_t adc_init(ADC_S *object) {
    return object->init(object->self);
}

inline int64_t adc_activate_channel(ADC_S *object, int64_t channel) {
    return object->activate_channel(object->self, channel);
}

inline int64_t adc_read(ADC_S *object, int64_t channel) {
    return object->read(object->self, channel);
}