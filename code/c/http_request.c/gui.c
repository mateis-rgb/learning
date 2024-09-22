#include <stdio.h>
#include <stdlib.h>

void logo (void)
{
	system("clear");

	printf(" _     _   _                                           _\n");         
	printf("| |__ | |_| |_ _ __     _ __ ___  __ _ _   _  ___  ___| |_   ___ \n"); 
	printf("| '_ \\| __| __| '_ \\   | '__/ _ \\/ _` | | | |/ _ \\/ __| __| / __|\n");
	printf("| | | | |_| |_| |_) |  | | |  __/ (_| | |_| |  __/\\__ \\ |_ | (__ \n");
	printf("|_| |_|\\__|\\__| .__/___|_|  \\___|\\__, |\\__,_|\\___||___/\\__(_)___|\n");
	printf("              |_| |_____|           |_|                          \n");
}

void askToUrl (char * url)
{
	printf("Entrez l'url que vous voulez tester : ");
	scanf("%s" &url);
}
