#ifndef _ENCODER_ABS_H__
#define _ENCODER_ABS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
    ENC_OK,
    ENC_NULL_PRT
};


typedef struct {
    void* self;
    int64_t (*init)(void* self);
    uint32_t (*get_position)(void *self);
    uint8_t (*get_direction)(void *self);
    uint32_t (*get_speed)(void *self);
} Encoder_S;

extern Encoder_S* Encoder;

int64_t encoder_init(Encoder_S* object);
uint32_t encoder_get_position(Encoder_S* object);
uint8_t encoder_get_direction(Encoder_S* object);
uint32_t encoder_get_speed(Encoder_S* object);

#ifdef __cplusplus
}
#endif

#endif /*_ENCODER_ABS_H__*/