#include <stdio.h>

/**
 * @brief Draw rectangle where L x H
 * 
 * @param L 
 * @param H 
 */
void rectangle (int L, int H);

int main (void)
{
	rectangle(3, 5);

	return 0;
}

void rectangle (int L, int H)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < H; i++) 
	{
		for (j = 0; j < L; j++)
		{
			printf("*");
		}
		printf("\n");
	}

}
