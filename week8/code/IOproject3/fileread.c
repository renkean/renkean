#include<stdio.h>
#include<stdlib.h>
#define MAX 128
void fileread_1()
{
char buffer1[MAX];
FILE *fp=fopen("test1.txt","r+");
fread(buffer1,sizeof(char),MAX,fp);
printf("%s\n",buffer1);
fclose(fp);
}
