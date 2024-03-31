from random import randint, shuffle
from string import ascii_uppercase, ascii_lowercase, digits

# Exercice 1
def ex1 () -> None:
	array: list[int] = []
	nb_values_sup_seven: int = 0

	while 7 not in array:
		random: int = randint(1, 10)

		array.append(random)

	print(array)

	average: float = sum(array) / len(array)
	minimum: int = min(array)
	maximum: int = max(array)

	print(average)
	print(minimum)
	print(maximum)

	for integer in array:
		if integer > 7:
			nb_values_sup_seven += 1

	print(nb_values_sup_seven)


# Exercice 2
def voyelles_founder (text: str) -> tuple:
	voyelles: list[str] = ["a", "e", "i", "o", "u", "y"]
	founded: dict[str, int] = {"a": 0, "e": 0, "i": 0, "o": 0, "u": 0, "y": 0}
	maximum: tuple = ()

	for char in text:
		if char in voyelles:
			if founded[char] >= 0 :
				founded[char] += 1


	for key, value in founded.items():
		if len(maximum) == 0:
			maximum = key, value

		elif maximum[1] < value:
			maximum = key, value

	return maximum


# Exercice 3
def remplacer (c1: str, c2: str, s: str) -> str:
	returned: str = ""

	for char in s:
		if char == c1:
			returned += c2

		else:
			returned += char

	return returned


# Exercice 4
def sentence_counter (file_path: str) -> int:
	try:
		with open(file_path) as file:
			text = file.read()

			# Remplace les charactères de fin de phrase par un charactère spécial '|' pour diviser le texte
			text = text.replace('.', '|').replace('?', '|').replace('!', '|')

			# Divise le texte en phrases en utilisant le charactère spécial comme séparateur
			sentences = text.split('|')

			# Supprime les phrases vides
			sentences = [sentence.strip() for sentence in sentences if sentence.strip()]

			return len(sentences)

	except FileNotFoundError:
		raise FileNotFoundError()


def password_generator (size: int) -> str:
	if size < 12:
		raise ValueError("The size must be 12 characters minimum")

	password_array: list[str] = []

	upper_size: int = size // 3
	lower_size: int = size // 3
	digits_size: int = size - (size // 3) * 2

	for k in range(upper_size):
		password_array += ascii_uppercase[randint(0, len(ascii_uppercase) - 1)]

	for k in range(lower_size):
		password_array += ascii_lowercase[randint(0, len(ascii_lowercase) - 1)]

	for k in range(digits_size):
		password_array += digits[randint(0, len(digits) - 1)]

	shuffle(password_array)

	return ''.join(password_array)


if __name__ == '__main__':
	ex1()

	print(voyelles_founder("coucou c'est moi"))
	print(voyelles_founder("gdfg hjklkm nbvcwxq dfsgdh fjkn"))

	print(remplacer("a", "e", "coucou c'est moi"))
	print(remplacer("k", "j", "coucou c'est moi"))
	print(remplacer(" ", "\n", "gdfg hjklkm nbvcwxq dfsgdh fjkn"))

	print(sentence_counter("./test.txt"))

	print(password_generator(12))
	print(password_generator(32))
	print(password_generator(64))