#include <xc.h>
#include "7-segment-x-3.h"


void convert_to_segment( int value ){
    switch(value){
        case -2:    //пустое значение
            LEDA = 0; 
            LEDB = 0;
            LEDC = 0;
            LEDD = 0;
            LEDE = 0;
            LEDF = 0;
            LEDG = 0;
            break;
        case -1:    //символ минуса
            LEDA = 0; 
            LEDB = 0;
            LEDC = 0;
            LEDD = 0;
            LEDE = 0;
            LEDF = 0;
            LEDG = 1;
            break;
        case 0:    //символ минуса
            LEDA = 1; 
            LEDB = 1;
            LEDC = 1;
            LEDD = 1;
            LEDE = 1;
            LEDF = 1;
            LEDG = 0;
            break;
        case 1:    
            LEDA = 0; 
            LEDB = 1;
            LEDC = 1;
            LEDD = 0;
            LEDE = 0;
            LEDF = 0;
            LEDG = 0;
            break;
        case 2:    
            LEDA = 1; 
            LEDB = 1;
            LEDC = 0;
            LEDD = 1;
            LEDE = 1;
            LEDF = 0;
            LEDG = 1;
            break;
        case 3:    
            LEDA = 1; 
            LEDB = 1;
            LEDC = 1;
            LEDD = 1;
            LEDE = 0;
            LEDF = 0;
            LEDG = 1;
            break;
        case 4:    
            LEDA = 0; 
            LEDB = 1;
            LEDC = 1;
            LEDD = 0;
            LEDE = 0;
            LEDF = 1;
            LEDG = 1;
            break;
        case 5:    
            LEDA = 1; 
            LEDB = 0;
            LEDC = 1;
            LEDD = 1;
            LEDE = 0;
            LEDF = 1;
            LEDG = 1;
            break;
        case 6:    
            LEDA = 1; 
            LEDB = 0;
            LEDC = 1;
            LEDD = 1;
            LEDE = 1;
            LEDF = 1;
            LEDG = 1;
            break;
        case 7:    
            LEDA = 1; 
            LEDB = 1;
            LEDC = 1;
            LEDD = 0;
            LEDE = 0;
            LEDF = 0;
            LEDG = 0;
            break;
        case 8:    
            LEDA = 1; 
            LEDB = 1;
            LEDC = 1;
            LEDD = 1;
            LEDE = 1;
            LEDF = 1;
            LEDG = 1;
            break;
        case 9:    
            LEDA = 1; 
            LEDB = 1;
            LEDC = 1;
            LEDD = 1;
            LEDE = 0;
            LEDF = 1;
            LEDG = 1;
            break;
        default:    //ошибочный символ
            LEDA = 1; 
            LEDB = 0;
            LEDC = 0;
            LEDD = 1;
            LEDE = 1;
            LEDF = 1;
            LEDG = 1;
            break;
    };
};

void draw_to_LED(int i){
    int d = i/100;
    convert_to_segment(d);
    LED1 = 0;
    __delay_ms(10);
    LED1 = 1;    

    d = i/10 - i/100*10;
    convert_to_segment(d);
    LED2 = 0;
    __delay_ms(10);
    LED2 = 1;    

    d = i - i/10*10;
    convert_to_segment(d);
    LED3 = 0;
    __delay_ms(10);
    LED3 = 1;    
};

void init_LED(){
    LEDA = 1; // засвечиваем все сегменты на старте
    LEDB = 1;
    LEDC = 1;
    LEDD = 1;
    LEDE = 1;
    LEDF = 1;
    LEDG = 1;
    
    LED1 = 0; // включаем все знаки
    LED2 = 0;
    LED3 = 0;
    
    __delay_ms(500);
    
    LED1 = 1; // выключаем все знаки
    LED2 = 1;
    LED3 = 1;
};