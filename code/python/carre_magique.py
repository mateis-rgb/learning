from colorama import Fore
from pyfiglet import figlet_format

def demander_taille() -> int:
	"""
	Demande à l'utilisateur la taille du carré magique.
	"""
	while True:
		try:
			taille: int = int(input("Entrez la taille du carré magique (un nombre impair ou pair) : "))
		
			return taille
		except ValueError:
			print("Veuillez entrer un nombre valide.")


def creer_carre_magique(taille: int) -> list[list[int]]:
	"""
	Crée un carré magique de taille donnée.
	"""
	carre_magique: list[list[int]] = [[0] * taille for k in range(taille)]

	# Définition des indices de départ pour le nombre 1
	i: int = 0
	j: int = taille // 2

	# Placement des nombres dans le carré magique
	for num in range(1, taille * taille + 1):
		carre_magique[i][j] = num
		new_i: int = (i - 1) % taille
		new_j: int = (j + 1) % taille

		# Vérification si la case suivante est déjà occupée
		if carre_magique[new_i][new_j] != 0:
			# Si oui, descendre d'une ligne
			i = (i + 1) % taille
		else:
			# Sinon, déplacer à la case suivante
			i, j = new_i, new_j

	return carre_magique


def verifier_carre_magique(carre_magique: list[list[int]]) -> bool:
	"""
	Vérifie si le carré magique est valide.
	"""
	# Obtenir la taille du carré magique
	taille: int = len(carre_magique)
	# Calculer le nombre maximum dans le carré
	max_num: int = taille * taille
	# Calculer la somme magique pour chaque ligne, colonne et diagonale
	somme_magique: int = taille * (max_num + 1) // 2

	# Vérification des lignes
	for row in carre_magique:
		# Vérifie si la somme de chaque ligne est égale à la somme magique
		if sum(row) != somme_magique:
			return False

	# Vérification des colonnes
	for j in range(taille):
		# Calcule la somme de chaque colonne
		somme_colonne: int = sum(carre_magique[i][j] for i in range(taille))
		# Vérifie si la somme de chaque colonne est égale à la somme magique
		if somme_colonne != somme_magique:
			return False

	# Vérification de la diagonale principale
	somme_diag_principale: int = sum(carre_magique[i][i] for i in range(taille))
	# Vérifie si la somme de la diagonale principale est égale à la somme magique
	if somme_diag_principale != somme_magique:
		return False

	# Vérification de la diagonale secondaire
	somme_diag_secondaire: int = sum(carre_magique[i][taille - 1 - i] for i in range(taille))
	# Vérifie si la somme de la diagonale secondaire est égale à la somme magique
	if somme_diag_secondaire != somme_magique:
		return False

	# Retourne True si toutes les vérifications sont valides
	return True


def afficher_carre_magique(carre_magique: list[list[int]], taille: int):
	"""
	Affiche le carré magique.
	"""

	somme_attendu: float = taille*(taille*taille+1) / 2
	
	print(f"\n\nLa somme de chaque ligne sera de : {int(somme_attendu)}")
	print("Voici le carré magique : ")
	
	print("+---"*taille, "+", sep="")

	for i in range(taille):
		print("| ", sep="", end="")

		for j in range(taille):
			print(f"{carre_magique[i][j]} | ", sep="", end="")
		
		print("\n", end="")
		print("+---"*taille, "+", sep="", end="\n")


def main() -> None:
	"""
	Fonction principale pour exécuter le programme.
	"""
	print(f"{Fore.GREEN}{figlet_format('magic square.py')}{Fore.WHITE}")
	
	# Demande à l'utilisateur de saisir la taille du carré magique
	taille: int = demander_taille()
	# Crée un carré magique valide
	carre_magique: list[list[int]] = creer_carre_magique(taille)

	# Si le carré magique n'est pas valide, en crée un nouveau jusqu'à ce qu'il soit valide
	while not verifier_carre_magique(carre_magique):
		carre_magique = creer_carre_magique(taille)
		print(carre_magique)

	# Affiche le carré magique valide
	afficher_carre_magique(carre_magique, taille)


if __name__ == "__main__":
	main()
