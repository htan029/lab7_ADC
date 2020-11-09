/*	Author: Heng Tan
 *  Partner(s) Name: 
 *	Lab Section: 024
 *	Assignment: Lab 7  Exercise 2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *  Demo Link: https://youtu.be/01x-fAY_-nk
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRB = 0xFF; PORTB = 0x00;
    DDRD = 0xFF; PORTD = 0x00;

    unsigned char tmpB = 0;
    unsigned char tmpD = 0;
    unsigned short x;

    /* Insert your solution below */
    ADC_init();
    while (1) {
        x = ADC;
        tmpB = (char)x;
        tmpD = (char)(x >> 8) & 0x03;
        PORTB = tmpB;
        PORTD = tmpD;
    }
    return 1;
}
