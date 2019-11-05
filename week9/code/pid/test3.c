#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int global1=0;
int global2=1;
int main()
{
int i=10;
static k=21;
pid_t pid=fork();
if(pid<0)
{
perror("创建子进程失败");
exit(0);
}
else if(pid==0)
{
printf("chlid:pid=%d,ppid=%d,address:i=%d,global1=%d,global2=%d\n",getpid(),getppid(),i,global1,global2);
global1=999;
global2=1000;
i=12;
k=19;
sleep(10);
printf("chlid:pid=%d,ppid=%d,address:i=%d,global1=%d,global2=%d\n",getpid(),getppid(),i,global1,global2);
exit(0);
}
else
{
printf("parent:pid=%d,ppid=%d,address:i=%d\n",getpid(),getppid(),i);
sleep(10);
printf("parent:address:i=%d,global1=%d,global2=%d\n",i,global1,global2);
}
}
