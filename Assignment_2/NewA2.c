#include <stdio.h>
#include <string.h>

int n, at[20], bt[20], tat[20], wt[20], temp[20];
float Awt, Atat;
char pname[20][20], cname[20][20];

void getdata();
void fcfs();
void calculate();
void gantt_chart();
void chart();

void getdata()
{
    int i;
    printf("\nEnter the number of process:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter the process name:");
        scanf("%s", &pname[i]);
        printf("Enter a arrival time %s= ", pname[i]);
        scanf("%d", &at[i]);
        printf("Enter a Burst time %s= ", pname[i]);
        scanf("%d", &bt[i]);
    }
}

void fcfs()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (at[i] > at[j])
            {
                int temp = bt[i];
                int temp1 = at[i];
                bt[i] = bt[j];
                at[i] = at[j];

                at[j] = temp1;
                bt[j] = temp;


                strcpy(cname[i], pname[i]);
                strcpy(pname[i], pname[j]);
                strcpy(pname[j], cname[i]);
            }
        }
    }
}

void calculate()
{
    wt[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

}

void gantt_chart()
{
    printf("\nGantt Chart");
    printf("\n|------------------------|\n");
    for(int i=1; i<=n; i++)
        printf("  %s  |",pname[i]);
    printf("\n|------------------------|\n");
    printf("");
    for(int i=1; i<=n; i++)
        printf("%d\t",wt[i]);
    printf("%d",wt[n]+bt[n]);
}

void chart()
{
    printf("\nProcess\tArrival_Time\tBurst_time\tT_A_T\tWaiting_Time\n");

    for (int i = 1; i <= n; i++)
    {
        tat[i] = 0;
        wt[i] = 0;
        temp[i + 1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        Awt=Awt+wt[i];
        Atat=Atat+tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i, at[i], bt[i], tat[i], wt[i]);
    }
    Awt=Awt/n;
    Atat=Atat/n;
    printf("\nAverage Witing time: %3.2fms\n", Awt);
    printf("\nAverage turn around time: %3.2fms\n", Atat);
}

int main()
{
    getdata();
    fcfs();
    calculate();
    gantt_chart();
    chart();
}