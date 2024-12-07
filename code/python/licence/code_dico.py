""" Ici, on décidera de faire un programme qui lorsqu'on l'appel en commande on écrira : `python3 code_dico.py <correspondence_file_path> <input_file_path> <chiffrer|dechiffrer|init> <output_file_path>`
"""
import argparse
from json import dumps as stringify, loads as parse
from colorama import Fore
from pyfiglet import figlet_format

def valeur_absolue (valeur: int) -> int:
	if valeur < 0:
		return -valeur

	return valeur

class Arguments:
	""" Classe utilisé par le parseur d'arguments, recopié tels quel depuis la documentation,
		il permet de pouvoir utiliser une variable (instance de cette classe) pour les arguments du parseur.
	"""
	pass


# cette fonction analyse le fichier en entré et defini un dictionnaire avec les aparition de chaques caractère et renvoie un dictionnaire de correspondance entre toutes les lettres
def init (input_path: str) -> dict:
	correspondance: dict = {}
	apparition: dict = {}

	with open(input_path, "r") as file:
		lines: list[str] = file.readlines()

		for line in lines:
			for caracter in line:
				if apparition.get(caracter):
					apparition[caracter] += 1
		
				else:
					apparition[caracter] = 1

	apparition = dict(sorted(apparition.items()))
	apparition_length: int = len(apparition)

	# le nombre de caractère dans apparition est pair
	if apparition_length % 2 == 0:
		for k in range (int(apparition_length / 2)):
			keys: list[str] = list(apparition.keys())
			key: str = keys[k]
			oposite_key: str = keys[apparition_length - 1 - k]
	
			correspondance[key] = oposite_key

	else:
		keys: list[str] = list(apparition.keys())

		for k in range (int((apparition_length - 1) / 2)):
			key: str = keys[k]
			oposite_key: str = keys[apparition_length - 1 - k]
	
			correspondance[key] = oposite_key

		correspondance[keys[len(correspondance)]] = keys[len(correspondance)]
		
	return correspondance


def code (input_path: str, corres: dict) -> list[str]:
	traitment: list[str] = []

	with open(input_path, "r") as file:
		lines: list[str] = file.readlines()
	
		for line in lines:
			trait_line: str = ""
			
			for car in line:
				for key, value in corres.items():
					if car == value:
						trait_line += key
					elif car == key:
						trait_line += value

			traitment.append(trait_line)

	return traitment


def main():
	screen = figlet_format("Code Dico.PY")
	print(f"{Fore.GREEN} {screen} {Fore.WHITE}")

	parser = argparse.ArgumentParser(description="Algorithme de chiffrement.")

	arguments = Arguments()

	parser.add_argument("-i", "--input", nargs=1, help="Chemin du fichier texte en entrée, avant chiffrement.")
	parser.add_argument("-o", "--output", nargs=1, help="Chemin du fichier texte en sortie, après le chiffrement.")
	parser.add_argument("-m", "--mode", nargs=1, choices=["chiffrer", "dechiffrer", "init"], help="Mode de chiffrement <chiffrer|dechiffrer|init>")
	parser.add_argument("-c", "--correspond", nargs=1, required=False, help="Chemin du fichier json de correspondance.")

	args = parser.parse_args(namespace=arguments)
	
	in_path: str = arguments.input[0]
	mode: str = arguments.mode[0]
	out_path: str = arguments.output[0]
	cor_path: str = None if arguments.correspond == None else arguments.correspond[0]

	if mode == "init" and cor_path == None:
		dict_code: dict = init(in_path)
		dict_path: str = "./dico_corres.json"

		with open(dict_path, "w") as file:
			file.write(stringify(dict_code))
	
		print(f"{Fore.BLUE}[program]: {Fore.WHITE}le dictionnaire de correspondance à bien été crée.\n{Fore.BLUE}[program]: {Fore.WHITE}veuillez l'utiliser lorsque vous utiliserez a nouveau le programme avec ces fichier d'entré et de sortie:\n{Fore.BLUE}[program]: {Fore.WHITE}`python3 code_dico.py {dict_path} {in_path} {mode} {out_path}`")
	
		return
	
	elif cor_path != None:
		with open(cor_path, "r") as corres:
			correspondant: dict = parse(corres.readline())

			if mode == "chiffrer":
				traitment: list[str] = code(in_path, correspondant)

				with open(out_path, "w") as file:
					file.writelines(traitment)

				print(f"{Fore.BLUE}[program]: {Fore.WHITE}le chiffrement s'est bien effectué.")
				
				return

			if mode == "dechiffrer":
				traitment: list[str] = code(in_path, correspondant)

				with open(out_path, "w") as file:
					file.writelines(traitment)

				print(f"{Fore.BLUE}[program]: {Fore.WHITE}le déchiffrement s'est bien effectué.")
				
				return
			

if __name__ == "__main__":
	main()