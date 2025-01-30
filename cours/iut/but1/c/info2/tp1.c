#include <avr/io.h>

int main (void)
{
	DDRB = 0x80;
	DDRC = 0x00;
	DDRD = 0xFC;
	
	PORTB = 0x00;
	PORTD = 0x00;

	unsigned char boolLed = 0;
	unsigned char muteOld = 0;
	unsigned char muteCurrent = 0;
	
	do 
	{
		// Act BTN BP+
		PORTD = (PINB & 0x40) != 0 ? 0xC0 : 0x00; // Allumer les leds PD7-6 si BP+ est appuyé 
		
		// Act BTN BP-
		PORTD = (PINB & 0x20) != 0 ? 0x30 : 0x00; // Allumer les leds PD5-4 si BP+ est appuyé
		
		// Act BTN Mute	
		PORTD = boolLed ? 0x0C : 0x00; // Inverser l'état des leds PD3-2 à chaque nouvel appuie de BP Mute
		
		muteCurrent = PINC & 0x02; // Mettre l'état du bouton dans la variable muteCurrent
		
		if (muteOld < muteCurrent) // Tester s'il y a un front montant
		{		
			boolLed = !boolLed; // Inverser l'état de la led
		}
		
		muteOld = muteCurrent; // Mettre la même valeur de current vers le old
	} 
	while (1);
}
