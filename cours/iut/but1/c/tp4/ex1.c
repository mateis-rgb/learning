#include <stdio.h>

int main (void)
{
	// On ajoute unsigned pour que la plage des valeurs possibles soient entre 0 et 255
	unsigned char i = 127;
	unsigned char j = i + 1;
	
	printf("%d + 1 = %d", i, j);

	return 0;
}
