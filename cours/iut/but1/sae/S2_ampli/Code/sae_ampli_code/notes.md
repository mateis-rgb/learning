# Id�es : 

procedure bp+:
	Si bp appui�:
		tant que le bouton est app
			Lance tempo

			fin tempo :
				l'�tat global (oux)

main:
	si oux = 1
	

	
# Etapes :
## Etape 1:
Faire une tempo de 3s et la tester sur la led mute.


------------------------
Code: 
int main(void)
{
	InitTimer();
	
	DDRB = 0x80;
	
	PORTB = 0x00;
	
    do 
    {
		PORTB = PORTB ^ (1 << LED_TEST); // Allume / Eteint la led
		
		Tempo_3s();
	} 
	while (1);
}
------------------------

## Etape 2:
On test l'appui du BP Plus, si le bp est maintenu 3s, on change l'�tat du state, qui allume ou �tein la led PD7 (ON si le state = 1, OFF sinon)

PB : Si le bp est maintenu 6s, �a rechange le state, et �a ind�finiment


------------------------
Code :
unsigned char state = 0;

int main(void)
{	
	InitTimer();
	
	DDRD = 0x80;
	DDRB = 0x80;
	PORTD = 0x00;	
	PORTB = 0x00;
	
    do 
    {
		AppuiBPP();
		
		if (state == 1)
		{
			PORTD = (1 << PD7);
		}
		else
		{
			PORTD = 0x00;
		}
	} 
	while (1);
}


void AppuiBPP (void)
{
	unsigned int cpt = 0;
	
	if ((PINB & (1 << PB6)) != 0)
	{				
		cpt = 0;
						
		while ((PINB & (1 << PB6)) != 0)
		{
			Tempo_1ms();
				
			cpt++;
				
			if (cpt > 3000) 
			{
				PORTB = 0x00;
				
				state = !state;	
					
				cpt = 0;
				
				break;
			}
		}
	}
}
------------------------

# Etape 3
On utilise l'afficheur LCD pour dire si le passe haut est actif

------------------------

Code :
int main(void)
{	
	InitTimer();
	InitLCD();
	
	DDRB = 0x00;
	DDRC = 1 << RELAIS;
	DDRD = 1 << LED_TEST;
	
	PORTD = 0x00;	
	PORTB = 0x00;
	PORTC = 0x00;
	
    do 
    {
		AppuiBPP();
		
		if (state == 1)
		{
			PORTC = (1 << RELAIS); // On allume le relais
			PORTD = (1 << LED_TEST); // On allume la led test
		
			placeCursor(0, 0);
			print("Passe haut actif");
		}
		else
		{
			PORTD = 0x00; // On eteint le relais
			PORTC = 0x00; // On eteint la led test

			placeCursor(0, 0);
			print("Ampli audio");

			placeCursor(0, 1);
			print("BP + -> passe haut");

			placeCursor(0, 2);
			print("BP - -> passe bas");
		}
	} 
	while (1);
}
------------------------
