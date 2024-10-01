#include <regex.h>
#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main(void)
{
	char str[255];

	printf("Enter the website URL:\n");
	fgets(str, 100, stdin);
	if (!strcmp(str, "\n")) {
		printf("Empty URL ");
		exit(2);
	}

	regex_t regex;
	int reti;
	char msgbuf[100];

	/* Compile regular expression */
	reti = regcomp(&regex, "[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,3}(/[^[:space:]]*)?$", REG_EXTENDED);
	if (reti) {
		fprintf(stderr, "Could not compile regex\n");
		exit(3);
	}

	/* Execute regular expression */
	reti = regexec(&regex, str, 0, NULL, 0);
	if (!reti) {
		puts("Valid URL");
	} else if (reti == REG_NOMATCH) { //This else if always executes.
		puts("Invalid URL");
		exit(4);
	} else {
		regerror(reti, &regex, msgbuf, sizeof (msgbuf));
		fprintf(stderr, "Regex match failed: %s\n", msgbuf);
		exit(5);
	}

	/* Free compiled regular expression if you want to use the regex_t again */
	regfree(&regex);
}

// /**
//  * @brief Return if url is valid
//  * 
//  * @param url 
//  * @return int 
//  */
// int isURLValid (char * url);

// /**
//  * @brief Return if is a youtube url
//  * 
//  * @param url 
//  * @return int 
//  */
// int isYoutubeURLValid (char * url);

// int isURLValid (char * url)
// {
// 	int value;
//     char * pattern = "^(?:http(s)?://)?[\w.-]+(?:\.[\w\.-]+)+[\w\-\._~:/?#[\]@!\$&'\(\)\*\+,;=.]+$";
// 	regex_t reegex;

// 	value = regcomp(&reegex, pattern, 0);
// 	value = regexec(&reegex, url, 0, NULL, 0);

// 	return value;
// }

// int isYoutubeURLValid (char * url)
// {
// 	return 0;
// }

// int main (void)
// {
// 	char * url;

// 	printf("entrez une url : ");
// 	scanf("%s", &url);

// 	printf("l'url est valide : %d", isURLValid(url));

// 	return 0;
// }
