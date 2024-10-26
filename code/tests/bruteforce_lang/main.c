// search_in_file.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct occurrence
{
	int index;
	char line[1024];
} occurrence;

int count_lines (FILE * file);

void search_in_file (const char *file_path, const char *search_string, FILE *file);

void display_results (const char * search_string, occurrence * founded, int index, double execution_time);


int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("Usage: ./search_in_file <file_path> <search_string>\n");
		
		return 1;
	}

	const char *file_path = argv[1];
	const char *search_string = argv[2];

	FILE *file = fopen(file_path, "r");


	if (file == NULL) {
		perror("Error opening file");
		return 1;
	}
	int nol = count_lines(file);

	printf("lines : %d\n", nol);

	// search_in_file(file_path, search_string, file);

	fclose(file);

	return 0;
}


int count_lines (FILE * file)
{
	int ch = 0;
	int number_of_lines = 0;

	do
	{
		ch = fgetc(file);

		if (ch == '\n')
		{
			number_of_lines++;
		}
	} 
	while (ch != EOF);

	if (ch != '\n' && number_of_lines != 0)
	{
		number_of_lines++;
	}

	return number_of_lines;
}


void search_in_file(const char *file_path, const char *search_string, FILE *file) {
	occurrence temp;
	occurrence founded[1024];

	clock_t start_time = clock();
	
	char line[1024];
	
	int line_number = 1;
	int index = 0;

	while (fgets(line, sizeof(line), file)) {
		if (strstr(line, search_string)) {
			temp.index = line_number;
			strcpy(temp.line, line);

			founded[index] = temp;

			index++;
		}

		line_number++;
	}

	clock_t end_time = clock();
	double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

	display_results(search_string, founded, index, execution_time);
}


void display_results (const char * search_string, occurrence * founded, int index, double execution_time)
{
	int k = 0;

	if (index == 0)
	{
		printf("String not found!\n");
	}
	else
	{
		for (k = 0; k < index; k++)
		{
			printf("String found at line %d!\n", founded[k].index);
			printf("> %s == %s\n", search_string, founded[k].line);
		}
	}
		
	printf("Execution time: %f seconds\n", execution_time);
}
