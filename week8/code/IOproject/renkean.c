#include<fcntl.h>
#include<sys/stat.h>
#include<syslog.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 128
int fileright();
int fileright()
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
int main()
{
FILE *fp;
int perfect;
int perfect1;
int choice;
char buffer[MAX];
char buffer1[MAX];
char* path="/bin/ls";
char* argv[4]={"ls","-l","test1.txt",NULL};
while(1)
{
printf("-----------------------------------\n");
printf("0. 退出\n");
printf("1. 创建新文件\n");
printf("2. 写文件\n");
printf("3. 读文件\n");
printf("4. 修改文件权限\n");
printf("5. 查看当前文件的权限修改文件权限\n");
printf("-----------------------------------\n");
printf("Please input your choice(0-6):");
scanf("%d",&choice);
switch(choice)
{
case 0:
fclose(fp);
return 0;
exit(0);
case 1:
fp=fopen("test1.txt","w+");
if(fp==NULL)
{
printf("failed created files\n\n");
}
else
{
printf("successed created files\n\n");
}
fclose(fp);
break;
case 2:
memset(buffer,0,sizeof(buffer));
fp=fopen("test1.txt","a");
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
break;
case 3:
fp=fopen("test1.txt","r+");
fread(buffer1,sizeof(char),MAX,fp);
printf("%s\n",buffer1);
fclose(fp);
break;
case 4:
fileright();
break;
case 5:
execv(path,argv);
break;
default:
printf("You have a wrong choice!\n"); }
}
}
