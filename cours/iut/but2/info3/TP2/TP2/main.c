//Corrigé V2 Interruption Timer0 + interruption INT3

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "lcd.h"
FILE lcd_str = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);

volatile unsigned char isNewCarac = 0;
volatile unsigned char carac = 0;

void initPORT(void)
{
	DDRB = 0x0F; 
	PORTB = 0x0F;
	DDRD &= 0xF7; 
	MCUCR  |= 0x0C; // Config pour la reconnaissance de front montant
}

void initUART0(unsigned int baud)
{
	UBRRH = (unsigned char) (baud >> 8); 						// prédiviseur pour obtenir 19200 bauds à partir de 8 MHz
	UBRRL = (unsigned char) baud;
	UCSRC = (1 << URSEL) | (3 << UCSZ0)	;					// 8 bits, 1 stop bit, mode asynchrone, pas de  parité
	UCSRB = (1 << RXEN) | (1 << RXCIE) | (1 << TXEN); 						// activation en émission et en réception
}

void UART0_Transmit(unsigned char data)
{
	while (!(UCSRA & (1 << UDRE)));

	UDR = data;
}

unsigned char UART0_Receive(void)
{ 
	return (UCSRA & (1 << RXC)) != 0 ? UDR : 0;
}



unsigned char clav(void)
{
	unsigned char t = 0; 
	unsigned char tabtouche [16] = {'1','2','3','F','4','5','6','E','7','8','9','D','A','0','B','C'};
	
	t = (PINA >> 1) & 0x0f;
	
	return tabtouche[t];
}

int main(void)
{    
	unsigned char touche = 0;
	unsigned char recu = 0;
		
	cli();
	
	initPORT();
	initUART0(25);
	lcd_init();
	
	stdout = &lcd_str;
	
	sei();
	
	while (1)
	{   		
		if (GIFR & (1 << INTF1))  // SI appui touche (front montant sur INT1 = PD3 = DA)
		{   
			GIFR = GIFR | (1 << INTF1); // Reset du flag de front montant
			touche = clav();
		
			PORTB &= 0xFE ; //allumer led L1
		
			UART0_Transmit(touche);
		
			position(0, 0);
			printf("Envoi : %c", touche);
		
			PORTB |= 0x01 ; //éteindre  led L1
		}
		
		if (isNewCarac == 1)
		{
			isNewCarac = 0;
			
			switch (carac)
			{
				case '&':
					cls_lcd();
					break;
				
				default:
					position(0, 1);
					printf("Recu : %c", carac);
					break;
			}
		}
	}
}


ISR(USART_RXC_vect)
{
	isNewCarac = 1;
	
	carac = UDR;
}


