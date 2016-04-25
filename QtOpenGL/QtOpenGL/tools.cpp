#include "tools.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include "string"

using std::cout;
using std::endl;
float *get_rand(){
	static bool k = false;
	float * f = new float[6];
	if (k == false){
		srand((unsigned)time(NULL));

	}
	k = true;
	//printf("%d\n",(unsigned)time(NULL)%10);
	for (int i = 0; i < 6; i++){
		f[i] = (rand() % 100) / (float)(100);
		//cout << f[i] << endl;
	}
	return f;
}

int stringToNumber(const char *string)
{
	int length = strlen(string);
	int number = 0;
	static int spos = 0;
	static int pos = 0;
	for (int i = 0; i < length; i++)
	{
		if (string[i] >= '0'&&string[i] <= '9'){
			number = number * 10 + (string[i] - '0');
		}


	}
	return number;
}