#include <avr/io.h>
#include "include/Afficheur_LCD.h"
#include "include/Timer.h"

#include "config.h"


void AppuiBPP (void);

void AppuiBPM (void);

/**
 * state[0] => statut du passe haut
 * state[1] => statut du passe bas
 */
unsigned char state[2] = {0, 0};


int main(void)
{	
	InitTimer();
	InitLCD();
	
	DDRB = 0x00;
	DDRC = (1 << RELAIS_PH) | (1 << RELAIS_PB);
	DDRD = (1 << LED_TEST_BPP) | (1 << LED_TEST_BPM);
	
	PORTD = 0x00;	
	PORTB = 0x00;
	PORTC = 0x00;
	
    do 
    {
		AppuiBPP();
		AppuiBPM();
		
		if (state[0] == 1)
		{
			PORTC = (1 << RELAIS_PH); // On allume le relais du passe haute
			PORTD = (1 << LED_TEST_BPP); // On allume la led test
		
			placeCursor(0, 0);
			print("High pass actif ");
		}
		else if (state[1] == 1)
		{
			PORTC = (1 << RELAIS_PB); // On allume le relais du passe bas
			PORTD = (1 << LED_TEST_BPM); // On allume la led test
		
			placeCursor(0, 0);
			print("Low pass actif  ");
		}
		else
		{
			PORTD = 0x00; // On eteint le relais
			PORTC = 0x00; // On eteint la led test

			placeCursor(0, 0);
			print("  Ampli audio ");

			placeCursor(0, 1);
			print("                ");

			placeCursor(0, 2);
			print("BP+ -> high pass");

			placeCursor(0, 3);
			print("BP- -> low pass ");
		}
	} 
	while (1);
}


void AppuiBPP (void)
{
	unsigned int cpt = 0; // On d�finit la variable de compteur
	
	if ((PINB & (1 << BTN_PASSE_HAUT)) != 0) // Si le bouton est appui�
	{				
		cpt = 0; // On remet le compteur � 0
						
		while ((PINB & (1 << BTN_PASSE_HAUT)) != 0) // Tant que le bouton est appui�
		{
			Tempo_1ms(); // On effectue une tempo de 1ms
				
			cpt++; // On incr�mente le compteur
				
			if (cpt > 3000) // Si le compteur d�passe 3000, ou si le compteur d�passe 3s
			{				
				state[0] = !state[0];	// On inverse l'�tat du state global
					
				cpt = 0; // On remet le cpt � 0
				
				break; // En attente de r�solution
			}
		}
	}
}


void AppuiBPM (void)
{
	unsigned int cpt = 0; // On d�finit la variable de compteur
	
	if ((PINB & (1 << BTN_PASSE_BAS)) != 0) // Si le bouton est appui�
	{				
		cpt = 0; // On remet le compteur � 0
						
		while ((PINB & (1 << BTN_PASSE_BAS)) != 0) // Tant que le bouton est appui�
		{
			Tempo_1ms(); // On effectue une tempo de 1ms
				
			cpt++; // On incr�mente le compteur
				
			if (cpt > 3000) // Si le compteur d�passe 3000, ou si le compteur d�passe 3s
			{				
				state[1] = !state[1];	// On inverse l'�tat du state global
					
				cpt = 0; // On remet le cpt � 0
				
				break; // En attente de r�solution
			}
		}
	}
}

