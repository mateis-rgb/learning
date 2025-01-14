import json

with open ("./cocktails.json") as file:
	data = json.load(file)

print(data)