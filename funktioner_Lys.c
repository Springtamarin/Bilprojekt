/*
 * Forlys.c
 *
 * Created: 30-11-2021 09:13:11
 * Author : sandr
 */ 

#include <avr/io.h>
#include "Funktioner_lys.h"

//Forlys
//Sæt alle PORTE's ben3 til at være udgange
DDRE |= 0b00010000;
// Clear
PORTE &= 0b11101111;

//Baglys:
//Sæt alle PORTE's ben4 til at være udgange
DDRE |= 0b00001000;
// Clear
PORTE &= 0b11110111;

//Udkast
TCCR3A = 0b10100011; // Timer 3 sættes til mode 3 (PWM 10-bit) + top på 0x03FF dvs 1023 + ikke fast PWM
					 // Clear OC3A when up-counting, set OC3A when down-counting
					 // Clear OC3B when up-counting, set OC3B when down-counting
TCCR3B = 0b00000001; // Clock prescaler sættes til 1 = no prescaling, så lyset blinker så hurtigt, at vi ikke kan se det blinker

//A-system til forlys. OSCR3A styrer PE ben3, og er sat til fuldt lys
OCR3A = 1023;


//B system til baglys. OSCR3B styrer PE ben4 er sat til fuldt lys
OCR3B = 1023;

//OSCR3B er sat til 50% duty cycle
OCR3B = 511;



turnOnFrontlight(int frontLight)
{
	if (frontLight==1)
	{
		xxx=
	}
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


