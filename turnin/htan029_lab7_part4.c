/*	Author: Heng Tan
 *  Partner(s) Name: 
 *	Lab Section: 024
 *	Assignment: Lab 7  Exercise 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *  Demo Link: https://youtu.be/aiZ-Nkay7gg
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

    unsigned short max = 0x00F8;
    unsigned short x;
    unsigned char arr[8] = {0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF};
    unsigned char cnt = 0;

    /* Insert your solution below */
    ADC_init();
    while (1) {
        x = ADC;
        cnt = x/(max/8);
        PORTB = arr[cnt];
    }
    return 1;
}

