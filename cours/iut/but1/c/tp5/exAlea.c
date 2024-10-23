#include <stdio.h>
#include <stdlib.h>

unsigned long predict (int n, int seed);

int main (void)
{
    int k = 0;
    printf("\n\n");

    srand(0);

    printf("long: %d\nint: %d\n\n", sizeof(long), sizeof(int));

    printf("RAND(): \n");
    for (k = 0; k < 20; k++) printf("%d ", rand());

    printf("\n\nPREDICT(): \n");
    for (k = 1; k < 20; k++) printf("%lu ", predict(k, 0));

    printf("\n\n");
    return 0;
}

unsigned long predict (int n, int seed)
{
    unsigned long Rn1 = seed;
    int k = 0;

    for (k = 0; k < n; k++)
    {
        Rn1 = 214013 * Rn1 + 2531011;
    }

    // return ((Rn1&0x7FFFFFFF)>>16);
    return ((Rn1>>16) & 0x7FFF);
}
