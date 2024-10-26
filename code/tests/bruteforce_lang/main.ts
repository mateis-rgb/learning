// search_in_file.js
const fs = require('fs');

type occurrence = {
    index: number;
    line: string;
}

const searchInFile = (filePath: string, searchString: string): void => {
    const startTime: number = Date.now();
    const fileContent: string = fs.readFileSync(filePath, 'utf-8');
    const lines: string[] = fileContent.split('\n');

    let founded: occurrence[] = [];

    lines.forEach((line, index) => {
        if (line.includes(searchString)) {            
            let temp: occurrence = {index, line};

            founded.push(temp);
        }
    });
	
	if (founded.length == 0) {
		console.log(`String not found!`);
	}
	else {
        founded.forEach((occu: occurrence) => {
            console.log(`String found at line ${occu.index + 1}!`);
            console.log(`> ${searchString} == ${occu.line}\n`);
        });
	}

    const endTime = Date.now();
    console.log(`Execution time: ${(endTime - startTime) / 1000} seconds`);
}

if (process.argv.length < 4) {
    console.log("Usage: node search_in_file.js <file_path> <search_string>");
    process.exit(1);
}

const filePath: string = process.argv[2];
const searchString: string = process.argv[3];

searchInFile(filePath, searchString);
