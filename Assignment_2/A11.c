#include <stdio.h>

int main()
{
    int i, p, j, n, bt[10], at[10], wt[10], tat[20], temp[20];
    float awt = 0, atat = 0;
    printf("Enter the no of process: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time of the process[%d]: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter the Burst time of the process[%d]: ", i + 1);
        scanf("%d", &bt[i]);

        temp[0] = 0;
    }
    printf("process\t Burst time\t Arrival time\t Waiting time\t Turn around time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        temp[i + 1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], at[i], wt[i], tat[i]);
    }

    //Gantt Chart
    for(i=1;i<= n; i++)
        printf("----------------");

    printf("\n");
    for(i=1; i<= n; i++)
    printf("|\tn%d\t",n[%d]);

    awt = awt / n;
    atat = atat / n;
    printf("Average waiting time: %f\n", awt);
    printf("Average Turn around time time: %f\n", atat);
}