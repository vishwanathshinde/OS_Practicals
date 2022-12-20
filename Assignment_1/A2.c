#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{
    int pid;
    pid=fork(); // fork() can't be used in windows. It will run online and in Linux
    char*args[] = {"Hello","World",NULL};
    if(pid==0)
    {
        printf("Child completed\n");
        printf("Child process id is %d\n", getpid());
        execv("./A22.exe",args);
    }
    else
    {
        printf("This is Parent Process\n");
        printf("Parent process id is %d\n", getpid());
    }
    return 0;
}