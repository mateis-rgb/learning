#include <iostream>

bool f (int i)
{ 
	if (i > 0)
	{
		return f(i - 1);
	}

	return true;
}

int main ()
{
	int i;

	do
	{
		std::cin >> i;
	}
	while (f(i));
}