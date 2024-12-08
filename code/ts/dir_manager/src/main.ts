import { Command } from "commander";
import figlet from "figlet";
import path from "path";

import { listDirContents, createDir, createFile } from "./functions";

const program: Command = new Command();

console.log(figlet.textSync("Dir Manager"));

program
	.version("1.0.0")
	.description("An example CLI for managing a directory")
	.option("-l, --ls [value]", "List directory contents")
	.option("-m, --mkdir <value>", "Create a directory")
	.option("-t, --touch <value>", "Create a file")
	.parse(process.argv);

const options = program.opts();


if (!process.argv.splice(2).length) {
	program.outputHelp();
}


if (options.ls) {
	const filepath = typeof options.ls === "string" ? options.ls : __dirname;

	listDirContents(filepath);
}

if (options.mkdir) {
	createDir(path.resolve(__dirname, options.mkdir));
}

if (options.touch) {
	createFile(path.resolve(__dirname, options.touch));
}
