#ifndef _ENCODER_TYPES_H__
#define _ENCODER_TYPES_H__

#include "encoder.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
    int32_t position;
    int8_t direction;
    int32_t speed;
} Encode_Private_S;


typedef struct {
    Encoder_S _public;
    Encode_Private_S _private;
} Encoder_Object_S;

#ifdef __cplusplus
}
#endif

#endif /*_ENCODER_TYPES_H__*/