/*
 * TP5.c
 *
 * Created: 27/03/2025 14:48:00
 * Author : Etudiant-admin
 */ 

#include <avr/io.h>
#include <stdio.h>

#define F_CPU 8000000UL

#include <util/delay.h>

#include "Afficheur_LCD.h"
#include "Timer.h"

FILE lcd_connexion = FDEV_SETUP_STREAM(sendOneChar, NULL, _FDEV_SETUP_WRITE);

#define BPMENU (1 << PB2)
#define LED (1 << PB7)

int main(void)
{
	int cpt = 0;
	int printable[2] = {0, 0};
	
	stdout = &lcd_connexion;

	DDRB = LED;

	InitLCD();
	InitTimer();
	
	placeCursor(0, 0);
	print("Appuyez sur Menu");
	
	do
	{
		cpt = 0;
		
		if ((PINB & BPMENU) != 0)
		{
			do
			{
				Attendre1ms();
				
				if (cpt%500 == 0) PORTB ^= LED;
				
				cpt++;
			}
			while ((PINB & BPMENU) != 0);
			
			PORTB = 0x00;
			
			printable[0] = cpt / 1000;
		}
		
		if (printable[0] > printable[1] && printable[0] < 10)
		{
			printable[1] = printable[0];
		}
		
		if (printable[1] > 0)
		{
			placeCursor(0, 1);
			
			printf("%cAct: %d  Best: %d%c", 0xA2, printable[0], printable[1], 0x00);
		}
	}	
	while (1);
}

