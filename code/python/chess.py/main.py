from pyfiglet import figlet_format
from colorama import Fore
from classes import Coodonne, Piece, Grid


def main ():
	print(Fore.YELLOW, figlet_format("chess.py"), Fore.WHITE, sep='')

	newGrid: Grid = Grid()

	newGrid.display()
	newGrid.generate()
	newGrid.display()


if (__name__ == '__main__'):
	main()