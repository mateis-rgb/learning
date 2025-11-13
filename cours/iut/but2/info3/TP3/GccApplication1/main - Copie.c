#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "ssc.h"
#include "fat16.h"

volatile unsigned int k = 0;
volatile unsigned char amp = 1;


void init_SPI_CNA (void);

void SPI_transmit (char cData);

void SPI_CNA (unsigned int val, unsigned char voie, unsigned char mult);

void init_Timer2 (void);

void initPort (void);

int main(void)
{	
	cli();
	
	init_SPI_CNA();
		
	init_Timer2();
	
	File * myfile;
	
	unsigned char data[64];
	
	initPort();
	
	if (!(PIND & (1 << PD2)))
	{
		if (InitFat16())
		{
			myfile = fopen_("fileTP30.bin", 'r'); // on ouvre "fileTP30.bin" en lecture, et on l'affecte au pointeur de myfile
			
			fread_(data, 64, 1, myfile); // on lit le flux de my file et on met les données dans le tableau
			
			fclose_(myfile); // on ferme le flux myfile
		}
	}
	sei();
 
    while (1) 
    {
		// code
    }
}


void initPort (void)
{
	DDRA = 0x00;
	DDRB = 0x0F;
	DDRB = 0x00;
	DDRD = 0;
}


void init_SPI_CNA (void)
{
	DDRB |= 0xB0;
	SPCR = 0b01010001;
	SPSR = 1 << SPI2X;
}


void SPI_transmit (char cData)
{
	SPDR = cData;
	
	while (!(SPSR & (1 << SPIF)));
}


void SPI_CNA (unsigned int val, unsigned char voie, unsigned char mult)
{
	unsigned char oct1 = 0x10;
	unsigned char oct2;
	
	PORTB &= ~(1 << PB4);
	
	oct1 |= (val >> 8) & 0x0F;
	
	if (voie == 1) oct1 |= 0x80;
	if (mult == 1) oct1 |= 0x20;
	
	SPI_transmit(oct1);
	
	oct2 = (unsigned char) val & 0x00FF;
	
	SPI_transmit(oct2);
	
	PORTB |= (1 << PB4);
}


void init_Timer2 (void) // FQ = 8MHz
{  	
	TCCR2  = 0x02 | (1 << WGM21);  
	OCR2 = 249;  
	TIMSK = 1 << OCIE2; 
}


ISR (TIMER2_COMP_vect)
{
	if (k == 63) k = 0;
	else 
	{
		SPI_CNA(k * amp, 0, 1);
		
		k++;
	}
}

