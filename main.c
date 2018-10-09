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
#include "adc_pic16.h"

#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select bit (MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Detect (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode is disabled)
#pragma config FCMEN = OFF      //  Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)

#define INPUT RA2   //ADC input 


unsigned int u;
int i = 0;


void main(void) {
    
        
    TRISA = 0b00000100;           //Port A as INPUT to AN2 RA2
    TRISC = 0b00000000;           //Port C is output to all
    ANSEL = 0b00000100;           // AN2 - enabled
    
    ADC_Init();                   //Initialize ADC
    
    init_LED();                   // тестирование ЛЕД на полсекунды 888  
    
    while(1){
        // Считываем ADC на втором канале и отображаем сразу
        draw_to_LED(ADC_Read(2)/2.048);
    };
    return;
};