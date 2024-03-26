from pycsp3 import satisfy, VarArray, AllDifferent, Sum, solve, SAT

n = int(input("Entrez la taille du carré magique (pair ou impair) : "))

# Définition des variables
square = VarArray(size=n*n, dom=range(1, n*n+1))

# Contrainte : tous les éléments doivent être distincts
satisfy(
	AllDifferent(square)
)

# Contraintes supplémentaires pour les lignes, colonnes et diagonales
magic_sum = n * (n * n + 1) // 2

for i in range(n):
	# Lignes
	satisfy(
		Sum(square[i * n: (i + 1) * n]) == magic_sum
	)
	# Colonnes
	satisfy(
		Sum([square[j * n + i] for j in range(n)]) == magic_sum
	)
# Diagonale principale
satisfy(
	Sum([square[i * (n + 1)] for i in range(n)]) == magic_sum
)
# Diagonale secondaire (si la taille est impaire)
if n % 2 != 0:
	satisfy(
		Sum([square[i * (n - 1)] for i in range(1, n + 1)]) == magic_sum
	)

if solve() is SAT:
	print(True)
else:
	print(False)
