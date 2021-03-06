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

#define SEP "-----------------------------\r\n"

void putch(char data){
    EUSART_Write(data);
}

uint8_t getch(){
    return EUSART_Read();
}

void recv_data(uint8_t size);
uint8_t recv_reader();
uint8_t bit_find();
uint8_t byte_recv();
void recv_daikin_reader();
void recv_daikin_frame(uint8_t size);
uint8_t detect_mode();

void DAIKIN();
void AEHA();
void SONY();
void NEC();


void main(void)
{    
    SYSTEM_Initialize();    
    LED_1_SetHigh();
    uint8_t mode = detect_mode();
    
    uint8_t cnt = 0;
        
	while(1){                      
        while(IR_GetValue() == 1){
            __delay_us(5);
        }
        
        if(mode == 'D'){
            DAIKIN();
        }else if(mode == 'A'){
            AEHA();
        }else if(mode == 'S'){
            SONY();
        }else if(mode == 'N'){
            NEC();
        }
        
        printf("end\r\n");
        printf("[%d]--------------------------\r\n", cnt);
        cnt++;        
	}
}

uint8_t detect_mode(){
    printf("IR Reciver Version 1.0.0\r\n");
    printf(SEP);
    printf("NEC:N | AEHA:A | DAIKIN:D | SONY:S|(*default:D)\r\n");
    
    uint8_t mode = getch();
    
    if(mode == 'N'){
        printf("Detect NEC\r\n");
        LED_N_SetHigh();
    }else if(mode == 'A'){
        printf("Detect AEHA\r\n");
        LED_A_SetHigh();
    }else if(mode == 'D'){
        printf("Detect DAIKIN\r\n");
        LED_D_SetHigh();
    }else if(mode == 'S'){
        printf("Detect SONY\r\n");
        LED_S_SetHigh();
    }else{
        mode = 'D';
        LED_D_SetHigh();
    }
    printf(SEP);
    
    return mode;
}

void AEHA(){		
	recv_reader();
	recv_data(MAX_SIZE);
	putch('|');
    printf("\r\n");  
}

void DAIKIN(){
    recv_daikin_reader();
               
    recv_reader();
    recv_daikin_frame(160);        
    putch('|');        
        
    __delay_ms(35);
        
    recv_reader();
    recv_daikin_frame(152);        
    putch('|');
}

void SONY(){
    
}

void NEC(){
    
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
void recv_data(uint8_t size){
	uint8_t i;    
	for(i = 0; i < size; i++){
		uint8_t a = bit_find();                				
		putch(a + '0');
        if(a == 3 || a == 2) break;
	}
}

void recv_daikin_reader(){
    uint8_t i;
    for(i = 0; i < 5; i++){
        uint8_t a = bit_find();
        putch(a + '0');
    }
    
    __delay_ms(25);
    printf("||");
}

void recv_daikin_frame(uint8_t size){
    uint8_t i;
    for(i = 0; i < size; i++){
        uint8_t a = bit_find();        
        putch(a + '0');              
        if(a == 3 || a == 2) break;
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
    
    /*
	if(width < 50){
        //printf("e");
		return 2;
	}
     * */

	width = 0;
	while(IR_GetValue() == 1){
		width++;        
		__delay_us(5);        
		        
        if(width > 300){
            return 3;
        }
	}

	if(width < 100){
		return 0;
	}else{
		return 1;
	}
}