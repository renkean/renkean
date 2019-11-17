#include<stdio.h>
#include<stdlib.h>
int fileright_1()
{
int c;
FILE *fp=fopen("test1.txt","r+");
int fd=fileno(fp);
printf("---%d----\n",fd);
printf(" 0. 0700\n 1. 0400\n 2. 0200 \n 3. 0100\n ");
printf("Please input your choice(0-3):");
scanf("%d",&c);
switch(c)
{
case 0: fchmod(fd,0700);break;
case 1: fchmod(fd,0400);break;
case 2: fchmod(fd,0200);break;
case 3: fchmod(fd,0100);break;
default:printf("You have a wrong choice!\n");
}
fclose(fp);
}
