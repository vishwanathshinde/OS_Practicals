#include <stdio.h>

int n, ari[10], bur[10], total = 0, i, j, small, temp, procs[100], k, waiting[10], finish[10];
float tavg = 0.0, wavg = 0.0;

void getdata();
void calculate();
void chart();

void getdata()
{
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time of process %d:\t", i);
        scanf("%d", &ari[i]);
        printf("Enter the Burst time of process %d:\t", i);
        scanf("%d", &bur[i]);

        waiting[i] = 0;
        total += bur[i];
    }
}

void calculate()
{
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ari[i] > ari[j])
            {
                temp = ari[i];
                ari[i] = ari[j];
                ari[j] = temp;
                temp = bur[i];
                bur[i] = bur[j];
                bur[j] = temp;
            }
        }
    }

    for (i = 0; i < total; i++)
    {
        small = 3200;

        for (j = 0; j < n; j++)
        {
            if ((bur[j] != 0) && (ari[j] <= i) && (bur[j] < small))
            {
                small = bur[j];
                k = j;
            }
        }
        bur[k]--;
        procs[i] = k;
    }

    k = 0;

    for (i = 0; i < total; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (procs[i] == j)
            {
                finish[j] = i;
                waiting[j]++;
            }
        }
    }
}

void chart()
{
    for (i = 0; i < n; i++)
    {
        printf("\n Process %d:- Finish Time: %d TurnAroundTime: %d WaitingTime: %d\n",
               i + 1, finish[i] + 1, (finish[i] - ari[i]) + 1, (((finish[i] + 1) - waiting[i]) - ari[i]));

        wavg = wavg + (((finish[i] + 1) - waiting[i]) - ari[i]);

        tavg = tavg + ((finish[i] - ari[i]) + 1);
    }
    printf("\n WAvG: \t%f\n TAVG: \t%f\n", (wavg / n), (tavg / n));

}

int main()
{
    getdata();
    calculate();
    chart();
}