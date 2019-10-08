#include "main.h"

//renkean 2019/10/5
int main(){

	struct timeval begin,end;
	struct timezone tz;
	struct arg args;

	int i;
	int num1[100],num2[100];

	int num1_size,num2_size;

	createRandomArray(num1,100);
	sleep(5);
	createRandomArray(num2,100);

//	quickSort(num1,100,sizeof(int));
//	quickSort(num1,100,sizeof(int));
	readArray(num1,100,"data.dat");

	/*
	args = analyzeArray(num2,100);
	printf("sum : %d    ave : %d\n",args.sum,args.ave);
	*/
printf("==============================\n");//line

	//quick sort
	num2_size = sizeof(num2)/sizeof(num2[0]);
	gettimeofday(&begin,&tz);
	quickSort(num2,num2_size,sizeof(int));
	gettimeofday(&end,&tz);
	printf("quick sort time:%ld(ms)\n",end.tv_usec - begin.tv_usec);
	show(num2,num2_size);

printf("==============================\n");//line

	//bubble sort
	num1_size = sizeof(num1)/sizeof(num1[0]);
	gettimeofday(&begin,&tz);
	bubbleSort(num1,num1_size);
	gettimeofday(&end,&tz);
	printf("bubble sort time:%ld(ms)\n",end.tv_usec - begin.tv_usec);
	show(num1,num1_size);

printf("==============================\n");//line
	
	return 0;

}
