
#include <stdint.h>
#include <stddef.h>
#include "gpio.h"
#include "pwm.h"
#include "encoder.h"
#include "tm4c_systick.h"
#include "adc.h"

#define RGB_BLUE_PIN    42
#define MAX_FREQ        250000

#define NOTE_FORMULA(freq)   ((int)(250000/((float)freq)+note_offset(30,15))) 

#define G2 NOTE_FORMULA(98.00)

#define C3  NOTE_FORMULA(130.81)
#define Cs3 NOTE_FORMULA(138.59)
#define D3  NOTE_FORMULA(146.83)
#define Ds3 NOTE_FORMULA(155.56)
#define E3  NOTE_FORMULA(164.81)
#define F3  NOTE_FORMULA(174.61)
#define Fs3 NOTE_FORMULA(185.00)
#define G3  NOTE_FORMULA(196.00)
#define Gs3 NOTE_FORMULA(207.65)
#define A3  NOTE_FORMULA(220.00)
#define As3 NOTE_FORMULA(233.08)
#define B3  NOTE_FORMULA(246.94)

#define C4  NOTE_FORMULA(261.63)
#define Cs4 NOTE_FORMULA(277.18)
#define D4  NOTE_FORMULA(293.66)
#define Ds4 NOTE_FORMULA(311.13)
#define E4  NOTE_FORMULA(329.63)
#define F4  NOTE_FORMULA(349.23)
#define Fs4 NOTE_FORMULA(369.99)
#define G4  NOTE_FORMULA(392.00)
#define Gs4 NOTE_FORMULA(415.30)
#define A4  NOTE_FORMULA(440.00)
#define As4 NOTE_FORMULA(466.16)
#define B4  NOTE_FORMULA(493.88)

#define C5  NOTE_FORMULA(523.25)
#define Cs5 NOTE_FORMULA(554.37)
#define D5  NOTE_FORMULA(587.33)
#define Ds5 NOTE_FORMULA(622.25)
#define E5  NOTE_FORMULA(659.25)
#define F5  NOTE_FORMULA(698.46)
#define Fs5 NOTE_FORMULA(739.99)
#define G5  NOTE_FORMULA(783.99)
#define Gs5 NOTE_FORMULA(830.61)
#define A5  NOTE_FORMULA(880.00)
#define As5 NOTE_FORMULA(932.33)
#define B5  NOTE_FORMULA(987.77)

#define PA1 1
#define PA7 7
#define PE1 33
#define PE2 34
#define PE3 35
#define PD1 25
#define PD2 26
#define PD3 27
#define PF1 41
#define PF4 44

#define NUM_OF_STRINGS  3


typedef struct {
   uint8_t *pin;
   uint32_t *note;
   uint32_t default_note;
   size_t size;
}Keys_S;

int32_t seed = 141351;

int32_t pseudo_rand(void) {
   seed = (123456789 * seed>>1) + ( ((seed++)<<1) * (float)(seed/(float)3.14));
   return seed;
}

int32_t note_offset(int max, int offset) {
   int32_t value = pseudo_rand();
   return (pseudo_rand()%max) - offset;
}


int play_notes(Keys_S *keys) {
   if(keys == NULL) return 0;
   for(int i = 0; i < keys->size; i++) {
      if( !gpio_read(GPIO, keys->pin[i]) ) {
         return keys->note[i];
      }
   }
   return keys->default_note;
}

void init_pins(uint8_t *pins, size_t size) {
   for(int i = 0; i < size; i++) {
      gpio_mode(GPIO, pins[i], INPUT);
      gpio_pull_mode(GPIO, pins[i], PULL_UP);
   }
}

void main(void) {    
   uint8_t pins[] = { PA7, PE3, PE2, PD1, PD2, PD3, PE1 };
   uint32_t first_notes[] = { G5, F5, E5, D5, C5, B4, A4 };
   uint32_t second_notes[] = { G4, F4, E4, D4, C4, B3, A3 };

   systick_init();
   adc_init(ADC);
   adc_activate_channel(ADC, 1);
   adc_activate_channel(ADC, 2);
   init_pins(pins, sizeof(pins)/sizeof(uint8_t));
   
   PWM_S *strings[NUM_OF_STRINGS] = {
      PWM, PWM2, PWM4
   };

   for(int i = 0; i < NUM_OF_STRINGS; i++) {
      pwm_init(strings[i]);
   }

   Keys_S first_melody = {
      .pin = pins,
      .note = first_notes,
      .default_note = G4,
      .size = sizeof(pins) / sizeof(uint8_t)
   };

   Keys_S second_melody = {
      .pin = pins,
      .note = second_notes,
      .default_note = G3,
      .size = sizeof(pins) / sizeof(uint8_t)
   };

   while (1) { 
      int melodies[NUM_OF_STRINGS] = {
         play_notes(&first_melody),
         play_notes(&second_melody),
         G2
      };

      for(int i = 0; i < NUM_OF_STRINGS; i++) {
         pwm_set_period(strings[i], melodies[i]);
         pwm_set_duty(strings[i], melodies[i]>>2);
      }

      volatile int aaa = adc_read(ADC, 1);
      volatile int bbb = aaa;
      systick_sleep_ms(10);

      volatile int aaa1 = adc_read(ADC, 2);
      volatile int bbb1 = aaa1;
      systick_sleep_ms(10);
   }
 }


   

 