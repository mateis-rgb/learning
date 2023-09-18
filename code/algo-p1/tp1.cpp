#include <iostream>
#include <math.h>
#include <complex>

using namespace std;

int tp1_4 () {
	const int c_anglais = 2, c_maths = 5, c_info = 3;
	
	float n_anglais, n_maths, n_info;
	float moyenne;

	cout << "Note en anglais (coeff. "<< c_anglais <<") : ";
	cin >> n_anglais;

	cout << "Note en mathématiques (coeff. "<< c_maths <<") : ";
	cin >> n_maths;

	cout << "Note en informatiques (coeff. "<< c_info <<") : ";
	cin >> n_info;

	moyenne = (n_anglais * c_anglais + n_maths * c_maths + n_info * c_info) / (c_anglais + c_maths + c_info);

	cout << "Moyenne obtenue : " << moyenne << endl;

	return 0;
}  

int tp1_6 () {
	int v1, v2, v3, v4, temp;

	cout << "Donnez 4 valeurs entières : ";
	cin >> v1 >> v2 >> v3 >> v4;

	temp = v1;

	v1 = v2;
	v2 = v3;
	v3 = v4;
	v4 = temp;

	cout << "Après le décalage, v1 = " << v1 << ", v2 = " << v2 << ", v3 = " << v3 << ", v4 = " << v4 << endl;

	return 0;
}

int tp2_3() {
	float x, fx;

	cout << "Donnez 1 valeur pour la fonction f(x) = (|x|+3x²)/((2/3)*x²-6) : ";
	cin >> x;

	// verifier que f est défini en x

	if (((2/3)*(x*x)-6) == 0) {
		cout << "f(x) n'est pas défini en x = " << x << endl;
		
		return 0;
	}

	fx = (abs(x) + 3 * (x*x)) / ((2/3)*(x*x)-6);

	cout << "La fonction f(x) par x = " << x << " est égal à : " << fx << endl;

	return 0;
}

int tp2_5() {
	int a, b, c;
	float delta;

    cout << "Définissez les coéfissiants de la fonction ax^2 + bx + c = 0 : " << endl;
    
    cout << "a : ";
    cin >> a;

    cout << "b : ";
    cin >> b;

    cout << "c : ";
    cin >> c;

    delta = b*b - 4*a*c;

    if (delta < 0) {
        complex<double> x1((-b / (2*a)), (sqrt(-delta) / (2 * a)));
		complex<double> x2((-b / (2*a)), (-sqrt(-delta) / (2 * a)));

        cout << "Le discriminant est inférieur à 0, ainsi les deux racines dans IC x1 = " << x1 << " et x2 = " << x2 << endl;
    }
    else if (delta == 0) {
        float x = -b / 2*a;

        cout << "Le discriminant est égal à 0, ainsi la racine dans IR x = " << x << endl;
    }
    else {
        float x1 = (-b-sqrt(delta)) / 2*a;
        float x2 = (-b+sqrt(delta)) / 2*a;

        cout << "Le discriminant est supérieur à 0, ainsi les deux racines dans IR x1 = " << x1 << " et x2 = " << x2 << endl;
    }

    return 0;
}

/*
int tp2_7 () {
	int a, b, rep;
	char* op;

	cout << "(Côté enseignant / parent) - Donnez deux nombres entiers : " << endl;
	cin >> a >> b;
	cout << "Donnez un signe d'opération (+, -, *, /) : ";
	cin >> op;

	cout << "(Côté élève) - Donnez la réponse du calcul suivant : " << a << " " << op << " " << b << endl;
	cin >> rep;

	if (op == "+" && rep == (a + b)) {
		cout << "Bravo" << endl; 
		return 0;
	}
	else if (op == "-" && rep == (a - b)) {
		cout << "Bravo" << endl;
		return 0;
	}
	else if (op == "/" && rep == (a / b)) {
		cout << "Bravo" << endl;
		return 0;
	}
	else if (op == "*" && rep == (a * b)) {
		cout << "Bravo" << endl;
		return 0;
	}

	cout << "Perdu" << endl;

	return 0;
}
*/

int tp3_2 () {
	int n;

	cout << "Entrez un nombre dont vous voulez avoir la table de multiplication : ";
	cin >> n;

	for (int k = 0; k <= 10; k++) {
		cout << k << " x " << n << " = " << k * n << endl;
	}

	return 0;
}

int tp3_4 () {
	int notes[] = {};
	int currentNote, tailleTableau, moyenne, min, max;

	do {
		cout << "Entrez une note entre 0 et 20 : ";
		cin >> currentNote;

		if (currentNote <= 20 && currentNote >= 0) {
			tailleTableau = sizeof(notes) / sizeof(int);

			if (currentNote < min) {
				min = currentNote;
			}
			else if (currentNote > max) {
				max = currentNote;
			}

			notes[tailleTableau] = currentNote;
			moyenne += currentNote;
		}
	}
	while (currentNote == -1);

	moyenne = moyenne / tailleTableau;

	cout << "La moyenne des notes saisie est de " << moyenne << endl;
	cout << "La note minimum est de " << min << endl;
	cout << "La note maximum est de " << max << endl;

	return 0;
}


int main () {
	tp3_4();

	return 0;
}
