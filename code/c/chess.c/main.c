#include <stdio.h>
#include <assert.h>

typedef struct Piece
{
	char id;
	char * name;
	char color;
} Piece;

void displayGrid (Piece grid[8][8])
{
	int i = 0;
	int j = 0;
	char toDisplay = '0';

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
	int k = 0;

	for (k = 0; k < 8; k++)
	{
		Piece pionB = {1, "pion", 0};
		Piece pionN = {1, "pion", 1};
		grid[1][k] = pionB;
		grid[6][k] = pionN;
	}

	
}


int main (void)
{ 
	Piece grid[8][8];
	
	generateGrid(grid);
	
	displayGrid(grid);

	initGrid(grid);

	displayGrid(grid);

	return 0;
}
