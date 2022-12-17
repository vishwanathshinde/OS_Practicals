#include<stdio.h>

int main()
{
    int Max[10][10], Allocation[10][10], Need[10][10];
    int p, r, i, j;

    printf("Enter the no of processes: ");
    scanf("%d",&p);

    printf("Enter the no of resources: ");
    scanf("%d",&r);

    printf("\nEnter the elements for Max matrix: \n");
    for(i=0; i<p; i++)
    {
        printf("Enter for process %d: ",i+1);
        for(j=0; j<r; j++)
            scanf("%d",&Max[i][j]);
    }

    printf("\nEnter the elements for Allocation matrix: \n");
    for(i=0; i<p; i++)
    {
        printf("Enter for process %d: ",i+1);
        for(j=0; j<r; j++)
            scanf("%d",&Allocation[i][j]);
    }

    printf("\nNeed Matrix: \n");
    for(i=0; i<p; i++)
    {
        for(j=0; j<r; j++)
        {
            Need[i][j] = Max[i][j] - Allocation[i][j];
            printf("%d\t",Need[i][j]);
        }
        printf("\n");
    }

}