#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

#include "./libs/lcd.h"

FILE lcd_str = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);

volatile unsigned long seconds = 3590;


void initPort (void);

void initTimer0 (void);

void initINT1 (void);

unsigned char clav (void);


int main(void)
{	
	unsigned char hh = 0;
	unsigned char mm = 0;
	unsigned char ss = 0;
	
	// unsigned char touch = 0;
	
	cli(); // interdit toutes les interruptions
	
	initPort();
	lcd_init();
	initTimer0();
	initINT1();
	
	stdout = &lcd_str;
	
	sei(); // autorise les interruptions
	
    while (1) 
    {
		hh = (seconds / 3600) % 24;
		mm = (seconds / 60) % 60;
		ss = seconds % 60;
		
		position(0, 0);
		printf("TP1");
		
		position(0, 1);
		printf("%02d:%02d:%02d", hh, mm, ss);
		
		
		/* if ((PIND & (1 << PD3)) != 0)
		{
			PORTB ^= 2;
			
			touch = clav();
			
			position (8, 0);
			
			printf("%c", touch);
			
			while((PIND & (1 << PD3)) != 0);
		} */
    }
}


void initPort (void)
{
	DDRB = 0x0F;
	DDRD = 0x00;
	PORTB = 0x0F;
	PORTD = 0x00;
}


void initTimer0(void)
{
	TCCR0 = 0x0C;
	OCR0 = 124;
	TIMSK = 1 << OCIE0 ;
}

ISR (TIMER0_COMP_vect)
{
	static unsigned char nbIT = 0;
	
	nbIT++;
	
	if (nbIT == 250) 
	{
		seconds++;
		
		// PORTB ^= 0x08;
		
		nbIT = 0;
	}
	
	// PORTB ^= 0x04;
}


void initINT1 (void)
{
	MCUCR = 0x0C; // configuration de INT1 en RE
	GICR = 0x80;
}

ISR (INT1_vect)
{
	unsigned char touch = clav();
	
	PORTB ^= 0x01;

	if (touch == '1')
	{
		seconds += 3600;
	}
	else if ((touch == 'F') && (seconds > 3600))
	{
		seconds -= 3600;
	}
	else if (touch == '4')
	{
		seconds += 60;
	}
	else if ((touch == 'E') && (seconds > 60))
	{
		seconds -= 60;
	}
	else if (touch == '7')
	{
		seconds += 1;
	}
	else if ((touch == 'D') && (seconds > 60))
	{
		seconds -= 1;
	}
}


unsigned char clav(void)
{  
	unsigned char t = 0;
	unsigned char tabtouche[16] = {'1', '2', '3', 'F', '4', '5', '6', 'E', '7', '8', '9', 'D', 'A' ,'0' ,'B' ,'C'};		   
	
	t = (PINA >> 1) & 0x0f;  // doit fournir le code DCBA, de 0 à 15 : A MASQUER !! 
	
	 return tabtouche[t];  // retourne le code ASCII de la touche
}