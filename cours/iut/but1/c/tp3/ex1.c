#include <stdio.h>

void bonjour (void);

int main ()
{
	for (int k = 0; k < 50; k++) bonjour();

	return 0;
}

void bonjour (void)
{
	printf("Bonjour !\n");
}
