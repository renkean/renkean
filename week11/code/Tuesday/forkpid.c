#include"my.h"
int main()
{
	int i;
	int pid1,pid2;
	FILE *fp;
	fp=fopen("out.dat","w+");
	pid1=fork();
	pid2=fork();
	if(pid1<0 || pid2<0)
	{
		perror("failed to fork!\n");
		return -1;
	}
/*	else if(pid1==0)
	{
		for(i=0;i<10;i++)
		{
			fprintf(fp,"%d---pid:%d\n",i,getpid());
		}	
printf("1!\n");
	}
*/
	else if(pid2==0)
	{
		for(i=0;i<10;i++)
		{
			fprintf(fp,"%d---pid:%d\n",i,getpid());
		}
printf("2!\n");
	}
	else
	{
		printf("success!\n");
fclose(fp);
	}
}
