from pycsp3 import VarArray, satisfy, AllDifferent, solve, values
import math

def ask_size() -> int:
    while True:
        try:
            size = int(input("Entrez un nombre n (qui correspondra à la taille de la matrice): "))
            if size < 3:
                print("La taille doit être supérieure ou égale à 3.")
                continue
            return size
        except ValueError:
            print("Veuillez entrer un nombre entier valide.")

def generate_magic_square(size: int) -> list[list[int]]:
    magic_sum = size * (size**2 + 1) // 2
    mat = VarArray(size=[size, size], dom=range(1, (size*size)+1))

    satisfy(AllDifferent(mat))

    # Contraintes pour les lignes et les colonnes
    for i in range(size):
        satisfy(sum(mat[i][j] for j in range(size)) == magic_sum)
        satisfy(sum(mat[j][i] for j in range(size)) == magic_sum)

    # Contraintes pour la diagonale principale
    satisfy(sum(mat[i][i] for i in range(size)) == magic_sum)

    # Contraintes pour la diagonale secondaire (si la taille est impaire)
    if size % 2 != 0:
        satisfy(sum(mat[i][size-i-1] for i in range(size)) == magic_sum)

    if solve():
        return [[values(mat[i][j])[0] for j in range(size)] for i in range(size)]
    
    raise Exception("Impossible de générer la matrice magique")

def print_matrix(mat: list[list[int]]):
    for row in mat:
        print(row)

def main():
    print("Génération d'un carré magique")
    size = ask_size()
    magic_square = generate_magic_square(size)
    print("Carré magique généré :")
    print_matrix(magic_square)

if __name__ == "__main__":
    main()
