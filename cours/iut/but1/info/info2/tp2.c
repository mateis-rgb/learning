#include <avr/io.h>
#include <stdio.h>

#define F_CPU 8000000

#include <util/delay.h>


/**
 * @brief Lit l'état du bouton SET
 *
 * @returns { unsigned char }
 */
unsigned char lectSet (void);

/**
 * @brief Lit l'état du capteur Intru
 *
 * @returns { unsigned char }
 */
unsigned char lectIntru (void);

/**
 * @brief Commande l'état de la LED V.
 * 
 * @param { unsigned char } onLedV
 */
void commanderLedV(unsigned char onLedV);

/**
 * @brief Commande l'état de la LED R.
 * 
 * @param { unsigned char } onLedV
 */
void commanderLedR(unsigned char onLedR);

/**
 * @brief Commande le buzzer de l'alarme
 * 
 * @param { unsigned char } onLedV
 */
void bipperAlarm();


int main (void)
{
	/************************************************************************/
	/* INIT                                                                 */
	/************************************************************************/
	DDRA = 0x80;
	DDRC = 0xC1;

	PORTA = 0x80;
	PORTC = 0xC0;
	
	unsigned char BTN_SET = 0;
	unsigned char CURRENT_HAS_INTRU = 0;
	unsigned char BEFORE_HAS_INTRU = 0;
	
	/************************************************************************/
	/* PROGRAMME PRINCIPAL                                                  */
	/************************************************************************/
	do // FAIRE
	{
		PORTC &= ~(1 << PC6); // On allume la led J de debug
		
		BTN_SET = lectSet(); // On lit le niveau du bouton d'allumage
		CURRENT_HAS_INTRU = lectIntru(); // On lit le niveau du capteur de mvt
	
		if (BTN_SET) // Si le bouton est à un NL 1
		{			
			if (BEFORE_HAS_INTRU < CURRENT_HAS_INTRU) // S'il y a un front montant sur le capteur de mvt
			{
				commanderLedR(1); // On fait clignotter la led R
				
				bipperAlarm(); // On fait bipper le buzzer
			}
			else
			{
				commanderLedR(0); // On eteint la led R sinon
			}
			
			BEFORE_HAS_INTRU = CURRENT_HAS_INTRU; // On actualise les fronts
		}
		
		commanderLedV(BTN_SET);	// On allume la led V si le bouton d'allumage est à NL 1 sinon on l'eteint
		
		PORTC |= (1 << PC6); // On eteint la led J de debug
	}
	while (1); // En boucle
}


unsigned char lectSet (void)
{
	return (PINA & (1 << PA5)) == 0; // On retourne 1 si la condition est vrai sinon 0
}


unsigned char lectIntru (void)
{
	return (PINA & (1 << PA6)) != 0; // On retourne 1 si la condition est vrai sinon 0
} 


void commanderLedV(unsigned char onLedV)
{
	if (onLedV) // Si onLedV est à 1
	{
		PORTA &= ~(1 << PA7); // On allume la led
	}
	else // Sinon
	{
		PORTA |= (1 << PA7); // On eteint la led
	}
}


void commanderLedR(unsigned char onLedR)
{
	if (onLedR) // Si onLedR est à 1
	{
		PORTC &= ~(1 << PC7); // On allume la led
		
		_delay_ms(100); // On attends 100ms
		
		PORTC |= (1 << PC7); // On eteint la led
		
		_delay_ms(100); // On attends 100ms
	}
	else // Sinon
	{
		PORTC |= (1 << PC7); // On eteint la led
	}
}

void bipperAlarm()
{
	PORTC |= (1 << PC0); // On fait bipper le buzzer
	
	_delay_ms(1); // On attends 1ms
	
	PORTC &= ~(1 << PC0); // On eteint le buzzer
	
	_delay_ms(1); // On attends 1ms
}
