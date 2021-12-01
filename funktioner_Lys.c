/*
 * Forlys.c
 *
 * Created: 30-11-2021 09:13:11
 * Author : sandr
 */ 

#include <avr/io.h>
#include "Funktioner_lys.h"

//Sæt alle PORTE's ben3 til at være udgange
DDRE |= 0b00010000;

// Clear
PORTE &= 0b00000000;

//Udkast
TCCR3A = 0b10000011; // Timer 3 sættes til mode 3 (PWM 10-bit) + top på 0x03FF dvs 1023 + ikke fast PWM
					 // Clear OC3B/C when up-counting, set OC3B/C when down-counting
					 // OCR3A styrer PE ben3
TCCR3B = 0b00000001; // Clock prescaler sættes til 1 = no prescaling, så lyset blinker så hurtigt, at vi ikke kan se det

//OSCR3A er sat til fuldt lys
OCR3A = 1023;


turnOnFrontlight(int frontLight)
{
	
}

turnOffFrontLight (int frontLight)
{
	
}

turnOnBackLight(int rearLight)
{
	
}

turnOffBackLight(int rearLight)
{
	
}

setIntensity(int intensity)
{
	
}


