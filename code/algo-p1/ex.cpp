#include <iostream>
#include <math.h>

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

int exo2_1 () {
    int x;

    cout << "Entrez un entier x : ";
    cin >> x;

    if (x < 0) {
        x = -x;
    }

    if (x % 2 == 0) {
        cout << "La valeur absolue de x = " << x << " et il est pair" << endl;
    }
    else {
        cout << "La valeur absolue de x = " << x << " et il est impair" << endl;
    }

    return 0;
}

int exo2_2 () {
    float note;

    cout << "Entrez un nombre : ";
    cin >> note;

    if (note < 0 || note > 20) {
        cout << "Note incorrecte : " << note << endl;
        return 0;
    }

    cout << "Note correcte : " << note << endl;
    return 0;
}

int main () {
    exo2_2();

    return 0;
}
