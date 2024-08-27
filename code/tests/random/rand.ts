const random = () => {
	const time: number = Date.now();
	const time_splitted_string: string[] = time.toString().split("");
	const time_splitted_number: number[] = [];
	
	time_splitted_string.map((value: string) => time_splitted_number.push(Number(value)));
	
	let rand: number = 0;
	
	time_splitted_number.map((value: number) => rand += value);

	return rand;

	const time_updated
}