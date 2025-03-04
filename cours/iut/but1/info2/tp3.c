#include <avr/io.h>

void InitTimer0 (void);
void Tempo_xx (void);
void Tempo_1s (void);

int main(void)
{
	DDRB = 0x80;
	
	PORTB = 0x00;
	
    do
	{
		Tempo_1s();
		
		PORTB = PORTB ^ (1 << PB7);
	}
	while (1);
}

void InitTimer0 (void)
{
	TCCR0 = 0x0D;
	TCNT0 = 0;
	OCR0 = 195;
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
	
	for (k = 0; k < 4; k++) Tempo_xx();
}
