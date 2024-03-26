from pycsp3 import VarArray, satisfy, AllDifferent, solve, SAT, values
from colorama import Fore
from pyfiglet import figlet_format

def ask_size () -> int :
	size: int = int(input("Enrez un nombre n (qui correspondra à la taille de la matrice): "))

	return size
	

def line_sum (mat: list[list[int]]) -> list[int]:
	line_s: list[int] = []
	
	# On parcours la matrice en ligne 
	for line in mat:
		line_s.append(sum(line))

	return line_s


def col_sum (mat: list[list[int]]) -> bool:
	col_s: list[int] = []

	# On parcours la matrice de gauche à droite
	for k in range(len(mat) + 1):
		col_s_calc: int = 0

		# Pour chaque ligne on prends la colone d'indice k, pour faire la somme de la colone
		for line in mat:
			col_s_calc += line[k]
		
		col_s.append(col_s_calc)

	# Sinon après tout les parcours sans retours, on retourne vrai
	return col_s


def top_bottom_diag_sum (mat: list[list[int]]) -> bool:
	top_bottom_diag_sum_calc: int = 0

	# On parcours la matrice
	for k in range(len(mat[0])):
		top_bottom_diag_sum_calc += mat[k][k]

	return top_bottom_diag_sum_calc


def bottom_top_diag_sum (mat: list[list[int]]) -> bool:
	bottom_top_diag_sum_calc: int = 0

	# On parcours la matrice
	for k in range(len(mat[0])):
		bottom_top_diag_sum_calc += mat[len(mat) - k][k]

	return bottom_top_diag_sum_calc


def generate_matrix (size: int) -> list[list[int]]:
	mat = VarArray(size=[size, size], dom=range(1, (size*size)+1))

	waiting: int = size * ((size*size) + 1) / 2

	lines_sum = line_sum(mat)
	cols_sum = col_sum(mat)
	t_b_diag_sum = top_bottom_diag_sum(mat)
	b_t_diag_sum = bottom_top_diag_sum(mat)

	satisfy (
		AllDifferent(mat)
	)

	for l_sum in lines_sum:
		satisfy (
			l_sum == waiting
		)

	for c_sum in cols_sum:
		satisfy (
			c_sum == waiting
		)

	satisfy (
		t_b_diag_sum == waiting
	)

	satisfy (
		b_t_diag_sum == waiting
	)

	if solve() is SAT:
		return values(mat)
	
	raise Exception("Something went wrong")


def main():
	print(f"{Fore.GREEN}{figlet_format('magic square.py')}{Fore.WHITE}")

	size: int = ask_size()

	mat: list[list[int]] = generate_matrix(size)

	print(mat)


if (__name__ == "__main__"):
	main()