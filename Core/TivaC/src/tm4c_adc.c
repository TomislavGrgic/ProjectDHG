#include "tm4c_adc.h"
#include "common_erorrs.h"

static int64_t tm4c_adc0_ll_gpio_init(uint8_t port, uint8_t pin);
static int64_t tm4c_adc0_ll_init(uint8_t channel);

typedef struct{
    uint8_t port;
    uint8_t pin;
} ADC_Channel_Pin_S;


static const ADC_Channel_Pin_S channels[AIN_MAX] = {
    {.pin = 3, .port = 4},
    {.pin = 2, .port = 4},
    {.pin = 1, .port = 4},
    {.pin = 0, .port = 4},
    {.pin = 3, .port = 3},
    {.pin = 2, .port = 3},
    {.pin = 1, .port = 3},
    {.pin = 0, .port = 3},
    {.pin = 5, .port = 4},
    {.pin = 4, .port = 4},
    {.pin = 4, .port = 1},
    {.pin = 5, .port = 1},
};


inline static void tm4c_adc0_change_ss3_chn(uint8_t channel) {
    ADC0->SSMUX3 &= ~(0b1111u<<0); //MUX0
    ADC0->SSMUX3 |= ((uint16_t)channel<<0); //MUX0
} 


int64_t tm4c_adc0_init(uint8_t channel) {
    if(channel >= AIN_MAX) return ERR_INVALID_PARAMETER;
    SYSCTL->RCGCADC |= (1u<<0);
    CHECK_ERROR( tm4c_adc0_ll_gpio_init(channels[channel].port, channels[channel].pin) );
    CHECK_ERROR( tm4c_adc0_ll_init(channel) );
    return ERR_OK;
}


static int64_t tm4c_adc0_ll_gpio_init(uint8_t port, uint8_t pin) {
    enum{ GPIO_PORTS_NUM = 6 };
    if( port >= GPIO_PORTS_NUM ) return ERR_INVALID_PARAMETER;
    
    GPIOA_Type* ports[GPIO_PORTS_NUM] = {
        GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF,
    };
    
    SYSCTL->RCGCGPIO |= (1u<<port);
    
    ports[port]->DIR &= ~(1u<<pin);
    ports[port]->AFSEL |= (1u<<pin);
    ports[port]->AMSEL |= (1u<<pin);
    ports[port]->PCTL &= ~(15u<<(pin*4));
    ports[port]->DEN &= ~(1u<<pin);

    return ERR_OK;
}


static int64_t tm4c_adc0_ll_init(uint8_t channel) {
    ADC0->ACTSS &= ~(1u<<3); //ASEN3

    ADC0->EMUX &= ~(0b1111u<<3); //EM3
    ADC0->EMUX |= (0x00u<<3);

    tm4c_adc0_change_ss3_chn(channel);

    ADC0->SSCTL3 &= ~(0b1111u<<0);
    ADC0->SSCTL3 |= (0b0110u<<0);

    ADC0->IM = 0;
    ADC0->ACTSS |= (1u<<3); //ASEN3

    return ERR_OK;
}


uint32_t tm4c_adc0_read(uint8_t channel) {
    ADC0->ACTSS &= ~(1u<<3);
    tm4c_adc0_change_ss3_chn(channel);
    ADC0->ACTSS |= (1u<<3); //ASEN3

    ADC0->PSSI |= (1u<<3); //SS3
    while( !(ADC0->RIS & (1u<<3)) );    //INR3
    uint32_t raw = ADC0->SSFIFO3;
    ADC0->ISC &= ~(1u<<3);  //IN3
    return raw;
}


