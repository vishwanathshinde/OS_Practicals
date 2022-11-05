#include<stdio.h>
#include<string.h>

int n, Bu[20], Twt, Ttt, A[10], wt[10], w;
float Awt, Att;
char pname[20][20],c[20][20];
void getdata();
void gantt_chart();
void calculate();
void fcfs();

void getdata()
{
    int i;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    for ( i = 1; i <= n; i++)
    {
        printf("Enter the process name: ");
        scanf("%s", &pname[i]);
        printf("Enter the Arrival time: ");
        scanf("%d", &A[i]);
        printf("Enter the Burst time: ");
        scanf("%d", &Bu[i]);
    }   
}

void gantt_chart()
{
    int i;
    printf("Gantt Chart\n");
    printf("\n---------------------------------\n");
    for ( i = 1; i <= n; i++)
        printf("   %s    |", pname[i]);
    printf("\n---------------------------------\n");
    printf("");
    for ( i = 1; i <=n; i++)
        printf("%d\t", wt[i]);
        printf("%d", wt[n]+Bu[n]);
}

void calculate()
{
    int i;
    wt[1]=0;
    for ( i = 2; i <= n; i++)
    {
        wt[i] = Bu[i-1] + wt[i-1];
    }
    for ( i = 1; i <= n; i++)
    {
        Twt=Twt+(wt[i]-A[i]);
        Ttt=Ttt+((wt[i]+Bu[i])-A[i]);
    }
    Att=(float)Ttt/n;
    Awt=(float)Twt/n;
    printf("\nAverage Turn around time=%3.2fms \n",Att);
    printf("\nAverage Waiting time=%3.2fms \n",Awt);
}

void fcfs()
{
    int i, j, temp, temp1;
    Twt=0;
    Ttt=0;
    for ( i = 1; i <=n; i++)
    {
        for (j=i+1; j<=n; j++)
        {
            if(A[i]>A[j])
            {
                temp=Bu[i];
                temp1=A[i];
                Bu[i]=Bu[j];
                A[i]=A[j];
                Bu[j]=temp;
                A[j]=temp1;
                strcpy(c[i],pname[i]);
                strcpy(pname[i],pname[j]);
                strcpy(pname[j],c[i]);
            }
        }       
    }
    calculate();
    gantt_chart();
}

int main()
{
    getdata();
    fcfs();
}