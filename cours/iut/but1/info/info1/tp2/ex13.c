#include <stdio.h>

/* Prototypage de la fonction qui récupère la longueur d'un entier
* @var {int} n
* @returns {int}
*/ 
int get_int_length (int n);

/* Prototypage de la fonction qui calcule la puissance d'un nombre par rapport à l'autre
* @var {int} a
* @var {int} b
* @returns {int}
*/ 
int pow (int a, int b);

/* Prototypage de la fonction qui renvoie une couleur en fonction du chiffre en entrée
* @var {int} n
* @returns {char *}
*/ 
char * get_color_by_number (int color_code);

int main (void)
{
	// définition des fonctions
	int res = 0;
	int res_temp = 0;
	int res_temp1 = 0;
	char chiffre = 0; 
	char chiffre2 = 0;
	char multi = 0;
	char res_length = 0;
	char isPossible = 1;

	// Demande de l'entrée à l'utilisateur
	printf("Entrez une valeur de resistance : ");
	scanf("%d", &res);

	// On récupère la longueur de la resistance et on copie la valeur de la resistance pour effectuer des opérations dessus
	res_length = get_int_length(res);
	res_temp = res;
	multi = res_length - 2;

	if (res_length < 8)
	{
		for (int k = 0; k <= res_length; k++)
		{
			if (res_length - k == 1)
			{
				// On récupère le premier chiffre
				chiffre = res_temp%10;
			}

			if (res_length - k == 2)
			{
				// On récupère le chiffre2plicateur
				chiffre2 = res_temp%10;
			}
			
			if (res_length - k == 3 && res_temp % 10 != 0)
			{
				isPossible = 0;
			}

			res_temp /= 10;
		}
	
		if (isPossible) printf("Couleur des bagues : %s - %s - %s\n", get_color_by_number(chiffre), get_color_by_number(chiffre2), get_color_by_number(multi));

		if (isPossible == 0)
		{
			printf("Cette résistance n'est pas réalisable\n");

			res_temp = (chiffre * 10 + chiffre2) * pow(10, multi);
			res_temp1 = (chiffre * 10 + chiffre2 + 1) * pow(10, multi);
		
			if (res - res_temp < res_temp1 - res)
			{
				printf("Voici la valeur la plus proche : %dΩ (%s - %s - %s)\n", res_temp1, get_color_by_number(chiffre), get_color_by_number(chiffre2), get_color_by_number(multi));
			}
			else
			{
				printf("Voici la valeur la plus proche : %dΩ (%s - %s - %s)\n", res_temp, get_color_by_number(chiffre), get_color_by_number(chiffre2), get_color_by_number(multi));
			}
		}
	}
	else
	{
		printf("Cette résistance n'est pas réalisable");
	}

	return 0;
}

int get_int_length (int n)
{
	if (n < 10) return 1;

	return 1 + get_int_length(n/10);
}

int pow (int a, int b)
{
	if (b == 0) return 1;

	return a * pow(a, b - 1);
}

char * get_color_by_number (int color_code)
{
	// On fait un switch-case pour afficher dynamiquement la couleur en fonction du code couleur
	switch (color_code)
	{
		case 1:
			return "\033[0;31mmarron";

		case 2:
			return "\033[0;31mrouge";

		case 3:
			return "\033[0;31morange";

		case 4:
			return "\033[0;33mjaune";

		case 5:
			return "\033[0;32mvert";

		case 6:
			return "\033[0;34mbleu";
	
		case 7:
			return "\033[0;35mviolet";
	
		case 8:
			return "\033[0;37mgris";
	
		case 9:
			return "\033[0;37mblanc";
	}

	return "\033[0;30mnoir";
}
