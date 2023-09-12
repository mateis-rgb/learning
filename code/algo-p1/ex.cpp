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

int exo2_21 () {
    float note;

    cout << "Entrez un nombre : ";
    cin >> note;

    if (note < 0 || note > 20) {
        cout << "Note incorrecte : " << note << endl;
    }
    else {
        cout << "Note correcte : " << note << endl;
    }

    return 0;
}

int exo2_22 () {
    float note;

    cout << "Entrez un nombre : ";
    cin >> note;

    if (note < 0) {
        if (note > 20) {
            cout << "Note incorrecte : " << note << endl;
        }
    }
    else {
        cout << "Note correcte : " << note << endl;
    }

    return 0;
}

int exo2_4 () {
    int a, b, c, delta;

    cout << "Définissez les coéfissiants de la fonction ax^2 + bx + c = 0 : " << endl;
    
    cout << "a : ";
    cin >> a;

    cout << "b : ";
    cin >> b;

    cout << "c : ";
    cin >> c;

    delta = b*b - 4*a*c;

    if (delta < 0) {
        cout << "Le discriminant est négatif, il est donc impossible de calculer les racines dans IR";
    }
    else if (delta == 0) {
        float x = -b / 2*a;

        cout << "Le discriminant est égal à 0, ainsi la racine dans IR x = " << x;
    }
    else {
        float x1 = (-b-sqrt(delta)) / 2*a;
        float x2 = (-b+sqrt(delta)) / 2*a;

        cout << "Le discriminant est supérieur à 0, ainsi les deux racines dans IR x1 = " << x1 << " et x2 = " << x2;
    }


    return 0;
}

int main () {
    exo2_4();

    return 0;
}
