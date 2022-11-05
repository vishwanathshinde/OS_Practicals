#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int i;
    int AT[10], BT[10], WT[10], TT[10], n;
    int burst=0, cmp_T;
    float Avg_Wt, Avg_TT, Total=0;
    printf("Enter no of processes: \n");
    scanf("%d",&n);
    printf("Enter Arrival Time and Burst Time: \n");
    printf("AT\tBT\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &AT[i], &BT[i]);
    }
    
    for (i = 0; i < n; i++)
    {
        if (i==0)
            WT[i]=AT[i];
        else
            WT[i]=burst - AT[i];
        burst += BT[i];
        Total += WT[i];
    }
    
    Avg_Wt = Total/n;
    cmp_T = 0;
    Total = 0;
    
    for (i = 0; i < n; i++)
    {
        cmp_T += BT[i];
        TT[i] = cmp_T - AT[i];
        Total += TT[i];
    }
    
    Avg_TT = Total/n;

    printf("Process , Waiting-Time , TurnAroundTime\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\n", i+1, WT[i], TT[i]);
    }
    
    printf("Average Waiting time is: %f\n",Avg_Wt);
    printf("Average TurnAroundTime time is: %f\n",Avg_TT);
}