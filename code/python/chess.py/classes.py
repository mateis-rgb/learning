class Coodonne:
	def __init__(self, pos_x: int, pos_y: int):
		self.pos_x: int = pos_x
		self.pos_y: int = pos_y

class Piece:
	def __init__(self, id: int, name: str, color: int):
		self.id: int = id
		self.name: str = name
		self.color: int = color

class Grid:
	def __init__(self):
		self.content: list[list[Piece]] = [[Piece(0, "null", -1) for _ in range(8)]]*8

	def display(self):
		print("+---+---+---+---+---+---+---+---+---+")
		print("|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |")
		print("+---+---+---+---+---+---+---+---+---+")
		
		for i in range(8):
			print("| " + chr(ord('A') + i) + " | ", end='')

			for j in range(8):
				# 1 = p = pion
				# 2 = c = cavalier
				# 3 = t = tour
				# 4 = f = fou
				# 5 = d = dame
				# 6 = r = roi

				print(self.content[i][j].name[0] + " | ", end='')

			print("\n+---+---+---+---+---+---+---+---+---+")

	def generate(self):
		placementB: list[int] = [3, 2, 4, 5, 6, 4, 2, 3]
		placementN: list[int] = [3, 2, 4, 6, 5, 4, 2, 3]
		toName: str = ""

		for k in range(8):
			pionB: Piece = Piece(1, "pion", 0)
			pionN: Piece = Piece(1, "pion", 1)

			self.content[1][k] = pionB
			self.content[6][k] = pionN

		for k in range(8):
			if placementB[k] == 1:
				toName = "pion"
				
			elif placementB[k] == 2:
				toName = "cavalier"
			
			elif placementB[k] == 3:
				toName = "tour"
			
			elif placementB[k] == 4:
				toName = "fou"
			
			elif placementB[k] == 5:
				toName = "dame"
			
			elif placementB[k] == 6:
				toName = "roi"

			self.content[0][k] = Piece(placementB[k], toName, 0)

		for k in range(8):
			if placementN[k] == 1:
				toName = "pion"
				
			elif placementN[k] == 2:
				toName = "cavalier"
			
			elif placementN[k] == 3:
				toName = "tour"
			
			elif placementN[k] == 4:
				toName = "fou"
			
			elif placementN[k] == 5:
				toName = "dame"
			
			elif placementN[k] == 6:
				toName = "roi"

			self.content[7][k] = Piece(placementN[k], toName, 0)