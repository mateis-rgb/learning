#include <iostream>
#include <math.h>
#include <complex>
#include <string>
#include <array>

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
	int n, rep;

	cout << "Entrez un nombre dont vous voulez avoir la table de multiplication ainsi que le nombre de multiplication que vous voulez : " << endl;
	cin >> n >> rep;

	for (int k = 0; k <= rep; k++) {
		cout << k << " x " << n << " = " << k * n << endl;
	}

	return 0;
}

int tp3_4 () {
	int taille;
	float currentNote, moyenne, min, max;

	do {
		cout << "Entrez une note entre 0 et 20 : ";
		cin >> currentNote;

		if (currentNote <= 20 && currentNote >= 0) {
			if (currentNote < min) {
				min = currentNote;
			}
			else if (currentNote > max) {
				max = currentNote;
			}
			
			moyenne += currentNote;
			taille++;
		}
	}
	while (currentNote == -1);

	moyenne = moyenne / taille;

	cout << "La moyenne des notes saisie est de " << moyenne << endl;
	cout << "La note minimum est de " << min << endl;
	cout << "La note maximum est de " << max << endl;

	return 0;
}

int tp3_5 () {
	int n;

	cout << "Entrez un nombre n : ";
	cin >> n;

	for (int k = 0; k < n; k++)
	{
		cout << "*";
	}

	cout << endl;

	for (int k = 0; k < n/2; k++)
	{
		cout << "*!";
	}

	if (n%2 == 0) {
		cout << endl;
	}
	else {
		cout << "*" << endl;
	}

	return 0;
}

int tp3_7() {
	for (int k = 100; k <= 999; k++) {
		string chaine = to_string(k);
		int a = chaine[0], b = chaine[1], c = chaine[2];

		if (a != b != c) {
			if ((a + b + c) == 9) {
				cout << k << endl;
			}
		}
	}

	return 0;
}

int tp4_4 () {
	// On définit les variables du programme
	const int taille = 10;
	float temp, ref, proche, distance;
	array<float, taille> tableau = {};

	// 
	for (int k = 0; k < taille; k++) {
		cout << "Entrez un nombre réel ("<< k+1 <<"/"<< taille <<") : ";
		cin >> temp;

		tableau[k] = temp;
	}

	cout << "Entrez un nombre réel qui sera dit référence : ";
	cin >> ref;
	
	proche = tableau[0];
	distance = abs(tableau[0] - ref);

	for (int k = 0; k < taille; k++) {
		if (abs(tableau[k] - ref) < distance) {
			proche = tableau[k];
			distance = abs(tableau[k] - ref);
		}
	}

	cout << "L'élément le plus proche de la référence ("<< ref <<") est : " << proche << endl;

	return 0;
}



int main () {
	tp4_4();

	return 0;
}