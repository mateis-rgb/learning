#include <stdio.h>
#include <assert.h>

typedef struct Piece
{
	char id;
	char * name;
	char color;
} Piece;

typedef struct Coordonne
{
	int pos_x;
	int pos_y;
} Coordonne;


void displayGrid (Piece grid[8][8]);

void generateGrid (Piece grid[8][8]);

void initGrid (Piece grid[8][8]);

int move (Piece grid[8][8], Coordonne from, Coordonne to);

int canMove (Piece grid[8][8], Coordonne from, Coordonne to);

void echange (Piece grid[8][8], Piece removed[32], int removed_size, Coordonne from, Coordonne to);


int main (void)
{ 
	Piece grid[8][8];
	
	generateGrid(grid);
	
	displayGrid(grid);

	initGrid(grid);

	displayGrid(grid);

	return 0;
}


void displayGrid (Piece grid[8][8])
{
	int i = 0;
	int j = 0;

	printf("+---+---+---+---+---+---+---+---+---+\n");
	printf("|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |\n");
	printf("+---+---+---+---+---+---+---+---+---+\n");
	
	for (i = 0; i < 8; i++)
	{
		printf("| %c | ", 'A' + i);

		for (j = 0; j < 8; j++)
		{
			/**
			 * 1 = p = pion
			 * 2 = c = cavalier
			 * 3 = t = tour
			 * 4 = f = fou
			 * 5 = d = dame
			 * 6 = r = roi
			 */

			printf("%c | ", grid[i][j].name[0]);
		}

		printf("\n+---+---+---+---+---+---+---+---+---+\n");
	}
}

void generateGrid (Piece grid[8][8])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			Piece isNull = {0, "null", -1};

			grid[i][j] = isNull;
		}
	}
}

void initGrid (Piece grid[8][8])
{
	/**
	 * 1 = p = pion
	 * 2 = c = cavalier
	 * 3 = t = tour
	 * 4 = f = fou
	 * 5 = d = dame
	 * 6 = r = roi
	*/
	int k = 0;

	int placementB[8] = {3, 2, 4, 5, 6, 4, 2, 3};
	int placementN[8] = {3, 2, 4, 6, 5, 4, 2, 3};

	char * toName;

	// Placement des pions
	for (k = 0; k < 8; k++)
	{
		Piece pionB = {1, "pion", 0};
		Piece pionN = {1, "pion", 1};
		grid[1][k] = pionB;
		grid[6][k] = pionN;
	}

	// Placement des blancs
	for (k = 0; k < 8; k++)
	{
		if (placementB[k] == 1) toName = "pion";
		else if (placementB[k] == 2) toName = "cavalier";
		else if (placementB[k] == 3) toName = "tour";
		else if (placementB[k] == 4) toName = "fou";
		else if (placementB[k] == 5) toName = "dame";
		else if (placementB[k] == 6) toName = "roi";

		grid[0][k] = (Piece) {placementB[k], toName, 0};
	}

	// Placement des blancs
	for (k = 0; k < 8; k++)
	{
		if (placementN[k] == 1) toName = "pion";
		else if (placementN[k] == 2) toName = "cavalier";
		else if (placementN[k] == 3) toName = "tour";
		else if (placementN[k] == 4) toName = "fou";
		else if (placementN[k] == 5) toName = "dame";
		else if (placementN[k] == 6) toName = "roi";

		grid[7][k] = (Piece) {placementN[k], toName, 1};
	}
}


int move (Piece grid[8][8], Coordonne from, Coordonne to)
{
	return 0;
}

int canMove (Piece grid[8][8], Coordonne from, Coordonne to)
{
	if (grid[from.pos_x][from.pos_y].id == 1)
	{

	}

	else if (grid[from.pos_x][from.pos_y].id == 2)
	{

	}

	else if (grid[from.pos_x][from.pos_y].id == 3)
	{

	}

	else if (grid[from.pos_x][from.pos_y].id == 4)
	{

	}

	else if (grid[from.pos_x][from.pos_y].id == 5)
	{

	}

	else if (grid[from.pos_x][from.pos_y].id == 6)
	{

	}


	return 0;
}

void echange (Piece grid[8][8], Piece removed[32], int removed_size, Coordonne from, Coordonne to)
{

}
