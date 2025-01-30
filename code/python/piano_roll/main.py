def init() -> list[list[15]]:
	temp: list[list[15]] = [[ 0 for _ in range(15) ] for _ in range(3)]

	return temp

def display(partition: list[list[15]]):
	for y in range(3): 
		for x in range(15):
			print(f"{partition[y][x]}", end=", ")
		print("\n", end="")

def fill_partition (step: int, partition: list[list[15]]) -> list[list[15]]:
	temp: int = int(input("Entrez un chiffre entre 1 et 3"))

	

def main ():
	partition: list[list[15]] = init()

	display(partition)
	
	print(f"hello, world!")

if __name__ == "__main__":
	main()