#include <iostream>

using namespace std;

int exo1_1 () {
    int a, b;

    cout << "Entrez un entier : ";
    cin >> a;
 
    cout << "Entrez un autre entier : "; 
    cin >> b;

    cout << "Le produit de " << a << " et " << b << " est " << a * b << endl;

    return 0;
}

int exo1_3 () {
    float x, fx;

    cout << "Entrez une valeur : ";
    cin >> x;

    fx = (x*x - 3*x + 0.5) * (x-3);

    cout << "Par f(x) = (x^2 - 3x + 0.5)(x - 3), pour x = " << x << " f(" << x << ") = " << fx << endl;

    return 0;
}

int exo1_5 () {
    int v1, v2, v3;

    cout << "Entrez une valeur : ";
    cin >> v1;

    cout << "Entrez une autre valeur : ";
    cin >> v2;

    v3 = v1;
    v1 = v2;
    v2 = v3;

    cout << "La variable v1 est devenue : " << v1 << ", et la variable v2 est devenue : " << v2 << endl;

    return 0;
}

int main () {
    exo1_5();

    return 0;
}
