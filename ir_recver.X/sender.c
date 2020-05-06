#include "mcc_generated_files/mcc.h"
#include "sender.h"
        
void pwm_out(){
    uint8_t i;
    for(i = 0; i < 8; i++){
        IR_LED_SetHigh();
        __delay_us(25);
        IR_LED_SetLow();
        __delay_us(5);
    }
}

/**
ON(8T) -> OFF(4T)
(4T)1700us / 5 = 340
(8T)3400us / 5 = 680
*/
void send_reader(){
    uint8_t width = 0;
    while(width < 3400){
        high_bit();
        __delay_us(1);
    }
    width = 0;
    while(width < 1700){
        low_bit();
        __delay_us(1);
    }
    
}

void send_data(uint8_t *data, uint8_t size){    
    uint8_t i;
    for(i = 0; i < size; i++){
        if(data[i] == 0){
            low_bit();
        }else{
            high_bit();
        }
    }
}

void send_data_ch(char *data, uint8_t size){
    uint8_t i;
    for(i = 0; i < size; i++){
        if(data[i] == '0'){
            low_bit();
        }else{
            high_bit();
        }
    }
}

void high_bit(){
    pwm_out();
    IR_LED_SetLow();
    __delay_us(425);
}

void low_bit(){
    pwm_out();
    IR_LED_SetLow();
    __delay_us(1275);
}
