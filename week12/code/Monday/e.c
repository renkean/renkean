#include"my.h"
#include<stdlib.h>
int count=0;
int main()
{
	pid_t p1,p2,p3;
	int i=0;
	int sum;
	char buf[4096];
	char buf1[4096];
	char buf2[8];
	int pipefd[2];
	memset(buf,0,sizeof(buf));
	memset(buf,0,sizeof(buf1));
	if(pipe(pipefd)<0)
	{
		perror("pipe failed.\n");
		return -1;
	}
	p1=fork();
	if(p1<0)
	{
		perror("fork failed\n");
		return -1;
	}
	else if(p1==0)
	{
		
		for(i=0;i<sizeof(buf);i++)
			sum+=i;
		printf("sum=%d\n",sum);	
		exit(99);
	}
	else
	{
		p2=fork();
		if(p2<0)
		{
			perror("fork failed\n");
			return -1;
		}
		else if(p2==0)
		{
				sleep(1);
				close(pipefd[1]);
				read(pipefd[0],buf1,sizeof(buf1));
				printf("buf1 read from pipe: %s\n",buf1);
				close(pipefd[0]);
				exit(34);
		}
		else
		{
			p3=fork();
			if(p3<0)
			{
				perror("fork failed\n");
				return -1;
			}
			else if(p3==0)
			{
				close(pipefd[0]);
				for(i=0;i<4096;i++)
				{
					sprintf(buf2,"%d\n",i);
			//		printf("buf2:%s\n",buf2);
					strcat(buf,buf2);
				}
				printf("buf:%s\n",buf);
				write(pipefd[1],buf,sizeof(buf));
				close(pipefd[1]);
				exit(77);
			}
			else
			{
				printf("parent finishing\n");
				return 0;
			}
}
}
	}
