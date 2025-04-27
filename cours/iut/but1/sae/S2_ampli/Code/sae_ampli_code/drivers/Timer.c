#include <avr/io.h>

#include "../include/Timer.h"

void InitTimer (void)
{
	TCCR0 = 0x0B;
	TCNT0 = 0;
	OCR0 = 124;
}


void Tempo_1ms (void)
{
	TIFR = 1 << OCF0;
	
	while ((TIFR & (1 << OCF0)) == 0);
}

