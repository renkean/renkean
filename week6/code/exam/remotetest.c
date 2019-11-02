#include"dylib.h"
#include<stdio.h>
#include<time.h>
int main()
{
int a[100];
init(a,100);
show(a,100);
printf("\n");
printf("max= %d\n",max(a,100));
printf("sum= %d\n",sum(a,100));
return 0;
}
