#include <stdio.h>

int main (void)
{
	int Tab[10];
	int k = -25;
	int cpt = 0;

	for (k = -25; k <= -16; k++)
	{
		Tab[cpt] = k;

		cpt++;
	}

	for (k = 0; k < 10; k++)
	{
		printf("Tab[%d] = %d\n", k, Tab[k]);
	}

	return 0;
}
