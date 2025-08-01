#ifndef _TM4C_QEI_H__
#define _TM4C_QEI_H__

#include "TM4C123.h"
#include <stdint.h>

#define SYSCTL_QEI_1_EN         (1u<<1)
#define SYSCTL_GPIOC_EN         (1u<<2)

#define GPIO_AFSEL_4            (1u<<4)
#define GPIO_AFSEL_5            (1u<<5)
#define GPIO_AFSEL_6            (1u<<6)

#define GPIO_PCTL_4             (15u<<16)
#define GPIO_PCTL_5             (15u<<20)
#define GPIO_PCTL_6             (15u<<24)

#define GPIO_PCTL_4_MD_6        (6u<<16)
#define GPIO_PCTL_5_MD_6        (6u<<20)
#define GPIO_PCTL_6_MD_6        (6u<<24)

#define QEI_CTL_ENABLE          (1u<<0)
#define QEI_CTL_CAPMODE         (1u<<3)
#define QEI_CTL_VELEN           (1u<<5)
#define QEI_CTL_VELDIV_ALL      (7u<<6)
#define QEI_CTL_VELDIV_0        (0u<<6)

#define QEI_STAT_DIRECTION      (1u<<1)

#define QEI_ISC_INTTIMER        (1u<<1)
#define QEI_ISC_INTDIR          (1u<<2)

#define QEI_INTEN_INTTIMER      (1u<<1)
#define QEI_INTEN_INTDIR        (1u<<2)


#ifdef __cplusplus
extern "C" {
#endif

void tm4c_qei_init(void);
uint32_t tm4c_qei_get_position(void);
int32_t tm4c_qei_get_direction(void);
int32_t tm4c_qei_get_speed(void);

#ifdef __cplusplus
}
#endif

#endif /*_TM4C_QEI_H__*/