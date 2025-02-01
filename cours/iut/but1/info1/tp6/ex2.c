#include <stdio.h>

int main (void)
{
	int Tab[100];
	int k = 0;

	for (k = 0; k < 100; k++)
	{
		Tab[k] = -k - 1;
	}

	for (k = 0; k < 100; k++)
	{
		printf("Tab[%d] = %d\n", k, Tab[k]);
	}

	return 0;
}
