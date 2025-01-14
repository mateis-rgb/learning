const fs = require("fs");

const file = fs.readFileSync("./cocktails.json", { encoding: "utf-8" });
const parsedFile = JSON.parse(file);

const alcool = ["Vodka", "Triple_sec_Cointreau_Grand_Marnier"];

console.log(parsedFile);

for (const [key, value] of Object.entries(parsedFile)) {
	console.log(key);

	for (const [sub_key, sub_values] of Object.entries(value)) {
		console.log(`${sub_key}:`);
		
		sub_values.forEach(sub_val => {
			console.log(`\t${sub_val}`);
		});
	}
	
	console.log("\n");
}