#include "price.h"


uint64_t getPrice(char* currency) {
	int currencyLength = strlen(currency);
	char* url = malloc(currencyLength + 72);
	if (!url) {
		exit(1);
	}
	strcpy(url, "https://api.coingecko.com/api/v3/simple/price?ids=bitcoin&vs_currencies=");
	strcat(url, currency);
	data priceRaw = request(url);
	free(url);
	
	json_object* priceJson = json_tokener_parse(priceRaw.data);
	free(priceRaw.data);
	json_object* bitcoin;
	json_object* value;
	uint64_t price;

	if (!json_object_object_get_ex(priceJson, "bitcoin", &bitcoin)) {
		printf("Bitcoin information not available in json response");
	}
	if (!json_object_object_get_ex(bitcoin, currency, &value)) {
		printf("Currency %s not available in json response", currency);
	}
	price = json_object_get_uint64(value);
	return price;
}
