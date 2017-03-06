/* 
 * File:   7-segment-x-3.h
 * Author: user
 *
 * Created on 6 березня 2017, 23:57
 */

#ifndef _7_SEGMENT_X_3_H_
#define	_7_SEGMENT_X_3_H_

#define _XTAL_FREQ 4000000    // частота генератора - ПОПРАВИТЬ!!!

#define LEDA RC0    // LED segments
#define LEDB RC1
#define LEDC RC2
#define LEDD RC3
#define LEDE RC4
#define LEDF RC5
#define LEDG RA0

#define LED1 RA1    //LED position
#define LED2 RA4
#define LED3 RA5

void convert_to_segment(int);
void draw_to_LED(int);
void init_LED(void);
#endif	/* 7_SEGMENT_X_3_H */
