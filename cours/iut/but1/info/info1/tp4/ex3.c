#include <stdio.h>

int main (void)
{
	for (unsigned char k = 33; k <= 128; k++) printf("Le code ASCII %d correspond au caractere %c\n", k, k);

	return 0;
}
