#include"my.h"
int main()
{
	int pid;
	FILE *fp;
	fp=fopen("ren.dat","w+");
	if(fp==NULL)
		perror("failed to open files!\n");
	pid=fork();
	if(pid<0)
	{
		perror("failed to fork!\n");
		return -1;
	}
	else if(pid==0)
	{
		fprintf(fp,"child---pid:%d\n",getpid());
	}
	else
	{
		
		fprintf(fp,"parent---pid:%d\n",getpid());
	}
	fclose(fp);
}
