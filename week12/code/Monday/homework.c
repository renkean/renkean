#include"my.h"
#include<stdlib.h>
int count=0;
int main()
{
	pid_t p1,p2,p3;
	printf("parent fork first time\n");
	int i=0;
	int sum;
	char buf[4096];
	int pipefd[2];
	memset(buf,0,sizeof(buf));
	printf("buf:%s\n",buf);
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
			printf("child1 start\n");
			close(pipefd[0]);
			for(i=0;i<sizeof(buf);i++)
			{
				if(write(pipefd[1],i,sizeof(char))!=-1)
				{
				printf("write ok!\n");
				}
			}
			printf("buf1:%s\n",buf);
			close(pipefd[1]);			
			exit(99);
	}
	else
	{
		printf("parent fork second time\n");
		p2=fork();
		if(p2<0)
		{
			perror("fork failed\n");
			return -1;
		}
		else if(p2==0)
		{
				printf("child2 start\n");
				close(pipefd[1]);
				read(pipefd[0],buf,sizeof(buf));
				printf("child2 read from pipe: %s\n",buf);
				close(pipefd[0]);
				exit(34);
		}
		else
		{
			printf("parent fork third time\n");
			p3=fork();
			if(p3<0)
			{
				perror("fork failed\n");
				return -1;
			}
			else if(p3==0)
			{
				  printf("child3 start\n");
				  for(i=0;i<sizeof(buf);i++)
						sum+=i;
					printf("sum=%d\n",sum);
					exit(77);
			}
			else
			{
				printf("parent waiting\n");
				printf("parent pid=%d,count=%d\n",getpid(),count);
				return 0;
			}
}
}
	}
