#include <iostream>
#include <math.h>

using namespace std;

int tp1_4 () {
	const int c_anglais = 2, c_maths = 5, c_info = 3;
	
	float anglais, maths, info;
	float moyenne;

	cout << "Note en anglais (coeff. 2) : ";
	cin >> anglais;

	cout << "Note en mathématiques (coeff. 5) : ";
	cin >> maths;

	cout << "Note en informatiques (coeff. 3) : ";
	cin >> info;

	moyenne = (anglais * c_anglais + maths * c_maths + info * c_info) / (c_anglais + c_maths + c_info);

	cout << "Moyenne obtenue : " << moyenne << endl;

	return 0;
}  

int tp1_6 () {


	return 0;
}

int main () {
	tp1_6();

	return 0;
}