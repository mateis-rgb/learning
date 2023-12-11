#include <iostream>

int factorielle (int n)
{
	if (n == 0)
	{
		return 1;
	}

	return n * factorielle(n - 1);
}

int main()
{
	std::cout << factorielle(3);

	return 0;
}