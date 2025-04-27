#include <stdio.h>

/**
 * @brief Draw triangle with L at length
 * 
 * @param L 
 */
void triangleInverse (int L);

int main (void)
{
	triangleInverse(5);

	return 0;
}

void triangleInverse (int L)
{
	int i, j;
	
	for (i = L; i >= 0; i--)
	{
		for (j = 0; j < L - i; j++) printf(" ");

		for (j = 0; j < i; j++) printf("*");

		printf("\n");
	}
}
