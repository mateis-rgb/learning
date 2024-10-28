int * createArray (const int size)
{
    int temp[size];
    int k = 0;


    for (k = 0; k < size; k++)
    {
        temp[k] = 0;
    }

    return temp;
}