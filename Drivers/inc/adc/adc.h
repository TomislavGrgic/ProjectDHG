#ifndef _ADC_INTERFACE_H__
#define _ADC_INTERFACE_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ADC_METHODS     3 /**Needs to be changed to corespond with the number of callbacks in the object. */
typedef struct {
    void *self;
    int64_t (*init)(void *self);
    int64_t (*activate_channel)(void *self, int64_t channel);
    int64_t (*read)(void *self, int64_t channel);
} ADC_S;

extern ADC_S* ADC;

int64_t adc_init(ADC_S *object);
int64_t adc_activate_channel(ADC_S *object, int64_t channel);
int64_t adc_read(ADC_S *object, int64_t channel);

#ifdef __cplusplus
}
#endif

#endif /*_ADC_INTERFACE_H__*/