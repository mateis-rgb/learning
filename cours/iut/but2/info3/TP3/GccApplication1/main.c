#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "ssc.h"    // config bas niveau
#include "fat16.h"
#include "lcd.h"


FILE lcd_str = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);


void init_SPI_CNA(void);

void SPI_transmit(char cData);

void SPI_CNA(unsigned int val, unsigned char voie, unsigned char mult);

void InitTimer2(void);

void initPort(void);

unsigned char clav(void);


volatile unsigned char k = 0;
volatile unsigned char ampli = 0;
volatile unsigned char data[64] = {};


int main (void)
{
	stdout = &lcd_str;
	
	File * myfile;
	
	initPort();    // configurer et éteindre les Leds L4 à L1, sur PB3..PB0 (voir TP1)
	
	if (!(PIND & (1<<PD2))){    // si carte SD présente
		if ( InitFat16())    // si le système peut être initialisé
		{
			myfile = fopen_("fileTP30.bin", 'r'); // on ouvre "fileTP30.bin" en lecture, et on l'affecte au pointeur de myfile
			
			fread_(data, 64, 1, myfile); // on lit le flux de my file et on met les données dans le tableau
			
			fclose_(myfile); // on ferme le flux myfile
			
			PORTB |= (1 << PB0) ;    // allumer Led L1
		}
	}
	
	cli();
	
	init_SPI_CNA();
	InitTimer2();
	lcd_init();
	
	sei();
	
	while (1) {
		
		if(PIND & (1 << PD3))    //detection de l’appuis d’une touche
		{
			while(PIND&(1<<PD3)); //attente touche relachée
			
			if(clav() == '1')
			{
				cli();
			
				if(ampli != 16) ampli += 1;
		
				sei();
				
			}
			if(clav() == 'F')
			{
				cli();
		
				if(ampli != 0) ampli -= 1 ;
		
				sei();
			}
			
		}
		
		position(0, 0);
		printf("Amplification: ");
		
		position(0, 1);
		printf("%02d",ampli);
	}
	
	return (0);
}

void initPort(void){
	DDRB=0x0F;
	PORTB=0x0F;
	DDRD=0;
}

void init_SPI_CNA(void)
{
	DDRB |= 0xB0 ;
	SPCR = 0b01010001 ; // MSB first, maitre, f/8, front montant
	SPSR = 1 << SPI2X ;
}

void SPI_transmit(char cData)
{
	SPDR = cData;                    //depose l'octet
	
	while(!(SPSR & (1 << SPIF)));        //attend la fin de transmission
}

void SPI_CNA(unsigned int val, unsigned char voie, unsigned char mult)
{
	unsigned char oct1;
	unsigned char oct2;
	
	PORTB &= ~(1<<PB4);//Csna a 0
	
	oct1 = ((val >> 8) & 0x0F) | 0x10 ;    //appliquer masque
	
	if (voie==1) oct1 |= 0x80 ;    //définir la voie
	if (mult==1) oct1 | 0x20 ;
	
	SPI_transmit(oct1) ;

	oct2 = (unsigned char) val ;

	SPI_transmit(oct2) ;

	PORTB |= (1<<PB4) ; //Csna a 1

}

ISR (TIMER2_COMP_vect)
{
	unsigned int valeurs = (data[k] * ampli);

	SPI_CNA(valeurs, 0, 0);
	
	k++;
	k %= 64;
	
	PORTB ^= (1<<PB3);
	
}

void InitTimer2(void) // FQ = 8MHz
{    
	TCCR2 = 0x02 | (1 << WGM21); //mode CTC et f/8
	OCR2 = 249;    //T= 8*(1+249)/(8*10^6)=250µs
	TIMSK = 1<<OCIE2;    //autorise l’interruption
}

unsigned char clav(void)
{
	unsigned char t = 0;
	unsigned char tabtouche[16] = {'1','2','3','F','4','5','6','E','7','8','9','D','A','0','C', 'D'}; 
	
	t = (PINA >> 1) & 0x0F;
	
	return tabtouche[t];
}