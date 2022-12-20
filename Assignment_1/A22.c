#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int ac, char *av[])
{
    printf("We are in A22.c\n");
    printf("PID of A22.c : %d\n", getpid());
    return 0;
}