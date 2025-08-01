#ifndef __WRP_GPIO_H__
#define __WRP_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

enum {
    INPUT = 0,
    OUTPUT = 1
};

enum {
    LOW = 0,
    HIGH = 1
};

typedef struct {
    void *self;
    void (*pin_mode)(void *, int pin, int mode);
    int (*read)(void *, int pin);
    void (*write)(void *, int pin, int state);
} GPIO_S;

extern GPIO_S* GPIO;

void gpio_mode(GPIO_S* object, int pin, int mode);
void gpio_write(GPIO_S* object, int pin, int state);
int gpio_read(GPIO_S* object, int pin);

#ifdef __cplusplus
}
#endif

#endif /*__WRP_GPIO_H__*/