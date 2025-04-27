#include <avr/io.h>

#define CHENILLARD 4

/**
 * @brief Initialise le Timer 0.
 *
 */
void InitTimer0 (void);

/**
 * @brief Fais une tempo de 25,088ms.
 *
 */
void Tempo_xx (void);

/**
 * @brief Fais une tempo de environ 1s.
 *
 */
void Tempo_1s (void);

/**
 * @brief Fais une tempo en fonction de la speed (40 / (1 + speed))
 * 
 * @param { unsigned char } speed
 */
void Tempo_speed (unsigned char speed);

/**
 * @brief Renvoie un octet dont un des bits spécifié en paramètre est à 1.
 * 
 * @param { unsigned char } n
 * 
 * @returns
 */
unsigned char MUnBit (unsigned char n);

/**
 * @brief Attend l'appui du bouton BP+.
 *
 */
void attBP_BPP (void);

/**
 * @brief Attend l'appui du bouton BP-.
 *
 * @returns
 */
unsigned char detectBPM (void);

/**
 * @brief Attend l'appui du bouton BP+.
 *
 */
unsigned char AppuiBPP(void);

int main(void)
{
	unsigned char current_led = 0;
	
	unsigned char values_arr[6] = { 0b10000100, 0b01001000, 0b00110000, 0b00110000, 0b01001000, 0b10000100 }; // Motifs du chenillard 4
	
	unsigned char bpm_current_state = 0;
	unsigned char bpm_previous_state = 0;
	
	unsigned char bpp_state = 0; // 0 si le chanillard est lance et 1 si le chenillard est fige
	
	unsigned char speed = 0; // defini la vitesse du chenillard en fonction du nombre d'appui
	
	
	switch (CHENILLARD)
	{
		case 1: 
			DDRB = 0x00;
			DDRD = 0xFC;
	 
			PORTD = 0x00;
	 
			InitTimer0();
				 
			do
			{				
				// On attends l'appui du bouton
				attBP_BPP();
		
				// Si on dépasse la dernière led, on remet le compteur de la led courrante à 0
				if (current_led + PD1 == 7) 
				{
					current_led = 0;
				}
		
				// On allume uniquement la led courrante 
				PORTD = MUnBit(current_led + PD1);
				
				Tempo_1s(); // On attends 1 sec
				
				PORTD = 0;
		
				// On incrémente le compteur de la led courrante
				current_led++;
			}
			while (1);
		
			break;
		
		case 2: 
			DDRB = 0x00;
			DDRD = 0xFC;
	 
			PORTD = 0x00;
	 
			InitTimer0();
				 
			// On attends l'appui du bouton
			attBP_BPP();
				 
			do
			{						
				// Si on dépasse la dernière led, on remet le compteur de la led courrante à 0
				if (current_led + PD1 == 7) 
				{
					current_led = 0;
				}
		
				// On allume uniquement la led courrante 
				PORTD = MUnBit(current_led + PD1);
				
				Tempo_1s(); 
				
				// On incrémente le compteur de la led courrante
				current_led++;
			}
			while (1);
		
			break;
			
		case 3:
			DDRB = 0x00;
			DDRD = 0xFC;
		
			PORTD = 0x00;
		
			InitTimer0();
				
			do
			{
				if (detectBPM() == 1) // BP- et BP+
				{
					for (current_led = 0; current_led < 6; current_led++)
					{
						// On allume ttes les leds sauf la led courrante 
						PORTD = ~MUnBit(current_led + PD1);
				
						Tempo_1s(); 
					}
				}	
				else // BP+ et non BP-
				{
					for (current_led = 0; current_led < 6; current_led++)
					{
						// On allume uniquement la led courrante 
						PORTD = MUnBit(current_led + PD1);
				
						Tempo_1s(); 
					}
				}
				
				PORTD = 0;
			}
			while (1);
		
			break;
			
		case 4:
			DDRB = 0x00;
			DDRD = 0xFC;
		
			PORTD = 0x00;
		
			InitTimer0();
						
			attBP_BPP();			
			
			do
			{	
				// Si BP+ est appuié alors on fige l'affichage sinon on continue l'affichage
				if (AppuiBPP()) bpp_state = !bpp_state;
				
				if (bpp_state)
				{	
					// On définit les états du bouton BP-
					bpm_previous_state = 0;	
					bpm_current_state = PINB & (1 << PB5);

					// On boucle sur 6 tours de leds
					if (current_led == 6) current_led = 0;	

					// On va chercher l'affichage correspondant dans le tableau d'affichage
					PORTD = values_arr[current_led];

					// On appel la tempo en fonction de la vitesse
					Tempo_speed(speed); 

					// S'il y a un front montant de BP- alors on réduit la vitesse
					if (bpm_current_state > bpm_previous_state)
					{
						speed++;	
					}
			
					// On incrémente le compteur de la led courrante
					current_led++;
				}
			}
			while (1);
		
			break;
	}
}


unsigned char MUnBit (unsigned char n)
{
	return 1 << (n + 1); // Retourne 1 décalé de n
}


void attBP_BPP (void)
{
	while ((PINB & (1 << PB6)) != 0);
	while ((PINB & (1 << PB6)) == 0);
}


unsigned char AppuiBPP (void)
{
	if (PINB & (1 << PB6)) 
	{
		while (PINB & (1 << PB6));
		
		return 1;
	}
	
	return 0;
}


unsigned char detectBPM (void)
{
	unsigned char current_state = 0;
	unsigned char previous_state = PINB & (1 << PB5);
	
	// On attends l'appui du bouton
	attBP_BPP();
	
	current_state = PINB & (1 << PB5);
	
	return previous_state != current_state;
}


void InitTimer0 (void)
{
	TCCR0 = 0x0D;
	TCNT0 = 0;
	OCR0 = 194;
}


void Tempo_xx (void)
{
	TIFR = 1 << OCF0;
	TCNT0 = 0;
	
	while ((TIFR & (1 << OCF0)) == 0);
}


void Tempo_1s (void)
{
	unsigned char k = 0;
	
	
	for (k = 0; k < 40 ; k++) Tempo_xx();
}


void Tempo_speed (unsigned char speed)
{
	unsigned char k = 0;
	
	unsigned char local_speed = 1 + speed;
	
	for (k = 0; k < (40 / local_speed) ; k++) Tempo_xx();
}
