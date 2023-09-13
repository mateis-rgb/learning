#include <iostream>
#include <math.h>

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

int main () {
	tp2_3();

	return 0;
}