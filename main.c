
#include <stdint.h>
#include "gpio.h"
#include "pwm.h"
#include "tm4c_qei.h"

#define RGB_BLUE_PIN    42
uint32_t speed = 0;

void fake_delay(int32_t delay) {
   for(volatile int i = 0; i < delay; i++);
}

void main(void) {
   gpio_mode(GPIO, RGB_BLUE_PIN, OUTPUT);

   tm4c_qei_init();
   pwm_init(PWM);
   pwm_set_period(PWM, 800);

   while (1)
   {  
      uint32_t speed_tmp = tm4c_qei_get_speed();
      if( speed_tmp != -1 ) {
         speed = speed*(float)0.9 + speed_tmp*(float)0.1;
      }

      pwm_set_duty(PWM, speed);
      fake_delay(30000);
   }
 }