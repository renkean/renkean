#include<stdio.h>
#include<stdlib.h>
#define MAX 128
void filewrite_1(char* filename)
{
int perfect;
char buffer[MAX];
FILE *fp=fopen("test1.txt","a");
memset(buffer,0,sizeof(buffer));
scanf("%s",buffer);
perfect=fwrite(buffer,strlen(buffer),1,fp);
if(perfect==1)
{
printf("successed write files\n\n");
}
else
{
printf("failed write files\n\n");
}
printf("%s\n",buffer);
fclose(fp);
}
