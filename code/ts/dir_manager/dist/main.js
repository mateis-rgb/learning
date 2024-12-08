"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const commander_1 = require("commander");
const figlet_1 = __importDefault(require("figlet"));
const path_1 = __importDefault(require("path"));
const functions_1 = require("./functions");
const program = new commander_1.Command();
console.log(figlet_1.default.textSync("Dir Manager"));
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
    (0, functions_1.listDirContents)(filepath);
}
if (options.mkdir) {
    (0, functions_1.createDir)(path_1.default.resolve(__dirname, options.mkdir));
}
if (options.touch) {
    (0, functions_1.createFile)(path_1.default.resolve(__dirname, options.touch));
}
//# sourceMappingURL=main.js.map