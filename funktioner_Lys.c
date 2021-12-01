/*
 * Forlys.c
 *
 * Created: 30-11-2021 09:13:11
 * Author : sandr
 */ 

#include <avr/io.h>
#include "Funktioner_lys.h"

// Sæt alle PORTE's ben til at være udgange
DDRE = 0xFF;
// Clear
PORTE = 0;

// Timer 3 sættes til mode 3 (PWM 10-bit)
// Top på 0x03FF dvs 1023
// Clock prescaler sættes til 1 = no prescaling
// Hvad styer OC3B? - ikke fast PWM //HENNING??
// Clear OC3B/C when up-counting, set OC3B/C when down-counting


TCCR3A = 0b10100011;  //TIL HENNING??
TCCR3B = 0b00000001; 

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


