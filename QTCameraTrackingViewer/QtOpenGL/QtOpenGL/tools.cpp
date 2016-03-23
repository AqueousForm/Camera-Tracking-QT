#include "tools.h"
#include "stdio.h"

float *get_rand(){
	float f[6];
	static bool k = false;
	if (k == false){
		srand(time(NULL) );
	}
	k = true;
	printf("%d\n",(unsigned)time(NULL)%10);
	for (int i=0; i < 6;i++)
	f[i] = (rand() % 100) / (float)(100);

	return (f);
}