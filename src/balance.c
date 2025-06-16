#include "balance.h"


uint64_t getBalanceSats(char* address) {
	int addressLength = strlen(address);
	char* url = malloc(addressLength + 37);
	if (!url) {
		exit(1);
	}
	strcpy(url, "https://blockstream.info/api/address/");
	strcat(url, address);
	data balanceRaw = request(url);
	free(url);
	
	
	json_object *balanceJson = json_tokener_parse(balanceRaw.data);
	free(balanceRaw.data);

	json_object *stats;
	json_object *value;

	uint64_t fundedChainSum;
	uint64_t spentChainSum;

	if (!json_object_object_get_ex(balanceJson, "chain_stats", &stats)) {
		printf("Value \"chai_stats\" not available in json response");
	}
	if (!json_object_object_get_ex(stats, "funded_txo_sum", &value)) {
		printf("Value \"funded_txo_sum\" not available in json response");
	}
	fundedChainSum = json_object_get_uint64(value);
	if (!json_object_object_get_ex(stats, "spent_txo_sum", &value)) {
		printf("Value \"spent_txo_sum\" not available in json response");
	}
	spentChainSum = json_object_get_uint64(value);

	uint64_t balance = fundedChainSum - spentChainSum;

	return balance;
}
double getBalanceBTC(char* address) {
	uint64_t balanceSats = getBalanceSats(address);
	return balanceSats / 100000000.0;
}
