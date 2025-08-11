#include "tm4c_system.h"

void tm4c_system_init(void) {
    //No init for now
}

void tm4c_system_reset(void) {
    SCB->AIRCR |= (1u<<2);
}