#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
printf("PID=%d,PPID=%d\n",getpid(),getppid());
system("/home/renkean/git/linuxprogram.git/week9/code/pid/test1");
printf("after calling");
return 0;
}
