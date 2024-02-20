import numpy as np;
import matplotlib.pyplot as plt;

""" Ex 1:
def main ():
	prenom: str = "";

	prenom = str(input("Quel est votre prénom: "));

	print(f"Coucou {prenom}");


if (__name__ == "__main__"):
	main();
"""

""" Ex 2:
def main ():
	cpt: int = 0;

	cpt = int(input("Valeur initial: "));

	if (cpt > 0):
		for k in range (cpt, 0, -1):
			print(k, end=" ");

		print("GO");

if (__name__ == "__main__"):
	main();
"""

""" Ex 3:
def main ():
	cpt: int = 0;
	mots: list = list();

	cpt = int(input("Combien de mots voulez vous écrire: "));

	for k in range (cpt):
		temp: str = "";

		temp = str(input(f"Entrez un mot {k+1}/{cpt}: "));

		mots.append(temp);

	for mot in mots:
		if (len(mot) > 4):
			print(mot);

if (__name__ == "__main__"):
	main();
"""

""" Ex 4:
def main():
	trad: dict = {
		"un": "one",
		"deux": "two",
		"trois": "three",
		"quatre": "four"
	};

	for key in trad.keys():
		print(key, end=" ");

	print("\n");

	for value in trad.values():
		print(value, end=" ");

	print("\n");

	for key, value in trad.items():
		print(f"{key} -> {value}");

if (__name__ == "__main__"):
	main();
"""

""" Ex 6:
def saisie(valeurs: list[int]):
	cpt: int = 0;

	cpt = int(input("Combien de valeurs voulez vous écrire: "));

	for k in range (cpt):
		temp: int = "";

		temp = int(input(f"Entrez une valeur entière positive {k+1}/{cpt}: "));

		if (temp >= 0):
			valeurs.append(temp);


derniere_valeurs = lambda array: array[-2];


def somme_valeurs (array: list[int]) -> int:
	retour: int = 0;

	for valeur in array:
		if (valeur != array[0] and valeur != array[-1]):
			retour += valeur;

	return retour;
"""

def main ():
	x = np.linspace(0, 2 * np.pi, 200)
	y = np.cos(x)

	fig, ax = plt.subplots()
	ax.plot(x, y)
	plt.show()

if (__name__ == "__main__"):
	main();