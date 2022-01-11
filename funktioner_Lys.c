/*
* Forlys.c
*
* Created: 30-11-2021 09:13:11
* Author : sandr
*/

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

void Init_lys (void)
{
	//Forlys
	//Sæt alle PORTE's ben3 til at være udgange
	DDRE |= ~0b00010000;
	// Clear
	PORTE &= 0b11101111;

	//Baglys:
	//Sæt alle PORTE's ben4 til at være udgange
	DDRE |= ~0b00001000;
	// Clear
	PORTE &= 0b11110111;

	TCCR3A = 0b10100011; // Timer 3 sættes til mode 3 (PWM 10-bit) + top på 0x03FF dvs 1023 + ikke fast PWM
	// Clear OC3A when up-counting, set OC3A when down-counting
	// Clear OC3B when up-counting, set OC3B when down-counting
	TCCR3B = 0b00000001; // Clock prescaler sættes til 1 = no prescaling, så lyset blinker så hurtigt, at vi ikke kan se det blinker

}

void turnOnFrontlight(void)
{
	//A-system til forlys. OSCR3A styrer PE ben3, og er sat til 90% lys (0,9*1023)
	OCR3A = 920;
}

void turnOffFrontLight (void)
{
	OCR3A = 0;
}

void turnOnBackLight_Alm(void)
{
	//B-system til baglys. OSCR3B styrer PE ben4, og er sat til 15% duty cycle
	OCR3B = 155;

}

void turnOnBackLight_Stop(void)
{
	//B system til baglys. OSCR3B styrer PE ben4 er sat til 90% lys (0,9*1023)
	OCR3B = 920;
}

void turnOffBackLight(void)
{
	OCR3B = 0;
}



//Test i main
int main(void)
{
	Init_lys();
	turnOnFrontlight();
	_delay_ms(5000);	turnOffFrontLight();
	turnOnBackLight_Alm();
	_delay_ms(2000);
	turnOnBackLight_Stop();
	_delay_ms(5000);
	turnOffBackLight();
	turnOnFrontlight();
	_delay_ms(5000);	turnOffFrontLight();
	
	while (1)
	{
	}
	
	
	
}




