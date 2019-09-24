#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UNUMBER 100

struct arg{
	float ave;
	int sum;
};
void show(int * m, int n);
void urand(int * m, int n);
struct arg operater(int * m,int n);

