#include <stdio.h>
#include <curl/curl.h>


/**
 * @brief Send GET HTTP request
 * 
 * @param url 
 */
void get (char * url);

/**
 * @brief Send POST HTTP request
 * 
 * @param url 
 * @param data 
 */
void post (char * url, char * data);

void get (char * url)
{
	// On définit les variables
	CURL * curl;
	CURLcode res;

	// On initialise l'instance de curl
	curl = curl_easy_init();

	if (curl)
	{
		// On ajoute l'url comme option de curl
		curl_easy_setopt(curl, CURLOPT_URL, url);

		// On affiche le résultat si la response arrive
		res = curl_easy_perform(curl);
		printf("\n");

		// Si la response n'est pas OK
		if (res != CURLE_OK)
		{
			// On affiche l'erreur
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		}

		// On nettoie l'instance de curl
		curl_easy_cleanup(curl);
	}
}

void post (char * url, char * data)
{
	// On définit les variables
	CURL * curl;
	CURLcode res;

	// On initialise globalement curl
	curl_global_init(CURL_GLOBAL_ALL);

	// On initialise l'instance de curl
	curl = curl_easy_init();

	if (curl)
	{
		// On ajoute l'url dans les options la requete
		curl_easy_setopt(curl, CURLOPT_URL, url);

		// On ajoute les data dans les options de la requete
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

		// On affiche le résultat si la response arrive
		res = curl_easy_perform(curl);
		printf("\n");

		// Si la response n'est pas OK
		if (res != CURLE_OK)
		{
			// On affiche l'erreur
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		}

		// On nettoie l'instance de curl
		curl_easy_cleanup(curl);
	}
}
