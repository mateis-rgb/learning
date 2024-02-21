#include <iostream>

int main()
{
    int e, u;

    do
    {
        std::cout << "Entrez un nombre entier positif: ";
        std::cin >> e;
    }
    while(e < 0);
    
    u = e;

    while (u != 1)
    {
        std::cout << u << ", ";

        if (u%2 == 0)
        {
            u = u/2;
        }
        else
        {
            u = (3*u) + 1;
        }
    }

    std::cout << u << ", ";

    return 0;
}