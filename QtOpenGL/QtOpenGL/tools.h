#pragma once

#define  SAFEDELETE(p) if(p){delete (p); (p) = NULL;}

#define  SAFEDELETES(p) if(p){delete [](p); (p) = NULL;}
#include <cstdlib>
#include <ctime>
float *get_rand();
int stringToNumber(const char *string);