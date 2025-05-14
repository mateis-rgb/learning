/*   Afficheur_LCD.c       */ 

#include <avr/io.h>

#define F_CPU 8000000UL

#include <util/delay.h>

#include "../include/Afficheur_LCD.h"

void InitUSART(void)
{	
	UBRRH = 0x00; UBRRL = 25; // vitesse de transmission 19200 bits/sec
	UCSRB = 1 << TXEN;        // autorise transmission
	UCSRC = 0x86;             // 8 bits, un stop bit, pas de bit de parité
}

char putCharToLCD(char codeASCII)
{ 
	while (!(UCSRA &(1<<UDRE))); // attente transmission précédente terminéee
  
	  UDR = codeASCII;			   // envoi du code ASCII à l’USART
 
	  return(codeASCII);		   // retourne le caractère envoyé si besoin
}

void InitLCD(void)
{	
	InitUSART();				//Initialisation du port série de l’ATMEGA32
	
	putCharToLCD(0xA0);
	
	_delay_ms(50);
}


void placeCursor (char x, char y)
{
	putCharToLCD(0xA1); // Mode placement du curseur
	
	putCharToLCD(x); // Position X
	putCharToLCD(y); // Position Y
	
	_delay_ms(20);
}

void print (unsigned char message[])
{
	unsigned char length = 0;
	
	putCharToLCD(0xA2);
	
	while (message[length] != '\0')
	{
		putCharToLCD(message[length]);

		length++;
	}
	
	putCharToLCD(0x00);
	
	_delay_ms(20);
}