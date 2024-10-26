# search_in_file.py
import sys
import time

class Occurences():
    def __init__(self, index: int, line: str):
        self.index: int = index
        self.line: str = line

def search_in_file(file_path, search_string):
	founded: list[Occurences] = []

	with open(file_path, 'r', encoding="utf-8") as file:

		for index, line in enumerate(file):						
			if search_string in line:
				temp: Occurences = Occurences(index, line)

				founded.append(temp)

	if len(founded) == 0:
		print(f"String not found!")
	else:
		for occu in founded:
			print(f"String found at line {occu.index}")
			print(f"> {search_string} == {occu.line}")


if __name__ == "__main__":
	if len(sys.argv) < 3:
		print("Usage: python search_in_file.py <file_path> <search_string>")
		sys.exit(1)


	file_path = sys.argv[1]
	search_string = sys.argv[2]
	
	start_time = time.time()
	
	search_in_file(file_path, search_string)
	
	end_time = time.time()
	
	print(f"Execution time: {end_time - start_time:.6f} seconds")
