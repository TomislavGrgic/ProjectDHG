#include "encoder.h"
#include "encoder_port.h"
#include "encoder_types.h"

Encoder_Object_S Encoder_obj = {
    ._public = {
        .self = (void*)&Encoder_obj,
        .init = encoder_tm4c_port_init,
        .get_position = encoder_tm4c_port_get_position,
        .get_direction = encoder_tm4c_port_get_direction,
        .get_speed = encoder_tm4c_port_get_speed
    },
    ._private = {
        .position = 0,
        .direction = 0,
        .speed = 0
    }
};
Encoder_S* Encoder = (Encoder_S*)&Encoder_obj;


inline int64_t encoder_init(Encoder_S* object) {
    return object->init(object->self);
}

inline uint32_t encoder_get_position(Encoder_S* object) {
    return object->get_position(object->self);
}

inline uint8_t encoder_get_direction(Encoder_S* object) {
    return object->get_direction(object->self);
}

inline uint32_t encoder_get_speed(Encoder_S* object) {
    return object->get_speed(object->self);
}