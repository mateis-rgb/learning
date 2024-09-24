#include "./gui.c"
#include "./request.c"
#include "./types.c"

int main (void)
{
	char * url = "https://url-example.com/api/json/get/?a=cool&toto=tata";

	Response response;


	logo();

	// askToUrl(url);



	get(url, &response);

	// "https://url-example.com/api/json/get/?a=cool&toto=tata"

	return 0;
}
