#include <stdio.h>
#include <string.h>

/**
 * @brief Convert dec number into binary
 * 
 * @param n 
 * @return char* 
 */
char * dec2bin (int n);

int main (void)
{
    // int dec = 19;
    // char * bin = dec2bin(dec);

    // printf("%d en binaire donne %s", dec, bin);

    char * a = "to1";
    char * b = "to2";
    char * cat = strcat(a, b);


    printf("%s + %s = %s", a, b, cat);

    return 0;
}


// char * dec2bin (int n)
// {
//     if (n == 0) return "0";
//     if (n == 1) return "1";

//     return concat(n % 2 == 0 ? "0" : "1", dec2bin(n/2));
// } 
