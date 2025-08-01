#ifndef _ENCODER_ABS_H__
#define _ENCODER_ABS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    void* self;
    void (*init)(void* self);
    void (*get_position)(void *self);
    void (*get_direction)(void *self);
    void (*get_speed)(void *self);
} Encoder_S;

#ifdef __cplusplus
}
#endif

#endif /*_ENCODER_ABS_H__*/