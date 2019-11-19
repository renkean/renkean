#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t pid;
	FILE *fp;
	int val=0;
	fp=fopen("an.dat","w+");
	if(fp==NULL)
		perror("failed to open files!\n");
	fprintf(fp,"调用vfork之前,val=%d\n",val);
	pid=vfork();
	if(pid<0)
	{
		perror("vfork error!\n");
		_exit(0);
	}
	else if(pid==0)
	{
		fprintf(fp,"子进程,val值变化之前,val=%d---pid:%d\n",val,getpid());
		val++;
		fprintf(fp,"子进程,val=%d---pid:%d\n",val,getpid());
		_exit(0);
	}
	else
	{

		fprintf(fp,"父进程,val=%d---pid:%d\n",val,getpid());
	}
		fclose(fp);
		return 0;
}
