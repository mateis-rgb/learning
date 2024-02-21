#include <iostream>

struct maillon
{
	int val;
	maillon * suiv;
};

using liste = maillon *;

void init (liste & L)
{
	L = nullptr;
}

void ajouter_debut (int valeur, liste & L)
{
	liste aux = new maillon;

	aux->val = valeur;
	aux->suiv = L;

	L = aux;
}

void supprimer_premier (liste & L)
{
	liste aux = L;

	L = L->suiv;

	delete aux;
}

void ajouter_fin (int valeur, liste & L)
{
	if (L == nullptr)
	{
		L = new maillon;
		L->val = valeur;
		L->suiv = nullptr;
	}
	else
	{
		ajouter_fin(valeur, L->suiv);
	}
}

bool appartient (int valeur, liste L)
{
	if (L == nullptr) return false;
	else if (L->val == valeur) return true;
	else return appartient(valeur, L->suiv);
}

void afficher (liste L)
{
	if (L == nullptr)
	{
		std::cout << "\n";
	}
	else
	{
		std::cout << L->val << " ";

		afficher(L->suiv);
	}
}

void vide (liste & L)
{
	if (L != nullptr)
	{
		supprimer_premier(L);

		vide(L);
	}

}

int longueur (liste L)
{
	if (L == nullptr)
	{
		return 0;
	}

	return 1 + longueur(L->suiv);
}

int main (void)
{
	liste L;
	int n, cpt;

	init(L);

	cpt = 0;

	std::cout << "Combien de valeurs voulez-vous ajouter à la liste: ";
	std::cin >> n;

	do {
		int temp;

		std::cout << "Ajouter une valeur a la liste ("<< cpt+1 << "/" << n  <<"): ";
		std::cin >> temp;

		cpt++;

		ajouter_debut(temp, L);
	}
	while (cpt < n);

	afficher(L);

	return 0;
}
















