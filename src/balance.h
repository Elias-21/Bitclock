#ifndef __BALANCE_H__
#define __BALANCE_H__

#include <json-c/json.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "requests.h"


uint64_t getBalanceSats(char* address);
double getBalanceBTC(char* address);


#endif //__BALANCE_H__
