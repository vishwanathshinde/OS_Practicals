#include <stdio.h>
#include <string.h>
struct job
{
    char name[20];
    int at, bt, ct, tat, wt, st, tbt;
} job[10];
int n, i, j;
float total_tat = 0;
float total_wt = 0;
void take_input()
{
    printf("Enter the no. of process:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time of the process %d: ", i);
        scanf("%d", &job[i].at);
    }
    for (i = 0; i < n; i++)
    {
        printf("\n Enter the burst time of the process %d: ", i);
        scanf("%d", &job[i].bt);
        job[i].tbt = job[i].bt;
    }
    for (i = 0; i < n; i++)
    {
        printf("\n Enter the name of the process %d: ", i);
        scanf("%s", &job[i].name);
    }
}
void sort()
{
    struct job temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (job[i].at > job[j].at)
            {
                temp = job[i];
                job[i] = job[j];
                job[j] = temp;
            }
        }
    }
}
void process()
{
    int time = job[0].at;
    for (j = 0; j < n; j++)
    {
        job[j].st = time;
        printf("| %d %s", job[j].st, job[j].name);
        time = time + job[j].tbt;
        job[j].ct = time;
        job[j].tat = time - job[j].at;
        job[j].wt = job[j].tat - job[j].tbt;
        printf("%d |", time);
    }
}
void print_output()
{
    printf("\n\n");
    printf("\n----------------------------------------------------------------");
    printf("\n PNAME           AT           BT          TAT           WT      ");
    printf("\n----------------------------------------------------------------");
    for (i = 0; i < n; i++)
    {
        printf("\n%s     %8d          %5d    	    %5d        %4d", job[i].name, job[i].at, job[i].bt, job[i].tat, job[i].wt);
        total_tat = total_tat + (float)(job[i].tat);
        total_wt = (float)total_wt + (float)(job[i].wt);
    }
    printf("\n----------------------------------------------------------------");
    printf("\n The avg  of turn around time is: %f", total_tat / n);
    printf("\n The avg of the waiting time is: %f", total_wt / n);
}
void main()
{
    int i;
    take_input();
    sort();
    process();
    print_output();
    printf("\n\n");
    for (i = 0; i < n; i++)
    {
        job[i].tbt = job[i].bt = rand() % 10 + 1;
        job[i].at = job[i].ct + 2;
    }
    process();
    print_output();
}