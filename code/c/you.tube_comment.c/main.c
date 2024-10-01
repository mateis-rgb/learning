#include <stdio.h>
#include <string.h>

#include "./gui.c"
#include "./request.c"

int main (void)
{
	char url[256];
	char dontWantToQuit = 1;

	clearScreen();

	logo();

	askForMethod();

	return 0;
}
