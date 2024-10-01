#include <stdio.h>

int main (void)
{
	unsigned char i = 100, j, k;
	j = i * 3;
	k = j / 3;

	// On nous affiche 14 pour k car 100*3 est out of range sur un unsigned char donc il reprend a 0 et j n'est pas égal à 300 mais à 44 et 44 / 3 = 14
	printf("%d*3=%d ???", i, k);

	return 0;
}
