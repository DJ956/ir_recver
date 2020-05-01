/*
1T = 350~500us
-----------------------------
0 => ON(1T) -> OFF(1T)
1 => ON(1T) -> OFF(3T)
-----------------------------
(1T)425us / 5 = 85
(3T)1275us / 5 = 255
(4T)1700us / 5 = 340
(8T)3400us / 5 = 680
-----------------------------
Data
reader		  |customer code|parity|data      |trailer
ON(8T) OFF(4T)|16bit		|4bit  |48bit(var)|ON(1T) -> OFF(>=8ms)
-----------------------------
Trailer
ON(1T) -> OFF(>=8ms)
*/

#include "mcc_generated_files/mcc.h"
#include <stdio.h>

#define MAX_SIZE 48
#define CS_SIZE 16
#define PARITY_SIZE 4
#define DATA_SIZE 28

void putch(char data){
    EUSART_Write(data);
}

void recv_data(uint8_t *data, uint8_t size);
uint8_t recv_reader();
uint8_t bit_find();

void main(void)
{    
    SYSTEM_Initialize();    
    printf("init AEHA format");
    printf("\r\n");
    
    LED_1_SetHigh();
    
	while(1){
		uint8_t data[MAX_SIZE];
		
		while(IR_GetValue() == 1){
			__delay_us(5);
		}

		recv_reader();
		recv_data(data, MAX_SIZE);
		putch('|');
        printf("\r\n");
	}
}

/**
ON(8T) -> OFF(4T)
(4T)1700us / 5 = 340
(8T)3400us / 5 = 680
*/
uint8_t recv_reader(){
	int width = 0;
	while(IR_GetValue() == 0){
		width++;
		__delay_us(5);
	}
    
	if(width > 800){
		return -1;
	}

	width = 0;
	while(IR_GetValue() == 1){
		width++;
		__delay_us(5);
		
		if(width > 500){
			return -1;
		}
	}

	return 0;
}

/**
data 48bit (variable)
*/
void recv_data(uint8_t *data, uint8_t size){
	uint8_t i;
	for(i = 0; i < size; i++){
		uint8_t a = bit_find();
		if(a == 3) break;

		data[i] = a;
		putch(a + '0');
	}
}

/**
Trailer
ON(1T) -> OFF(>=8ms)
8000us / 5 = 1600
-----------------------------
0 => ON(1T) -> OFF(1T)
1 => ON(1T) -> OFF(3T)
-----------------------------
(1T)425us / 5 = 85
(3T)1275us / 5 = 255
*/
uint8_t bit_find(){
	int width = 0;
	while(IR_GetValue() == 0){
		width++;        
		__delay_us(5);        
	}

	if(width < 50){
        printf("e");
		return 2;
	}

	width = 0;
	while(IR_GetValue() == 1){
		width++;        
		__delay_us(5);        
		
		if(width > 1800){
            printf("end");
			return 3;
		}
	}

	if(width < 100){
		return 0;
	}else{
		return 1;
	}
}