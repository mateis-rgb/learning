#include <stdio.h>

#define BAR_WIDTH 50

void printProgressBar(int progress) {
    int pos = BAR_WIDTH * progress / 100;
    
	printf("[");
    
	for (int i = 0; i < BAR_WIDTH; i++) {
        if (i < pos) {
            printf("#");
        } else if (i == pos) {
            printf("#");
        } else {
            printf(" ");
        }
    }

    printf("] %d%%\r", progress);
    fflush(stdout); // Forcer l'affichage immédiat

    if (progress == 100) printf("\n\n");
}