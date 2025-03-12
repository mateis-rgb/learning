#define F_CPU 8000000UL

#include <avr/io.h>

#define PD7_On PORTD |= (1 << PD7)
#define PD7_Off PORTD &= ~(1 << PD7)

/**
 * @brief Fais une tempo en fonction t le temps (16us * t)
 * 
 * @param { unsigned char } t
 */
void tempo (unsigned char t);

int main(void)
{	
	unsigned char boolLed = 0;
	unsigned char muteOld = 0;
	unsigned char muteCurrent = 0;
	
	// CONFIG & INIT
	DDRB = 0x80;
	DDRC = 0x00;
	DDRD = 0b11000000; // Led en sortie
	
	TCNT2 = 0x00; // RAZ CPT 2 
	TCCR2 = 0b01101010; // Config PWM && Prescaler
	OCR2 = 0x04; // Valeur de début
	
	PORTB = 0x00;
	PORTD = 0x00;
	
	do
	{	
		// Act BTN Mute	
		if (boolLed == 1) 
		{
			PORTB = (1 << PB7); // Allumer la led MUTE
			PORTD = PORTD | (1 << PD6);
		}
		else
		{
			PORTB = 0; // Eteindre la led MUTE
			PORTD = PORTD & ~(1 << PD6);
		}
		
		muteCurrent = PINC & (1 << PC1); // Mettre l'état du bouton dans la variable muteCurrent
		
		if (muteOld < muteCurrent) // Tester s'il y a un front montant
		{		
			boolLed = !boolLed; // Inverser l'état de la led
		}
		
		muteOld = muteCurrent; // Mettre la même valeur de current vers le old
		
		// Gestion de la vitesse
		if ((PINB & (1 << PB6)) != 0) // S'il y a un appui de BP+
		{		
			if (OCR2 < 254) // Si on n'est pas en butée
			{
				OCR2 += 0x0A; // On augmente la vitesse
			}
			
			while ((PINB & (1 << PB6)) != 0); // On attends le relachement
		}
		
		if ((PINB & (1 << PB5)) != 0) // S'il y a un appui de BP-
		{				
			OCR2 -= OCR2 > 10 ? 0x0A : 0; // Si on n'est pas en butée on diminue la vitesse
		
			while ((PINB & (1 << PB5)) != 0); // On attends le relachement
		}	
	}
	while(1);
	
	return 0;
}


void tempo (unsigned char t)
{
	TCNT2 = 0; // RAZ CPT 2 
	OCR2 = t - 1; // Mise à la limite du comparateur t-1
	TIFR = 1 << OCF0; // RAZ du flag de comparateur
	
	while ((TIFR & (1 << OCF2)) == 0); // On attend la fin du compteur
}
