#include "adc_port.h"
#include "common_object.h"
#include "common_erorrs.h"


int64_t tm4c_adc_port_init(void* self) {
    CHECK_ERROR( common_object_construct(self, ADC_METHODS) );
    return ERR_OK;
}


int64_t tm4c_adc_port_activate_channel(void* self, int64_t channel) {
    CHECK_ERROR( tm4c_adc0_init(channel) );
    return ERR_OK;
}


int64_t tm4c_adc_port_read(void* self, int64_t channel) {
     return tm4c_adc0_read((uint8_t)channel);
}