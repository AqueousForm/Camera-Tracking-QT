#include "tools.h"
float *get_rand(){
	float f[6];
	srand((unsigned)time(NULL));
	for (int i=0; i < 6;i++)
	f[i] = (rand() % 10) / (float)(10);

	return (f);
}