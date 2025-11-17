#include <stdio.h>

int main (void)
{
	int Var, * pVar;

	pVar = &Var;

	*pVar = 0x118;

	printf("%d %d\n", Var, *pVar);
	printf("%p %p\n", &Var, pVar);

	return 0;
}
