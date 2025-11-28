#include <math.h>
#include <stdio.h>

double polynome(double a, double b, double c, double * px1, double * px2); 


int main (void)
{
	return 0;
}


double polynome (double a, double b, double c, double* px1, double* px2)
{
	double delta = (b * b) - (4 * a * c);

	if (delta == 0)
	{
		*px1 = (-b) / (2 * a);
		*px2 = (-b) / (2 * a);
	}
	else if (delta > 0)
	{
		*px1 = ((-b) - sqrt(delta)) / (2 * a);
		*px2 = ((-b) + sqrt(delta)) / (2 * a);
	}

	return delta;
}
