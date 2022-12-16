#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    int pid;
    pid=fork(); // fork() can't be used in windows. It will run online and in Linux

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