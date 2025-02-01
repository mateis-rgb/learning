#include <stdio.h>

int main (void)
{
	float somme = 0;
	float temp = 0;
	unsigned char cpt = 0;

	do {
		printf("Entrez une note : ");
		scanf("%f", &temp);

		if (temp != -1)
		{
			somme += temp;
			cpt++;
		}
	} 
	while (temp != -1);
	
	printf("La moyenne est %.2f", somme/cpt);

	return 0;
}
