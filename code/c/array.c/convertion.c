char * toChar (int * array, int size) 
{
    char temp[size];
    int k = 0;


    for (k = 0; k < size; k++)
    {
        temp[k] = (char)array[k];
    }

    return temp;
}


float * toFloat (int * array, int size) 
{
    float temp[size];
    int k = 0;


    for (k = 0; k < size; k++)
    {
        temp[k] = (float)array[k];
    }

    return temp;
}


unsigned int * toUnsignedInt (int * array, int size) 
{
    unsigned int temp[size];
    int k = 0;


    for (k = 0; k < size; k++)
    {
        temp[k] = (unsigned int)array[k];
    }

    return temp;
}


unsigned char * toUnsignedChar (int * array, int size) 
{
    unsigned char temp[size];
    int k = 0;


    for (k = 0; k < size; k++)
    {
        temp[k] = (unsigned char)array[k];
    }

    return temp;
}