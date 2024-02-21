""" Ici, on décidera de faire un programme qui lorsqu'on l'appel en commande on écrira : `python3 main.py <key> <input> <chiffrer|dechiffrer> <output>`
"""
import sys;

def valeur_absolue (valeur: int) -> int:
	if (valeur < 0):
		return -valeur;

	return valeur;

#
def init (input_path: str) -> dict:


def code (input_path: str) -> list[str]:
	traitment: list[str] = [];

	with open(input_path, "r") as file:
		lines: list[str] = file.readlines();
	
		for line in lines:
			trait_line: str = "";
			
			for car in line:
				code: int = ord(car);

				# si le caractère est un retour a la ligne passe le caractere dans la ligne traité
				if (code == 10):
					trait_line += car;
				
				# on regarde si le caractere est un x, y, z
				elif (code >= 120 and code <= 122):
					trait_line += chr(valeur_absolue(120 - code) + 97);
				
				else:
					trait_line += chr(code + 3);

			traitment.append(trait_line);

	return traitment;

def decode (input_path: str) -> list[str]:
	traitment: list[str] = [];

	with open(input_path, "r") as file:
		lines: list[str] = file.readlines();

		for line in lines:
			trait_line: str = "";
			
			for car in line:
				code: int = ord(car);

				# si le caractère est un retour a la ligne passe le caractere dans la ligne traité
				if (code == 10):
					trait_line += car;
				
				# on regarde si le caractere est un x, y, z
				elif (code >= 97 and code <= 99):
					trait_line += chr(valeur_absolue(97 - code) + 120);

				else:
					trait_line += chr(code - 3);

			traitment.append(trait_line);

	return traitment;


def main(args):
	if (len(args) != 4):
		raise ValueError("\n\n[error]: Le programme doit avoir 3 arguments:\n\t- input file path\n\t- mode: <chiffrer|dechiffrer>\n\t- output file path");

	in_path: str = args[1];
	mode: str = args[2];
	out_path: str = args[3];

	if (mode != "chiffrer" and mode != "dechiffrer" and mode != "init"):
		raise ValueError("\n\n[error]: Le mode doit absolument être \"chiffrer\" ou \"dechiffrer\" ou \"init\".");

	if (mode == "init"):
		init();

	if (mode == "chiffrer"):
		traitment: list[str] = code(in_path);

		with open(out_path, "w") as file:
			file.writelines(traitment);

		print("[program]: le codage s'est bien effectué.");
		
		return;

	if (mode == "dechiffrer"):
		traitment: list[str] = decode(in_path);

		with open(out_path, "w") as file:
			file.writelines(traitment);

		print("[program]: le décodage s'est bien effectué.");
		
		return;

	raise Exception("[error]: Quelque chose s'est mal passé, réessayer avec d'autres valeurs, ou des valeurs conforment au programme.");


if (__name__ == "__main__"):
	main(sys.argv);