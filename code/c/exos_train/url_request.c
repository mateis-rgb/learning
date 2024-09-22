#include <curl/curl.h>
#include <stdio.h>

int main(void)
{
	CURL *curl = curl_easy_init();
	
	curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
	curl_easy_setopt(curl, CURLOPT_URL, 
		"https://url-example.com/api/json/get/?a=cool&toto=tata");
		
	curl_easy_perform(curl);

	return 0;
}
