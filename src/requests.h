#ifndef __REQUESTS_H__
#define __REQUESTS_H__

#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	size_t length;
	char* data;
}data;

size_t getData(void* ptr, size_t size, size_t nmemb, void* outData);

data request(char* url);


#endif //__REQUESTS_H__
