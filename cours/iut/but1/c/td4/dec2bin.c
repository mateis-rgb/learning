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
    // int dec = 19;
    // char * bin = dec2bin(dec);

    // printf("%d en binaire donne %s", dec, bin);

    char * a = "to";
    char * b = "to";
    char * cat = concat(a, b);


    printf("%s + %s = %s", a, b, cat);

    return 0;
}

char * concat (char * string1, char * string2)
{
    char * stringTemp = string1;

    int i = 0;
    int j = strlen(stringTemp);
    int str2len = strlen(string2);

    for (i = 0; i < str2len; i++)
    {
        stringTemp[i+j] = string2[i];
    }

    stringTemp[i+j] = '\0';

    return stringTemp;
}


// char * dec2bin (int n)
// {
//     if (n == 0) return "0";
//     if (n == 1) return "1";

//     return concat(n % 2 == 0 ? "0" : "1", dec2bin(n/2));
// } 
