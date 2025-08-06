#ifndef _ENCODER_PORT_H__
#define _ENCODER_PORT_H__

#include <stdint.h>
#include <stddef.h>
#include "encoder.h"

#ifdef __cplusplus
extern "C" {
#endif

int64_t encoder_tm4c_port_init(void* self);
uint32_t encoder_tm4c_port_get_position(void* self);
uint8_t encoder_tm4c_port_get_direction(void* self);
uint32_t encoder_tm4c_port_get_speed(void* self);

#ifdef __cplusplus
}
#endif

#endif /*_ENCODER_PORT_H__*/