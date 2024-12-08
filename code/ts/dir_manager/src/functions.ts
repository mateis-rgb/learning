import fs from "fs";
import path from "path";

export const listDirContents = async (filepath: string) => {
	try {
		const files = await fs.promises.readdir(filepath);

		const detailedFilePromises = files.map(async (file: string) => {
			let fileDetails = await fs.promises.lstat(path.resolve(filepath, file));

			const { size, birthtime } = fileDetails;

			return { filename: file, "size(KB)": size, created_at: birthtime }
		});

		const detailedFile = await Promise.all(detailedFilePromises);

		console.table(detailedFile);
	} 
	catch (err) {
		console.error("Error occurred while reading the directory!", err);
	}
}


export const createDir = (filepath: string) => {
	if (!fs.existsSync(filepath)) {
		fs.mkdirSync(filepath);

		console.log("The directory has been created successfully!");
	}
}


export const createFile = (filepath: string) => {
	fs.openSync(filepath, "w");

	console.log("An empty file has been created!");
}