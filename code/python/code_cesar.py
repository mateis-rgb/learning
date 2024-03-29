""" Ici, on décidera de faire un programme qui lorsqu'on l'appel en commande on écrira : `python3 main.py <input> <chiffrer|dechiffrer> <output>`
"""
import argparse
from colorama import Fore
from pyfiglet import figlet_format
from string import ascii_letters, ascii_lowercase

alphabet_length = len(ascii_lowercase)

def valeur_absolue (valeur: int) -> int:
	""" Fonction valeur absolue

	Args:
		valeur (int): entier positif ou négatif

	Returns:
		int: entier sans signe
	"""	
	if valeur < 0:
		return -valeur

	return valeur

class Arguments:
	""" Classe utilisé par le parseur d'arguments, recopié tels quel depuis la documentation,
		il permet de pouvoir utiliser une variable (instance de cette classe) pour les arguments du parseur.
	"""
	pass


def code (input_path: str, decalage: int) -> list[str]:
	""" Fonction de codage

	Args:
		input_path (str): Chemin d'acces au fichier en entrée
		decalage (int): Décalage du code césar

	Returns:
		list[str]: document chiffrer en liste de chaines de caractère représentant chaque ligne du fichier
	"""	
	traitment: list[str] = []

	with open(input_path, "r") as file:
		lines: list[str] = file.readlines()
	
		for line in lines:
			trait_line: str = ""
			
			for car in line:
				if car not in ascii_letters:
					trait_line += car
				
				else:
					index: int = 0

					if car.islower():
						index = (ascii_letters.index(car) + decalage) % alphabet_length
					
					else:
						index = (ascii_letters.index(car) + decalage) % alphabet_length + alphabet_length

					trait_line += ascii_letters[index]

			traitment.append(trait_line)

	return traitment


def decode (input_path: str, decalage: int) -> list[str]:
	""" Fonction de décodage

	Args:
		input_path (str): Chemin d'acces au fichier en entrée
		decalage (int): Décalage du code césar

	Returns:
		list[str]: document déchiffrer en liste de chaines de caractère représentant chaque ligne du fichier
	"""	
	traitment: list[str] = []

	with open(input_path, "r") as file:
		lines: list[str] = file.readlines()

		for line in lines:
			trait_line: str = ""
			
			for car in line:
				if car not in ascii_letters:
					trait_line += car
				
				else:
					index: int = 0

					if car.islower():
						index = (ascii_letters.index(car) - decalage) % alphabet_length
					
					else:
						index = (ascii_letters.index(car) - decalage) % alphabet_length + alphabet_length

					trait_line += ascii_letters[index]

			traitment.append(trait_line)

	return traitment


def main():
	screen = figlet_format("Code CESAR.PY")
	print(f"{Fore.GREEN}{screen}{Fore.WHITE}")

	parser = argparse.ArgumentParser(description="Algorithme de chiffrement par le code cesar.")

	arguments = Arguments()

	parser.add_argument("-i", "--input", nargs=1, help="Chemin du fichier texte en entrée, avant chiffrement.")
	parser.add_argument("-o", "--output", nargs=1, help="Chemin du fichier texte en sortie, après le chiffrement.")
	parser.add_argument("-m", "--mode", nargs=1, choices=["chiffrer", "dechiffrer"], help="Mode de chiffrement <chiffrer|dechiffrer>")
	parser.add_argument("-d", "--decalage", nargs=1, type=int, help="Entier, utilisé pour le décalage de chiffrement ou de déchiffrement")

	args = parser.parse_args(namespace=arguments)
	
	in_path: str = arguments.input[0]
	mode: str = arguments.mode[0]
	out_path: str = arguments.output[0]
	decal: int = arguments.decalage[0]

	if mode == "chiffrer":
		traitment: list[str] = code(in_path, decal)

		with open(out_path, "w") as file:
			file.writelines(traitment)

		print(f"{Fore.BLUE}[program]: {Fore.WHITE}le codage s'est bien effectué.")
		
		return

	if mode == "dechiffrer":
		traitment: list[str] = decode(in_path, decal)

		with open(out_path, "w") as file:
			file.writelines(traitment)

		print(f"{Fore.BLUE}[program]: {Fore.WHITE}le décodage s'est bien effectué.")
		
		return
			

if __name__ == "__main__":
	main()