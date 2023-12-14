#include <iostream>

unsigned int factorielle (unsigned int n)
{
	if (n == 0)
	{
		return 1;
	}

	return n * factorielle(n - 1);
}

int somme (int n)
{
	if (n == 0)
	{
		return 0;
	}

	return n + somme(n - 1);
}

int mystere (int n) // n >= 1
{
	if (n == 1)
	{
		return 1;
	}

	return mystere(n - 1) + 2 * (n - 1) + 1;
}

bool impaire (int);

bool pair (int n) // n >= 0
{
	if (n == 0)
	{
		return true;
	}

	return impaire (n - 1);
}

bool impaire (int n) // n >= 0
{
	if (n == 1)
	{
		return true;
	}
	
	return pair (n - 1);
}

int main()
{
	

	return 0;
}