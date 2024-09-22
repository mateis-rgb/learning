#include "./gui.c"
#include "./request.c";

int main (void)
{
	char * url = "";

	logo();

	askToUrl(url);

	get(url);

	// "https://url-example.com/api/json/get/?a=cool&toto=tata"

	return 0;
}
