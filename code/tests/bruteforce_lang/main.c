// search_in_file.c
#include "../progress_bar.c"
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Codes de couleurs ANSI
#define RED "\033[31m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

typedef struct occurrence {
    int index;
    char line[1024];
} occurrence;

typedef struct searchResult {
    occurrence founded[1024];
    int index;
    double exec_time;
} searchResult;

int count_lines(FILE *file);
void clearScreen(void);
searchResult search_in_file(FILE *file, const char *search_string, int number_of_lines);
void display_results(const char *search_string, occurrence *founded, int index, double execution_time);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf(RED "[error]: " RESET "You must have two parameters\n> ./search_in_file <file_path> <search_string>\n");
        return 1;
    }

    const char *file_path = argv[1];
    const char *search_string = argv[2];

    searchResult result;

    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror(RED "[error]: " RESET "Error opening file");
        return 1;
    }

    printf(BLUE "[program]: " RESET "File has been loaded!\n");

    int nol = count_lines(file);
    printf(BLUE "[program]: " RESET "Number of lines of file: %d\n", nol);

    fclose(file);
    file = fopen(file_path, "r");
    if (file == NULL) {
        perror(RED "[error]: " RESET "Error opening file");
        return 1;
    }

    printf(BLUE "[program]: " RESET "Searching in file for \"%s\"...\n", search_string);
    result = search_in_file(file, search_string, nol);
    fclose(file);

    display_results(search_string, result.founded, result.index, result.exec_time);
    return 0;
}

void clearScreen(void) {
    system("clear");
}

int count_lines(FILE *file) {
    int ch = 0;
    int number_of_lines = 0;

    do {
        ch = fgetc(file);
        if (ch == '\n') {
            number_of_lines++;
        }
    } while (ch != EOF);

    if (ch != '\n' && number_of_lines != 0) {
        number_of_lines++;
    }

    return number_of_lines;
}

searchResult search_in_file(FILE *file, const char *search_string, int number_of_lines) {
    occurrence temp;
    searchResult result;
    clock_t start_time = clock();
    char line[1024];
    int line_number = 1;

    result.index = 0;
    printProgressBar(0);

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, search_string)) {
            temp.index = line_number;
            strcpy(temp.line, line);
            printProgressBar(line_number * 100 / number_of_lines);
            result.founded[result.index] = temp;
            result.index++;
        }
        line_number++;
    }

    printProgressBar(100);
    clock_t end_time = clock();
    result.exec_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    return result;
}

void display_results(const char *search_string, occurrence *founded, int index, double execution_time) {
    if (index == 0) {
        printf(RED "[error]: " RESET "String not found!\n");
    } else {
        for (int k = 0; k < index; k++) {
            printf(BLUE "[program]: " RESET "%d > %s == %s", founded[k].index, search_string, founded[k].line);
        }
    }

    printf(YELLOW "[info]: " RESET "Execution time: %f seconds\n", execution_time);
}
