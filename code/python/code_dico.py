""" Ici, on décidera de faire un programme qui lorsqu'on l'appel en commande on écrira : `python3 code_dico.py <correspondence_file_path> <input_file_path> <chiffrer|dechiffrer|init> <output_file_path>`
"""
import argparse
# from sys import argv
from json import dumps as stringify, loads as parse
from colorama import Fore
from pyfiglet import figlet_format

def valeur_absolue (valeur: int) -> int:
	if valeur < 0:
		return -valeur

	return valeur


def help ():
	print(f"{Fore.BLUE}[program]: {Fore.WHITE}pour utilisez ce program de chiffrement, utiliser la commande:\n{Fore.BLUE}[program]: {Fore.WHITE}`python3 code_dico.py <correspondence_file_path> <input_file_path> <chiffrer|dechiffrer|init> <output_file_path>`\n{Fore.BLUE}[program]: {Fore.WHITE}si vous n'avez pas de fichier de correspondance utilisez:\n{Fore.BLUE}[program]: {Fore.WHITE}`python3 code_dico.py <input_file_path> init <output_file_path>`")


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


def decode (input_path: str, corres: dict) -> list[str]:
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
	code = figlet_format("Code Dico.PY")
	print(f"{Fore.GREEN} {code} {Fore.WHITE}")

	parser = argparse.ArgumentParser(description="Algorithme de chiffrement.")

	# parser.add_argument("input", metavar="input_text_file", type=str, nargs=1, help="Chemin du fichier texte en entrée, avant chiffrement.")
	# parser.add_argument("mode", type=str, nargs=1, choices=["chiffrer", "dechiffrer", "init"], help="Mode de chiffrement <chiffrer|dechiffrer|init>")
	# parser.add_argument("output", metavar="output_text_file", type=str, nargs=1, help="Chemin du fichier texte en sortie, après le chiffrement.")
	# parser.add_argument("correspond", metavar="correspond_json_file", type=str, nargs=1, help="Chemin du fichier json de correspondance.")

	class Arguments:
		pass

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

				print(f"{Fore.BLUE}[program]: {Fore.WHITE}le codage s'est bien effectué.")
				
				return

			if mode == "dechiffrer":
				traitment: list[str] = decode(in_path, correspondant)

				with open(out_path, "w") as file:
					file.writelines(traitment)

				print(f"{Fore.BLUE}[program]: {Fore.WHITE}le décodage s'est bien effectué.")
				
				return

"""
def main(args):
	code = figlet_format("Code Dico.PY")
	print(f"{Fore.GREEN}{code}")

	if args[1] == "-h" or args[1] == "--help":
		help()

		return

	cor_path: str = ""
	in_path: str = ""
	mode: str = ""
	out_path: str = ""

	if len(args) == 4:
		in_path = args[1]
		mode = args[2]
		out_path = args[3]
	
	elif len(args) == 5:
		cor_path = args[1]
		in_path = args[2]
		mode = args[3]
		out_path = args[4]
	
	else:	
		raise ValueError(f"\n\n{Fore.RED}[error]: {Fore.WHITE}Le programme doit avoir 3 arguments:\n\t- input file path\n\t- mode: <chiffrer|dechiffrer|init>\n\t- output file path\n[program]: faites `python3 code_dico.py <-h|--help>")


	if mode != "chiffrer" and mode != "dechiffrer" and mode != "init":
		raise ValueError(f"\n\n{Fore.RED}[error]: {Fore.WHITE}Le mode doit absolument être \"chiffrer\" ou \"dechiffrer\" ou \"init\"\n{Fore.BLUE}[program]: {Fore.WHITE}: faites `python3 code_dico.py <-h|--help>`")

	if mode == "init":
		dict_code: dict = init(in_path)
		dict_path: str = "./dico_corres.json"

		with open(dict_path, "w") as file:
			file.write(stringify(dict_code))
	
		print(f"{Fore.BLUE}[program]: {Fore.WHITE}le dictionnaire de correspondance à bien été crée.\n{Fore.BLUE}[program]: {Fore.WHITE}veuillez l'utiliser lorsque vous utiliserez a nouveau le programme avec ces fichier d'entré et de sortie:\n{Fore.BLUE}[program]: {Fore.WHITE}`python3 code_dico.py {dict_path} {in_path} {mode} {out_path}`")
	
		return
	else:
		with open(cor_path, "r") as corres:
			correspondant: dict = parse(corres.readline())

			if mode == "chiffrer":
				traitment: list[str] = code(in_path, correspondant)

				with open(out_path, "w") as file:
					file.writelines(traitment)

				print(f"{Fore.BLUE}[program]: {Fore.WHITE}le codage s'est bien effectué.")
				
				return

			if mode == "dechiffrer":
				traitment: list[str] = decode(in_path, correspondant)

				with open(out_path, "w") as file:
					file.writelines(traitment)

				print(f"{Fore.BLUE}[program]: {Fore.WHITE}le décodage s'est bien effectué.")
				
				return



	raise Exception(f"{Fore.RED}[error]: {Fore.WHITE}quelque chose s'est mal passé, réessayer avec d'autres valeurs, ou des valeurs conforment au programme.\n{Fore.BLUE}[program]: {Fore.WHITE}faites `python3 code_dico.py <-h|--help>")
"""

if __name__ == "__main__":
	# main(argv)
	main()