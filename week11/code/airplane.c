#include <sys/types.h>                                    
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int num = 0;
    printf("fork now\n");
    int fd = open("forktest.txt", O_RDWR | O_CREAT, 0600);
    //pid_t pid = fork();
    pid_t pid = vfork();
    if (pid < 0)
    {
        printf("fork fail\n");
        exit(-1);
    }
    if (pid == 0)
    {
        num = 1;
        char* buf = "this is son process.";
        write(fd, buf, strlen(buf));
    }
    else
    {
        //num = 2;
        char* buf = "this is father process.";
        write(fd, buf, strlen(buf));
    }
    printf("num is:%d\n", num);
    close(fd);
    exit(0);
}
