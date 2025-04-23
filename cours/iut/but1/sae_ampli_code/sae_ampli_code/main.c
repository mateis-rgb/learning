#include <avr/io.h>
#include "include/Afficheur_LCD.h"
#include "include/CAN.h"
#include "include/Timer.h"

#include "config.h"


void AppuiBPP (void);

unsigned char state = 0;


int main(void)
{	
	InitTimer();
	
	DDRB = 0x00;
	DDRC = 1 << RELAIS;
	DDRD = 1 << LED_TEST;
	
	PORTD = 0x00;	
	PORTB = 0x00;
	PORTC = 0x00;
	
    do 
    {
		AppuiBPP();
		
		if (state == 1)
		{
			PORTC = (1 << RELAIS); // On allume le relais
			PORTD = (1 << LED_TEST); // On allume la led test
		}
		else
		{
			PORTD = 0x00; // On eteint le relais
			PORTC = 0x00; // On eteint la led test
		}
	} 
	while (1);
}


void AppuiBPP (void)
{
	unsigned int cpt = 0; // On définit la variable de compteur
	
	if ((PINB & (1 << BTN_PASSE_HAUT)) != 0) // Si le bouton est appuié
	{				
		cpt = 0; // On remet le compteur à 0
						
		while ((PINB & (1 << BTN_PASSE_HAUT)) != 0) // Tant que le bouton est appuié
		{
			Tempo_1ms(); // On effectue une tempo de 1ms
				
			cpt++; // On incrémente le compteur
				
			if (cpt > 3000) // Si le compteur dépasse 3000, ou si le compteur dépasse 3s
			{				
				state = !state;	// On inverse l'état du state global
					
				cpt = 0; // On remet le cpt à 0
				
				break; // En attente de résolution
			}
		}
	}
}

