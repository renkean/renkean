#include"my.h"
int main()
{
	int i;
	int pid;
	FILE *fp;
	fp=fopen("ren.dat","w+");
	pid=fork();
	if(pid<0)
	{
		perror("failed to fork!\n");
		return -1;
	}
	else if(pid==0)
	{
		for(i=0;i<10;i++)
		{
			fprintf(fp,"%d---pid:%d\n",i,getpid());
		}
	}
	else
	{
		for(i=0;i<10;i++)
		{
			fprintf(fp,"%d---pid:%d\n",i,getpid());
		}
		printf("success!\n");
		fclose(fp);
	}
}
