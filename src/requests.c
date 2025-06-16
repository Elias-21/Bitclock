#include "requests.h"


size_t getData(void* ptr, size_t size, size_t nmemb, void* outData) {
	data* out = (data*)outData;
	out->length = size * nmemb;
	out->data = malloc(out->length + 1);
	if (out->data == NULL) {
		exit(1);
	}
	memcpy(out->data, ptr, out->length);
	out->data[out->length] = '\0';
	return size * nmemb;
}


data request(char* url) {
	data out = {0};
	CURL* curl = curl_easy_init();
	if (!curl) {
		exit(1);
	}

	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getData);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);


	CURLcode res;
	res = curl_easy_perform(curl);
	if (res != CURLE_OK) {
		curl_easy_cleanup(curl);
		exit(1);
	}
	curl_easy_cleanup(curl);
	return out;
}
