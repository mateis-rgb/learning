#include <stdio.h>
#include <string.h>

#include "./gui.c"
#include "./request.c"

int main (void)
{
	// char * url_get = "https://url-example.com/api/json/get/?a=cool&toto=tata";
	// char * url_post = "https://url-example.com/api/json/post/";
	// char* data_post = "a=toto&toto=cool&";

	char url[256];
	char body[512];
	char method = 0;
	char dontWantToQuit = 1;

	clearScreen();

	while (dontWantToQuit != 0)
	{
		logo();

		method = askForMethod();

		switch (method)
		{
			case -1: // Quit
				dontWantToQuit = 0;
				
				break;
				
			case 0: // Help
				clearScreen();

				logo();

				// On demande dans help si on veut quitter le programme
				dontWantToQuit = help();

				if (dontWantToQuit == 1) clearScreen();

				break;
			
			case 1: // GET
				strcpy(url, askForUrl());

				clearScreen();

				printf("l'url passee est %s\n", url);
				printf("le contenu de la reponse est : \n=> ");

				get(url);

				dontWantToQuit = retry();

				break;
			
			case 2: // POST
				strcpy(url, askForUrl());
				strcpy(body, askForPostBody());

				clearScreen();

				printf("l'url passee est %s\n", url);
				printf("le body de la requete est : %s\n", body);
				printf("le contenu de la reponse est : \n=>");

				post(url, body);

				dontWantToQuit = retry();

				break;

			case 3: // Clear screen
				clearScreen();

				break;
		}
	}

	return 0;
}
