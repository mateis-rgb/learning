#include <stdio.h>

unsigned int fibo_iter (int n);

int main (void)
{
	printf("fibo(4): %d\n", fibo_iter(4));

	return 0;
}

unsigned int fibo_iter (int n)
{
	int k = 0;
	unsigned int fibo = 0;

	for (k = 0; k < n; k++)
	{
		fibo += fibo;
	}

	return fibo;
}

unsigned int fibo_recurse (int n)
{
	if (n == 0) return 0;

	for (k = 0; k < n; k++)
	{
		fibo += fibo;
	}

	return fibo;
}
