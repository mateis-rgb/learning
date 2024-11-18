#include <stdio.h>

int main (void)
{
	int k = 0;
	char str[10] = "abc";

	for (k = 0; (unsigned long) k < sizeof(str); k++)
	{
		printf("str[%d] = '%c' = %.2d = 0x%.2x\n", k, str[k], str[k], str[k]);
	}

	return 0;
}
