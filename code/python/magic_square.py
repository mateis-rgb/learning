from pycsp3 import VarArray, satisfy, AllDifferent, solve, SAT, values
from colorama import Fore
from pyfiglet import figlet_format

def ask_size () -> int :
	size: int = int(input("Enrez un nombre n (qui correspondra à la taille de la matrice): "))

	return size


def gen_matrix (size: int) -> list[list[int]]:
	mat = VarArray(size=[n, n], dom=range(1, (n*n)+1))

	satisfy(
		AllDifferent(mat)
	)

	if solve() is SAT:
		return values(mat)
	
	raise Exception("Something went wrong...")


def line_verify (mat: list[list[int]], waiting: int) -> bool:
	# On parcours la matrice en ligne 
	for line in mat:
		line_sum: int = 0

		# On fait la somme de toutes les valeurs de la ligne
		for k in line:
			line_sum += k

		# Si le résultat attendu est différent de la somme calculé on retourne faux
		if line_sum != waiting:
			return False

	# Sinon lorsque toutes les lignes ont été parcouru sans avoir été retourné, on retourne vrai
	return True


def col_verify (mat: list[list[int]], waiting: int) -> bool:
	# On parcours la matrice de gauche à droite
	for k in range(len(mat + 1)):
		col_sum: int = 0

		# Pour chaque ligne on prends la colone d'indice k, pour faire la somme de la colone
		for line in mat:
			col_sum += line[k]

		# On vérifie si la somme de la colone est différent du résultat attendu, si le cas échéant on retourne faux
		if col_sum != waiting:
			return False
	
	# Sinon après tout les parcours sans retours, on retourne vrai
	return True


def diagonal_verify (mat: list[list[int]], waiting: int) -> bool:
	top_bottom_diag_sum: int = 0
	bottom_top_diag_sum: int = 0

	# On parcours 
	for k in range(len(mat + 1)):
		top_bottom_diag_sum += mat[k][k]
		bottom_top_diag_sum += mat[len(mat) - k][k]

	if top_bottom_diag_sum == bottom_top_diag_sum:
		if top_bottom_diag_sum != waiting:
			return False

	return True

def verify (mat: list[list[int]], size: int) -> bool:
	waiting: int = (size*(size*size + 1) / 2)

	# On vérifie si la ligne correspond au calcul attendu
	if line_verify(mat, waiting):
		
		# On vérifie si la colone correspond au calcul attendu
		if col_verify (mat, waiting):

			# On vérifie si les diagonales correspond au calcul attendu
			if diagonal_verify (mat, waiting):
				return True

	# Sinon on retourne faux 
	return False


def main():
	print(f"{Fore.GREEN} {figlet_format('magic square.py')} {Fore.WHITE}")

	size: int = ask_size()

	mat = gen_matrix(size)

	print(mat)


if (__name__ == "__main__"):
	main()