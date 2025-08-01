#include "tm4c_qei.h"



void tm4c_qei_init(void) {
    SYSCTL->RCGCQEI |= SYSCTL_QEI_1_EN;
    SYSCTL->RCGCGPIO |= SYSCTL_GPIOC_EN;

    GPIOC->DIR &= ~( (1u<<4) | (1u<<5) | (1u<<6) ); 
    GPIOC->DEN |= (1u<<4) | (1u<<5) | (1u<<6);
    GPIOC->AFSEL |= GPIO_AFSEL_4 | GPIO_AFSEL_5 | GPIO_AFSEL_6;
    GPIOC->PCTL &= ~( GPIO_PCTL_4 | GPIO_PCTL_5 | GPIO_PCTL_6 );
    GPIOC->PCTL |= GPIO_PCTL_4_MD_6 | GPIO_PCTL_5_MD_6 | GPIO_PCTL_6_MD_6;  
    
    //Config QEI
    QEI1->CTL |= QEI_CTL_CAPMODE | QEI_CTL_VELEN;  
    //Velocity prescalar
    QEI1->CTL &= ~QEI_CTL_VELDIV_ALL;
    QEI1->CTL |= QEI_CTL_VELDIV_0;
    //Velovity timer
    QEI1->LOAD |= 599999;  
    // No max position, count all the way up.
    QEI1->MAXPOS = 0xFFFFFFFF;
    //Enable interrupts
    QEI1->INTEN |= ( QEI_INTEN_INTTIMER | QEI_INTEN_INTDIR ); 
    //Enable
    QEI1->CTL |= QEI_CTL_ENABLE; 
}


uint32_t tm4c_qei_get_position(void) {
    return QEI1->POS;
}

int32_t tm4c_qei_get_direction(void) {
    if( !(QEI1->ISC & QEI_ISC_INTDIR) ) {
        return -1;
    }
    return !!(QEI1->STAT&QEI_STAT_DIRECTION);
}

int32_t tm4c_qei_get_speed(void) {
    if( !(QEI1->ISC & QEI_ISC_INTTIMER) ) {
        return -1;
    }
    return QEI1->SPEED;
}