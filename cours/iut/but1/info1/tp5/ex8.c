#include <stdio.h>

/**
 * @brief Draw triangle with width of L
 * 
 * @param L 
 */
void triangle (int L);

int main (void)
{
	triangle(4);

	return 0;
}

void triangle (int L)
{
	int i, j;
	
	for (i = 0; i <= L; i++)
	{
		for (j = 0; j < i; j++) printf("*");

		printf("\n");
	}
}
