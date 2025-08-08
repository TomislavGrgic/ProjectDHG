
#include <stdint.h>
#include <stddef.h>
#include "gpio.h"
#include "pwm.h"
#include "encoder.h"
#include "tm4c_systick.h"

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
   uint8_t pin;
   uint32_t note;
}Key_S;

int32_t seed = 141351;

int32_t pseudo_rand(void) {
   seed = (123456789 * seed>>1) + ( ((seed++)<<1) * (float)(seed/(float)3.14));
   return seed;
}

int32_t note_offset(int max, int offset) {
   int32_t value = pseudo_rand();
   return (pseudo_rand()%max) - offset;
}

void fake_delay(int32_t delay) {
   for(volatile int i = 0; i < delay; i++);
}

int play_notes(Key_S keys[], size_t size, uint32_t default_note) {
   if(keys == NULL) return 0;
   for(int i = 0; i < size; i++) {
      if( !gpio_read(GPIO, keys[i].pin) ) {
         return keys[i].note;
      }
   }
   return default_note;
}

void init_pins(void) {
   uint8_t pins[] = {
      PE1, PE2, PD1, PD2, PD3, PE3, PA7
   };

   for(int i = 0; i < sizeof(pins)/sizeof(uint8_t); i++) {
      gpio_mode(GPIO, pins[i], INPUT);
      gpio_pull_mode(GPIO, pins[i], PULL_UP);
   }
}

void main(void) { 
   systick_init();
   init_pins();
   
   PWM_S *strings[NUM_OF_STRINGS] = {
      PWM, PWM2, PWM4
   };

   for(int i = 0; i < NUM_OF_STRINGS; i++) {
      pwm_init(strings[i]);
   }
   
   Key_S first_melody [] = {
      {.pin = PA7, .note = G5},
      {.pin = PE3, .note = F5},
      {.pin = PE2, .note = E5},
      {.pin = PD1, .note = D5},
      {.pin = PD2, .note = C5},
      {.pin = PD3, .note = B4},
      {.pin = PE1, .note = A4},
   };

   Key_S second_melody [] = {
      {.pin = PA7, .note = G4},
      {.pin = PE3, .note = F4},
      {.pin = PE2, .note = E4},
      {.pin = PD1, .note = D4},
      {.pin = PD2, .note = C4},
      {.pin = PD3, .note = B3},
      {.pin = PE1, .note = A3},
   };

   while (1) { 
      int melodies[NUM_OF_STRINGS] = {
         play_notes(first_melody, sizeof(first_melody)/sizeof(Key_S), G4),
         play_notes(second_melody, sizeof(second_melody)/sizeof(Key_S), G3),
         G2
      };

      for(int i = 0; i < NUM_OF_STRINGS; i++) {
         pwm_set_period(strings[i], melodies[i]);
         pwm_set_duty(strings[i], melodies[i]>>2);
      }

      systick_sleep_ms(1000);

      for(int i = 0; i < NUM_OF_STRINGS; i++) {
         pwm_set_period(strings[i], 0);
         pwm_set_duty(strings[i], 0);
      }
      
      systick_sleep_ms(1000);
   }
 }


   

 