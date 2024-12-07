def creer_carre_magique(n):
    carre_magique = [[0] * n for _ in range(n)]

    # Positionner le premier nombre au centre de la première ligne
    i, j = 0, n // 2
    for num in range(1, n**2 + 1):
        carre_magique[i][j] = num
        new_i, new_j = (i - 1) % n, (j + 1) % n
        if carre_magique[new_i][new_j]:
            i += 1
        else:
            i, j = new_i, new_j

    return carre_magique

def creer_carre_magique_paire(n):
    carre_magique = [[0] * n for _ in range(n)]

    # Remplir le carré magique en partant des coins
    num = 1
    for i in range(n):
        for j in range(n):
            if (i + j) % 4 == 0 or ((i - 2) % 4 == 0 and (j - 2) % 4 == 0):
                carre_magique[i][j] = num
            else:
                carre_magique[i][j] = n**2 + 1 - num
            num += 1

    return carre_magique

def afficher_carre_magique(carre):
    print("Carré Magique :")
    for ligne in carre:
        print("\t".join(map(str, ligne)))

def main():
    taille = int(input("Entrez la taille du carré magique : "))
    if taille < 3:
        print("La taille doit être au moins 3.")
        return

    if taille % 2 == 0:
        print("La taille est paire.")
        carre_magique = creer_carre_magique_paire(taille)
    else:
        print("La taille est impaire.")
        carre_magique = creer_carre_magique(taille)

    afficher_carre_magique(carre_magique)

if __name__ == "__main__":
    main()
