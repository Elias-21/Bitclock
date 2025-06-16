#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "balance.h"
#include "height.h"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("Invalid Number of Arguments\nExpected at least 2 got %i", argc);
		return 1;
	}
	if (strcmp(argv[1], "--height") == 0) {
		int height = getHeight();
		printf("{\"text\": \"%i\"}", height);

	}else if(strcmp(argv[1], "--balance-sats") == 0){
		uint64_t balance = getBalanceSats(argv[2]);
		printf("{\"text\": \"%" PRIu64 "\"}", balance);

	}else if(strcmp(argv[1], "--balance-btc") == 0){
		double balance = getBalanceBTC(argv[2]);
		printf("{\"text\": \"%f\"}", balance);

	}else {
		printf("Not a valid argument\n");
	}

	return 0;
}
