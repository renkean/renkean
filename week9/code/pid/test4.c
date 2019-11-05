#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
char* argv[4]={"/home/renkean/git/linuxprogram.git/week9/code/pid/test","HELLO","WORLD",NULL};
int main()
{
printf("PID=%d,PPID=%d\n",getpid(),getppid());
execv(argv[0],argv);
printf("later");
return 0;
}
