const division = (a: number, b: number): number => {
	return Math.floor(a / b);
} 

const retirer_element = <T>(arr: T[], indice: number): T[] => {
	if (arr.length === 0) {
		return [];
	}

	if (indice > arr.length) {
		throw new Error("L'indice de l'élément à supprimer ne doit pas dépasser la taille du tableau");
	}

	const new_arr: T[] = [];

	for (let k = 0; k < arr.length; k++) {
		if (k !== indice) {
			new_arr.push(arr[k]);
		}
	}

	return new_arr;
}

const rendu_monnaie = (montant: number, systeme_monnaie: number[]): Record<string, number> => {
	if (systeme_monnaie.length === 0) {
		throw new Error("Le système monnaitaire ne doit pas être vide.");
	}
	
	const monnaie: number = systeme_monnaie[0];
	const str_monnaie: string = monnaie.toString();
	
	if (montant % monnaie === 0) {
		return { str_monnaie: montant/monnaie }
	}
	
	const new_systeme_monnaie: number[] = retirer_element(systeme_monnaie, 0);

	return { str_monnaie: division(montant, monnaie), ...rendu_monnaie(montant % monnaie, new_systeme_monnaie) }
}

const systeme_monnaie: number[] = [500, 200, 100, 50, 20, 10, 5, 2, 1];

console.log(rendu_monnaie(999, systeme_monnaie));