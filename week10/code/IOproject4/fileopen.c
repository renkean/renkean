#include<stdio.h>
#include<stdlib.h>
string fileopen_2()
{
char filename[9];
printf("输入文件名称:");
scanf("%s",filename);
FILE *fp=fopen(filename,"w+");
if(fp==NULL)
{
printf("failed created files\n\n");
}
else
{
printf("successed created files\n\n");
}
fclose(fp);
return filename;
}
