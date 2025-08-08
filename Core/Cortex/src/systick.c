#include "systick.h"

extern void SysTick_ISR_Handler(void);

int64_t tick_count = 0;

void SysTick_ISR_Handler(void) {
    tick_count++;
}

void systick_init(void) {
    /*Systick is divided by 4 according to the TM4C datasheet page 123*/
    SysTick->CTRL = 0;
    SysTick->LOAD = 4000 - 1;
    SysTick->VAL = 0;
    SysTick->CTRL = (1u<<0) | (1u<<1);
    __enable_irq();
}


int64_t systick_get_ticks(void) {
    __disable_irq();
    int64_t ticks = tick_count;
    __enable_irq();
    return ticks;
}


void systick_sleep_ms(int64_t delay) {
    int64_t sleep_timestamp = systick_get_ticks() + delay;
    while( sleep_timestamp > systick_get_ticks() );
}

