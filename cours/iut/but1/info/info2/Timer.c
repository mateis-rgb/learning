#include <avr/io.h>

void InitTimer (void)
{
	TCCR0 = 0x0B;
	TCNT0 = 0;
	OCR0 = 124;
}

void Attendre1ms (void)
{
	TIFR = 1 << OCF0;
	TCNT0 = 0;
	
	while ((TIFR & (1 << OCF0)) == 0);
}
