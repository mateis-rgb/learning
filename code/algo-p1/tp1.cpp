#include <iostream>
#include <math.h>

using namespace std;

int tp1_4 () {
	const int coeffs[3] = {2, 5, 3};
	float anglais, maths, info;
	float moyenne;

	cout << "Note en anglais (coeff. 2) : ";
	cin >> anglais;

	cout << "Note en mathématiques (coeff. 5) : ";
	cin >> maths;

	cout << "Note en informatiques (coeff. 3) : ";
	cin >> info;

	moyenne = (anglais * coeffs[0] + maths * coeffs[1] + info * coeffs[2]) / 3;

	cout << "Moyenne obtenue : " << moyenne << endl;

	return 0;
}  

int main () {
	return 0;
}