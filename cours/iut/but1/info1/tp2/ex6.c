#include <stdio.h>

int main (void)
{
	// version do...while
	int k = 22;

	do
	{
		printf("%d ", k);

		// On fait une décrementation par 2 (k -= 2 <=> k = k - 2)
		k -= 2;
	}
	while(k >= 2);

	// Version while
	k = 22;

	while (k >= 2)
	{
		printf("%d ", k);

		// On fait une décrementation par 2 (k -= 2 <=> k = k - 2)
		k -= 2;
	}

	return 0;
}
