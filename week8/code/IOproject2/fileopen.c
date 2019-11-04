#include<stdio.h>
#include<stdlib.h>
void fileopen_1()
{
FILE *fp=fopen("test1.txt","w+");
if(fp==NULL)
{
printf("failed created files\n\n");
}
else
{
printf("successed created files\n\n");
}
fclose(fp);
}
