#include <stdio.h>

/**
 * @brief User can choose between 1 (ascii -> char) and 2 (char -> ascii)
 * 
 * @return int 
 */
char menu (void);

int main (void)
{
	char choice = menu();
	unsigned char temp = 0;

	// ASCII -> char
	if (choice == 1)
	{
		printf("Entrez le code ASCII : ");
		scanf("%d", &temp);

		printf("Le caractere correspondant au code ASCII %d est %c", temp, temp);
	}


	// char -> ASCII
	if (choice == 2)
	{
		printf("Entrez le caractere : ");
		scanf(" %c", &temp);

		printf("Le code ASCII corresondant %c est %d", temp, temp);
	}

	return 0;
}

char menu (void)
{
	char returned_value = 0;

	printf("1. ASCII vers caractere\n2. Caractere vers ASCII\nQuel est votre choix (1 ou 2) : ");
	scanf("%d", &returned_value);

	return returned_value;
}
