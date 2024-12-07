import argparse
from colorama import Fore
from pyfiglet import figlet_format
from string import ascii_letters
from numpy import minimum

class Arguments:
	""" Classe utilisé par le parseur d'arguments, recopié tels quel depuis la documentation,
		il permet de pouvoir utiliser une variable (instance de cette classe) pour les arguments du parseur.
	"""
	pass

frequence_apparition_lettres_fr: dict = {
	"e": 12.10,
	"a": 7.11,
	"i": 6.59
}

alphabet_length: int = len(ascii_letters)


def dict_sort(dictionnary: dict) -> dict:
	sorted_dict = dict(
        sorted(
			dictionnary.items(), 
			key=lambda x: x[1], 
			reverse=True
		)
	)

	return sorted_dict


def frequence_apparition (string: str) -> dict[str, float]:
	apparition: dict = {}
	string_len: int = len(string)
	string_len_without_alpha: int = 0

	for k in range(string_len):
		value: str = string[k].lower()

		if value.isalpha():
			string_len_without_alpha += 1

			if apparition.get(value):
				apparition[value] += 1

			else:
				apparition[value] = 1

	for key, value in apparition.items():
		apparition[key] = round((value / string_len_without_alpha) * 100, 3)

	return dict_sort(apparition)


def decode (text: str, decalage: int) -> str:
	""" Fonction de décodage

	Args:
		text (str): texte a dechiffrer
		decalage (int): Décalage du code césar

	Returns:
		str: texte déchiffrer
	"""	
	traitment: str = ""
	
	for car in text:
		if car not in ascii_letters:
			traitment += car
		
		else:
			index: int = 0

			if car.islower():
				index = (ascii_letters.index(car) - decalage) % alphabet_length
			
			else:
				index = (ascii_letters.index(car) - decalage) % alphabet_length + alphabet_length

			traitment += ascii_letters[index]

	return traitment


def bruteforce (in_path: str) -> str:
	traitment: list[str] = []

	with open(in_path, "r") as file:
		decoded_file: dict[int, str] = dict()
		frequences_list: dict[int, dict[str, float]] = dict()
		differences: dict[int, dict[str, float]] = dict()

		min_diff: int = 0

		text: str = file.read()

		for k in range(len(ascii_letters)):
			decoded_file[k] = decode(text, k)

		for key, value in decoded_file.items():
			frequence_apparition_decoded: dict[str, float] = frequence_apparition(value)

			frequences_list[key] = frequence_apparition_decoded

		for key, value in frequences_list.items():
			diff: dict[str, float] = dict()

			for letter, percent in value.items():
				if letter in ["a", "e", "i"]:
					diff[letter] = round(abs(percent - frequence_apparition_lettres_fr[letter]), 3)

			if len(diff) == 3:
				differences[key] = dict_sort(diff)
				
		for indice, difference in differences.items():
			if (min_diff != indice):
				min_diff_dict = differences[min_diff]
				
				min_values: list[float] = list(min_diff_dict.values())
				diff_values: list[float] = list(difference.values())

				mini: list[float] = minimum(min_values, diff_values)

				if (mini == diff_values).all():
					min_diff = indice
					
		return decoded_file[min_diff]


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
	main()