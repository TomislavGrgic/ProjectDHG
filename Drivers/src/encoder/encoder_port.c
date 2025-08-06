#include "encoder_port.h"
#include "encoder_types.h"
#include "tm4c_qei.h"

#define ENCODER_NULL_PTR_CHECK(fun)    do{ if(fun == NULL) return ENC_NULL_PRT; }while(0);


static inline int64_t encoder_port_wrapper_init(void *self, int64_t (function_cb)(void* f_args), void *args) {
    Encoder_Object_S* object = (Encoder_Object_S*)self;
    int64_t ret = ENC_OK;

    ENCODER_NULL_PTR_CHECK(object);
    ENCODER_NULL_PTR_CHECK(object->_public.init);
    ENCODER_NULL_PTR_CHECK(object->_public.get_position);
    ENCODER_NULL_PTR_CHECK(object->_public.get_direction);
    ENCODER_NULL_PTR_CHECK(object->_public.get_speed);

    //Driver specific callback
    if(function_cb != NULL) {
        ret = function_cb(args);

        if( ret != ENC_OK ) {
            return ret;
        }
    }

    object->_private.position = 0;
    object->_private.direction = 0;
    object->_private.speed = 0;
    return ret;
}


int64_t encoder_tm4c_port_init_cb(void* f_args) {
    (void)f_args;
    tm4c_qei_init();
    return ENC_OK;
}


int64_t encoder_tm4c_port_init(void* self) {
    return encoder_port_wrapper_init(self, encoder_tm4c_port_init_cb, NULL);
}


uint32_t encoder_tm4c_port_get_position(void* self) {
    Encoder_Object_S* object = (Encoder_Object_S*)self;
    object->_private.position = tm4c_qei_get_position();
    return object->_private.position;
}


uint8_t encoder_tm4c_port_get_direction(void* self) {
    Encoder_Object_S* object = (Encoder_Object_S*)self;
    object->_private.direction = tm4c_qei_get_direction();
    return object->_private.direction;
}


uint32_t encoder_tm4c_port_get_speed(void* self) {
    Encoder_Object_S* object = (Encoder_Object_S*)self;
    object->_private.speed = tm4c_qei_get_speed();
    return object->_private.speed;
}