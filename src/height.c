#include "height.h"



int getHeight() {
	data heightRaw = request("https://blockstream.info/api/blocks/tip/height");
	char* end;
	long height = strtol(heightRaw.data, &end, 10);
	if (heightRaw.data == end) {
		free(heightRaw.data);
		return -1;
	}
	free(heightRaw.data);
	return (int)height;
}
