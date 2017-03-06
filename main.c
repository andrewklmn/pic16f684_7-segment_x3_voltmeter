/*
 * File:   main.c
 * Author: user
 *
 * Created on 6 березня 2017, 22:35
 */
#define _XTAL_FREQ 4000000 

#include <xc.h>
#include <pic16f684.h>
#include "7-segment-x-3.h"


#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select bit (MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Detect (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)

#define INPUT RA2   //ADC input 


unsigned int u;
int i = 0;

void ADC_Init()
{
  ADCON0 = 0x10000001;               //Turn ON ADC and Clock Selection
  ADCON1 = 0b001;
}

unsigned int ADC_Read(unsigned char channel)
{
    if(channel > 7) return 0;    //Channel range is 0 ~ 7
        
    ADCON0 = 0b10000001;         //Clearing channel selection bits
    ADCON0 |= channel<<2;        //Setting channel selection bits
    __delay_ms(2);               //Acquisition time to charge hold capacitor
    GO_nDONE = 1;                //Initializes A/D conversion
    while(GO_nDONE) NOP();             //Waiting for conversion to complete
    return ((ADRESH<<8)+ADRESL); //Return result
}



void main(void) {
    
        
    TRISA = 0b00000100;           //Port A as INPUT to AN2 RA2
    TRISC = 0b00000000;           //Port C is output to all
    ANSEL = 0b00000100;           // AN2 - enabled
    ADC_Init();                   //Initialize ADC
    
    init_LED();                   // тестирование ЛЕД на полсекунды 888  
    
    while(1){
        // Считываем ADC на втором канале и отображаем сразу
        draw_to_LED(ADC_Read(2));
    };
    return;
};