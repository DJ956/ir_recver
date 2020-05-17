/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC16F1827
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.35	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED_N aliases
#define LED_N_TRIS                 TRISAbits.TRISA0
#define LED_N_LAT                  LATAbits.LATA0
#define LED_N_PORT                 PORTAbits.RA0
#define LED_N_ANS                  ANSELAbits.ANSA0
#define LED_N_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LED_N_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LED_N_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LED_N_GetValue()           PORTAbits.RA0
#define LED_N_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LED_N_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LED_N_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define LED_N_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set IR aliases
#define IR_TRIS                 TRISAbits.TRISA1
#define IR_LAT                  LATAbits.LATA1
#define IR_PORT                 PORTAbits.RA1
#define IR_ANS                  ANSELAbits.ANSA1
#define IR_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define IR_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define IR_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define IR_GetValue()           PORTAbits.RA1
#define IR_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define IR_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define IR_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define IR_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set LED_1 aliases
#define LED_1_TRIS                 TRISAbits.TRISA2
#define LED_1_LAT                  LATAbits.LATA2
#define LED_1_PORT                 PORTAbits.RA2
#define LED_1_ANS                  ANSELAbits.ANSA2
#define LED_1_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_1_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_1_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_1_GetValue()           PORTAbits.RA2
#define LED_1_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_1_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_1_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_1_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set IR_LED aliases
#define IR_LED_TRIS                 TRISAbits.TRISA3
#define IR_LED_LAT                  LATAbits.LATA3
#define IR_LED_PORT                 PORTAbits.RA3
#define IR_LED_ANS                  ANSELAbits.ANSA3
#define IR_LED_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define IR_LED_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define IR_LED_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define IR_LED_GetValue()           PORTAbits.RA3
#define IR_LED_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define IR_LED_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define IR_LED_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define IR_LED_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set LED_D aliases
#define LED_D_TRIS                 TRISAbits.TRISA6
#define LED_D_LAT                  LATAbits.LATA6
#define LED_D_PORT                 PORTAbits.RA6
#define LED_D_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define LED_D_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define LED_D_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define LED_D_GetValue()           PORTAbits.RA6
#define LED_D_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define LED_D_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)

// get/set LED_A aliases
#define LED_A_TRIS                 TRISAbits.TRISA7
#define LED_A_LAT                  LATAbits.LATA7
#define LED_A_PORT                 PORTAbits.RA7
#define LED_A_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define LED_A_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define LED_A_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define LED_A_GetValue()           PORTAbits.RA7
#define LED_A_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define LED_A_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set LED_S aliases
#define LED_S_TRIS                 TRISBbits.TRISB7
#define LED_S_LAT                  LATBbits.LATB7
#define LED_S_PORT                 PORTBbits.RB7
#define LED_S_WPU                  WPUBbits.WPUB7
#define LED_S_ANS                  ANSELBbits.ANSB7
#define LED_S_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define LED_S_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define LED_S_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define LED_S_GetValue()           PORTBbits.RB7
#define LED_S_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define LED_S_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define LED_S_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define LED_S_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define LED_S_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define LED_S_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/