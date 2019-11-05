#include<stdio.h>
#include<stdlib.h>
void menu_1()
{
FILE *fp;
int choice;
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
exit(0);
case 1:
fileopen_1();
break;
case 2:
filewrite_1();
break;
case 3:
fileread_1();
break;
case 4:
fileright_1();
break;
case 5:
execv(path,argv);
break;
default:
printf("You have a wrong choice!\n"); }
}
}
