import { readFileSync } from "fs";

const randint = (minimum: number, maximum: number): number => {
	return Math.floor(Math.random() * (maximum - minimum + 1 )) + minimum;
}


const div = (a: number, b: number): number => {
	return Math.floor(a / b);
}


const shuffle = <T>(array: T[]): T[] => {
    const shuffledArray = [...array];
    
	for (let i = shuffledArray.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        
		[shuffledArray[i], shuffledArray[j]] = [shuffledArray[j], shuffledArray[i]];
    }

    return shuffledArray;
}


const sum = (arr: number[]): number => {
	let integer: number = 0;

	arr.map((value: number) => {
		integer += value;
	});

	return integer;
}


const avg = (arr: number[]): number => {
	return sum(arr) / arr.length;
}


const min = (arr: number[]): number => {
	let minimum: number = arr[0];

	arr.map((value: number) => {
		if (value < minimum) {
			minimum = value;
		}
	});

	return minimum;
}


const max = (arr: number[]): number => {
	let maximum: number = arr[0];

	arr.map((value: number) => {
		if (value > maximum) {
			maximum = value;
		}
	});

	return maximum;
}


const trim = (arr: string[]): string[] => {
	let returned: string[] = [];

	arr.map((str: string) => {
		if (str.length !== 0) {
			returned.push(str);
		}
	})

	return returned;
}


const ex1 = (): void => {
	let arr: number[] = [];

	let nb_values_sup_sevent: number = 0;
	let average: number = 0;
	let minimum: number = 0;
	let maximum: number = 0;

	let stop: boolean = true;

	while (stop) {
		let random: number = randint(1, 10);

		arr.push(random);
		
		if (random === 7) {
			stop = false;
		}
	}

	console.log(arr);

	average = avg(arr);
	minimum = min(arr);
	maximum = max(arr);

	console.log(average);
	console.log(minimum);
	console.log(maximum);

	arr.map((value: number) => {
		if (value > 7) {
			nb_values_sup_sevent++;
		}
	});

	console.log(nb_values_sup_sevent);
}


const voyelles_founder = (text: string): [string, number] | null => {
	let text_arr: string[] = text.split("");
	let voyelles: string[] = ["a", "e", "i", "o", "u", "y"];
	let founded: Record<string, number> = {"a": 0, "e": 0, "i": 0, "o": 0, "u": 0, "y": 0}
	let maximum: [string, number] | null = null;

	text_arr.map((char: string) => {
		if (voyelles.includes(char)) {

			if (founded[char] >= 0) {
				founded[char] += 1;
			}
		}
	});

	for (const key in founded) {
		const value: number = founded[key];

		if (!maximum) {
			maximum = [key, value];
		}

		else if (maximum[1] < value) {
			maximum = [key, value];
		}
	}


	return maximum;
}


const replace = (c1: string, c2: string, s: string): string => {
	let returned: string = "";

	const string_splited: string[] = s.split("");
	
	string_splited.map((char: string) => {
		if (char === c1) {
			returned += c2;
		}
		else {
			returned += char;
		}
	});


	return returned;
}


const sentence_counter = (file_path: string): number => {
	const text: string = readFileSync(file_path, { encoding: "utf-8"});
		
	const replaced_text: string = text.replace('.', '|').replace('?', '|').replace('!', '|');

	const sentences: string[] = replaced_text.split("|");

	const sentences_transformed: string[] = trim(sentences);

	return sentences_transformed.length
} 


const password_generator = (size: number): string => {
	const ascii_lowercase: string = 'abcdefghijklmnopqrstuvwxyz';
	const ascii_uppercase: string = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
	const digits: string = '0123456789';

	let password_array: string[] = [];

	const upper_size: number = div(size, 3);
	const lower_size: number = div(size, 3);
	const digits_size: number = size - (div(size, 3) * 2);

	for (let k = 0; k < upper_size; k++) {
		password_array = [...password_array, ascii_uppercase[randint(0, ascii_uppercase.length - 1)]];
	}

	for (let k = 0; k < lower_size; k++) {
		password_array = [...password_array, ascii_lowercase[randint(0, ascii_lowercase.length - 1)]];
	}

	for (let k = 0; k < digits_size; k++) {
		password_array = [...password_array, digits[randint(0, digits.length - 1)]];
	}

	const shuffled: string[] = shuffle(password_array);

	return shuffled.join("");
}


ex1();

console.log(voyelles_founder("coucou c'est moi"))
console.log(voyelles_founder("gdfg hjklkm nbvcwxq dfsgdh fjkn"))

console.log(replace("o", "e", "coucou c'est moi"))
console.log(replace("k", "j", "coucou c'est moi"))
console.log(replace(" ", "\n", "gdfg hjklkm nbvcwxq dfsgdh fjkn"))

console.log(sentence_counter("./test.txt"))

console.log(password_generator(12))
console.log(password_generator(32))
console.log(password_generator(64))