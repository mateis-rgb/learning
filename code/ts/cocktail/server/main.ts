import express, { Application, Request, Response } from "express";
import dotenv from "dotenv";

dotenv.config();

const app: Application = express();
const port = process.env.PORT || 3000;

app.get("/", (req: Request, res: Response) => {
	res.json("Hello, world!");
});

app.listen(port, () => {
	console.log(`Server is listening at http://localhost:${port}`);
});
