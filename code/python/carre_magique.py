from colorama import Fore
from pyfiglet import figlet_format

def ask_size () -> int:
	"""
	Demande à l'utilisateur la taille du carré magique.
	"""
	while True:
		try:
			taille: int = int(input("Entrez la taille du carré magique : "))
			
			return taille
			
		except ValueError:
			print("Veuillez entrer un nombre valide.")


def creer_carre_magique(taille: int) -> list[list[int]]:
	"""
	Crée un carré magique de taille donnée.
	"""

	# Initialisation d'une liste vide pour stocker le carré magique
	carre_magique: list[list[int]] = [[0] * taille for _ in range(taille)]

	# Initialisation des variables pour le placement des nombres dans le carré
	i: int = taille / 2
	j: int = taille - 1
	num: int = 1
	max_num: int = taille * taille  # Calcul du nombre maximum dans le carré
	somme_magique: float = taille * (max_num + 1) / 2  # Calcul de la somme magique pour chaque ligne, colonne et diagonale

	# Boucle pour placer les nombres dans le carré
	while num <= max_num:
		# Vérification des conditions pour la position du prochain nombre
		if i == -1 and j == taille:
			j = taille - 2
			i = 0
		else:
			if j == taille:
				j = 0
			if i < 0:
				i = taille - 1

		# Vérification si la case est déjà remplie, si oui, déplacer les indices
		if carre_magique[i][j] != 0:
			j = j - 2
			i = i + 1
			continue
		else:
			# Placer le prochain nombre dans la case
			carre_magique[i][j] = num
			num = num + 1

		# Déplacer les indices pour la prochaine itération
		j = j + 1
		i = i - 1

	# Retourner le carré magique une fois terminé
	return carre_magique


def verifier_carre_magique(carre_magique: list[list[int]]) -> bool:
	"""
	Vérifie si le carré magique est valide.
	"""

	taille: int = len(carre_magique)
	max_num: int = taille * taille
	somme_magique: int = taille * (max_num + 1) // 2

	# Vérification des lignes
	for row in carre_magique:
		if sum(row) != somme_magique:
			return False

	# Vérification des colonnes
	for j in range(taille):
		somme_colonne = sum(carre_magique[i][j] for i in range(taille))
		
		if somme_colonne != somme_magique:
			return False

	# Vérification de la diagonale principale
	somme_diag_principale = sum(carre_magique[i][i] for i in range(taille))
	
	if somme_diag_principale != somme_magique:
		return False

	# Vérification de la diagonale secondaire
	somme_diag_secondaire = sum(carre_magique[i][taille - 1 - i] for i in range(taille))
	
	if somme_diag_secondaire != somme_magique:
		return False

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


def main():
	"""
	Fonction principale pour exécuter le programme.
	"""
	print(f"{Fore.GREEN}{figlet_format('magic square.py')}{Fore.WHITE}")
	
	taille: int = ask_size()
	carre_magique: list[list[int]] = creer_carre_magique(taille)

	while not verifier_carre_magique(carre_magique):
		carre_magique = creer_carre_magique(taille)

	afficher_carre_magique(carre_magique, taille)


if __name__ == "__main__":
	main()
