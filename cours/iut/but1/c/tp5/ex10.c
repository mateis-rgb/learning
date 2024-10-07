#include <stdio.h>

/**
 * @brief Return 1 if a is divisible by b and 0 instead
 * 
 * @param a 
 * @param b 
 * @return char 
 */
char isDivider (int a, int b);

/**
 * @brief Find the littlest divider
 * 
 * @param n 
 * @return int 
 */
int littleDivider (int n);

/**
 * @brief Find if a num is prime or not
 * 
 * @param n 
 * @return int 
 */
int prime (int n);

int main (void)
{
	// int nbr = 0;
	// int primed_nbr = 0;

	// printf("Entrez un nombre entier : ");
	// scanf("%d", &nbr);

	// primed_nbr = prime(nbr);

	// if (primed_nbr == 0) printf("%d est un nombre premier.", nbr);
	// else printf("%d est divisible par %d, ce n'est pas un nombre premier.", nbr, primed_nbr);

	printf("\nisDivider\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");

	return 0;
}

char isDivider (int a, int b)
{
	if (a % b == 0) return 1;

	return 0;
}

int littleDivider (int n)
{
	int k = 2;
	char founded = 0;

	while (!founded || k < n)
	{
		founded = isDivider(n, k);

		k++;
	}

	if (founded == 0) return -1;

	return k;
}

int prime (int n)
{
	if (n == 1 || n == 0) return n;

	return 0;
}
