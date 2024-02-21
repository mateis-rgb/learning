#include <iostream>
#include <array>
#include <cmath>

unsigned int factorielle (unsigned int n)
{
	if (n == 0)
	{
		return 1;
	}

	return n * factorielle(n - 1);
}

int somme (int n)
{
	if (n == 0)
	{
		return 0;
	}

	return n + somme(n - 1);
}

int mystere (int n) // n >= 1
{
	if (n == 1)
	{
		return 1;
	}

	return mystere(n - 1) + 2 * (n - 1) + 1;
}

bool impaire (int);

bool pair (int n) // n >= 0
{
	if (n == 0)
	{
		return true;
	}

	return impaire (n - 1);
}

bool impaire (int n) // n >= 0
{
	if (n == 1)
	{
		return true;
	}
	
	return pair (n - 1);
}

unsigned int pgcd_v1 (unsigned int a, unsigned int b)
{
	if (a % b == 0)
	{
		return b;
	}

	return  pgcd_v1 (a , a % b);
}

unsigned int pgcd_v2 (unsigned int a, unsigned int b)
{
	if (a > b) return pgcd_v1(a, b);

	return pgcd_v1(b, a);
}

unsigned int pgcd_v3 (int a, int b)
{
	if (a < 0) return a = -a;
	if (b < 0) return b = -b;

	if (a == 0) return b;
	if (b == 0) return a;

	return pgcd_v2(a, b);
}

int zero (int a, int b)
{
	int m = b-a;

	return m;
}


struct point
{
	float x, y;
};

bool points_confondus (point a, point b)
{
	return a.x == b.x && a.y == b.y;
}

float distance (point a, point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

point milieu (point a, point b)
{
	point retour = { (b.x - a.x)/2, (b.y - a.y)/2 };

	return retour;
}

int main()
{
	point a = { 1.0, 4.0 };

	return 0;
}
