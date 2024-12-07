from pycsp3 import VarArray, satisfy, AllDifferent, solve, values, SAT, Sum, value
from colorama import Fore
from pyfiglet import figlet_format

def ask_size() -> int:
	size: int = int(input("Entrez un nombre n (qui correspondra à la taille de la matrice): "))
	return size

def line_sum(mat: list[list[int]]) -> list[int]:
	line_s: list[int] = []
	# On parcourt la matrice en ligne
	for line in mat:
		line_s.append(Sum(line))
	return line_s

# def col_sum(mat: list[list[int]]) -> list[int]:
# 	col_s: list[int] = []
# 	# On parcourt la matrice de gauche à droite
# 	for k in range(len(mat[0])):
# 		col_s_calc: int = 0
# 		# Pour chaque ligne on prend la colonne d'indice k, pour faire la somme de la colonne
# 		for line in mat:
# 			col_s_calc += line[k]
# 		col_s.append(col_s_calc)
# 	return col_s

# def top_bottom_diag_sum(mat: list[list[int]]) -> int:
# 	top_bottom_diag_sum_calc: int = 0
# 	# On parcourt la matrice
# 	for k in range(len(mat[0])):
# 		top_bottom_diag_sum_calc += mat[k][k]
# 	return top_bottom_diag_sum_calc

# def bottom_top_diag_sum(mat: list[list[int]]) -> int:
# 	bottom_top_diag_sum_calc: int = 0
# 	# On parcourt la matrice
# 	for k in range(len(mat[0])):
# 		bottom_top_diag_sum_calc += mat[len(mat) - k - 1][k]
# 	return bottom_top_diag_sum_calc


# def line_sum(mat: list[list[int]]) -> list[int]:
#     return [sum(line) for line in mat]

def col_sum(mat: list[list[int]]) -> list[int]:
    return [Sum(col) for col in zip(*mat)]

def top_bottom_diag_sum(mat: list[list[int]]) -> int:
    return Sum(mat[i][i] for i in range(len(mat)))

def bottom_top_diag_sum(mat: list[list[int]]) -> int:
    return Sum(mat[i][len(mat)-1-i] for i in range(len(mat)))


def generate_matrix(size: int) -> list[list[int]]:
	mat = VarArray(size=[size, size], dom=range(1, (size*size)+1))
	waiting: int = size * ((size*size) + 1) // 2

	lines_sum = line_sum(mat)
	cols_sum = col_sum(mat)
	t_b_diag_sum = top_bottom_diag_sum(mat)
	b_t_diag_sum = bottom_top_diag_sum(mat)

	satisfy(AllDifferent(mat))

	print(value(mat[0][0]))

	# print(lines_sum)
	# print(cols_sum)
	# print(t_b_diag_sum)
	# print(b_t_diag_sum)

	if solve() is SAT:
		print(True)
	
	else:
		print(False)
	# raise Exception("Impossible de générer la matrice magique")

def print_matrix(mat: list[list[int]]):
	for row in mat:
		print(row)


def main():
	print(f"{Fore.GREEN}{figlet_format('magic square.py')}{Fore.WHITE}")
	size: int = ask_size()
	mat: list[list[int]] = generate_matrix(size)
	# print("Matrice magique générée :")
	# print_matrix(mat)

if __name__ == "__main__":
	main()
