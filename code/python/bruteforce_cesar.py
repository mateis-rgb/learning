import argparse
from colorama import Fore
from pyfiglet import figlet_format
from string import printable;

class Arguments:
	""" Classe utilisé par le parseur d'arguments, recopié tels quel depuis la documentation,
		il permet de pouvoir utiliser une variable (instance de cette classe) pour les arguments du parseur.
	"""
	pass


def bruteforce (in_path: str) -> list[str]:
	traitment: list[str] = []
	ascii_printable = printable[:-38]
	
	print(in_path, "\n")

	"""
	decalage len list tte valeurs possible
	pour trouver des proba d'apparition de lettres
	stocker celui qui a la plus grande apparition de e -> 12,10%
	"""


	with open(in_path, "r") as file:
		for k in range(len(ascii_printable)):
			traitment: list[str] = []
			
			lines: list[str] = file.readlines()

			for line in lines:
				trait_line: str = ""
				
				for car in line:
					code: int = ord(car)

					# si le caractère est un retour a la ligne passe le caractere dans la ligne traité
					if (code == 10):
						trait_line += car
					
					# on regarde si le caractere est un x, y, z
					elif (code >= 97 and code <= 99):
						trait_line += chr(valeur_absolue(97 - code) + 120)

					else:
						trait_line += chr(code - k)

			traitment.append(trait_line)




def main():
	screen = figlet_format("bruteforce cesar.PY")
	print(f"{Fore.GREEN} {screen} {Fore.WHITE}")

	parser = argparse.ArgumentParser(description="Algorithme de chiffrement.")

	arguments = Arguments()

	parser.add_argument("-i", "--input", nargs=1, help="Chemin du fichier texte en entrée (fichier à déchiffrer).")
	parser.add_argument("-o", "--output", nargs=1, help="Chemin du fichier texte en entrée (fichier à déchiffrer).")

	parser.parse_args(namespace=arguments)

	in_path: str = arguments.input[0]
	out_path: str = arguments.output[0]

	traitment: list[str] = bruteforce(in_path)

	with open(out_path, "w") as file:
		file.writelines(traitment)

	return

if __name__ == "__main__":
	# main()

	bruteforce("./output.txt")