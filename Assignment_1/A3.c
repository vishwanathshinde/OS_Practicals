#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    int pid;
    pid=fork();

    if(pid==0)
    {
        printf("Child process running\n");
        execl("/bin/ls","ls","-l",NULL);
    }
    else
    {
        sleep(5);
        printf("This is Parent Process\n");
    }
    return 0;
}