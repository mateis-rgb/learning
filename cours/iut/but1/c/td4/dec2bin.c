#include <stdio.h>
#include <string.h>

/**
 * @brief Concatenate a + b strings
 * 
 * @param a 
 * @param b 
 * @return char* 
 */
char * concat (char * a, char * b);

/**
 * @brief Convert dec number into binary
 * 
 * @param n 
 * @return char* 
 */
char * dec2bin (int n);

int main (void)
{
    int dec = 19;
    char * bin = dec2bin(dec);

    printf("%d en binaire donne %s", dec, bin);

    return 0;
}

char * concat (char * a, char * b)
{
    char * tempa = a;
    char * tempb = b;

    strcat(&tempa, &tempb);

    return a;
}


char * dec2bin (int n)
{
    if (n == 0) return "0";
    if (n == 1) return "1";

    return concat(n % 2 == 0 ? "0" : "1", dec2bin(n/2));
} 
