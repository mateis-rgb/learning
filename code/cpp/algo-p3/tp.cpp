#include <iostream>
#include <string>

std::string extract (std::string chaine, unsigned int indice, unsigned int longueur)
{
	if (longueur == 0)
	{
		return chaine[indice] + "";
	}


	return chaine[indice] + extract(chaine, indice + 1, longueur - 1);
}

bool estPalindrome (std::string chaine, int debut, int fin)
{
	if (debut >= fin)
	{
		return false;
	}

	if (chaine[debut] == chaine[fin])
	{
		return true;
	}

	return estPalindrome(chaine, debut++, fin--);
}

int main ()
{
	

	return 0;
}