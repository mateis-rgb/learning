"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.createFile = exports.createDir = exports.listDirContents = void 0;
const fs_1 = __importDefault(require("fs"));
const path_1 = __importDefault(require("path"));
const listDirContents = (filepath) => __awaiter(void 0, void 0, void 0, function* () {
    try {
        const files = yield fs_1.default.promises.readdir(filepath);
        const detailedFilePromises = files.map((file) => __awaiter(void 0, void 0, void 0, function* () {
            let fileDetails = yield fs_1.default.promises.lstat(path_1.default.resolve(filepath, file));
            const { size, birthtime } = fileDetails;
            return { filename: file, "size(KB)": size, created_at: birthtime };
        }));
        const detailedFile = yield Promise.all(detailedFilePromises);
        console.table(detailedFile);
    }
    catch (err) {
        console.error("Error occurred while reading the directory!", err);
    }
});
exports.listDirContents = listDirContents;
const createDir = (filepath) => {
    if (!fs_1.default.existsSync(filepath)) {
        fs_1.default.mkdirSync(filepath);
        console.log("The directory has been created successfully!");
    }
};
exports.createDir = createDir;
const createFile = (filepath) => {
    fs_1.default.openSync(filepath, "w");
    console.log("An empty file has been created!");
};
exports.createFile = createFile;
//# sourceMappingURL=functions.js.map