#include<stdio.h>

int main()
{
    int Max[10][10] , Allocation[10][10] , Need[10][10] , Available[10];
    int i, j, p, r, c;

    printf("Enter no of processes: ");
    scanf("%d",&p);

    printf("Enter no of resources: ");
    scanf("%d",&r);

    printf("\nEnter the elements of Max matrix: \n");
    for(i=0; i<p; i++)
    {
        printf("Enter for process %d: ",i+1);
        for(j=0; j<r; j++)
            scanf("%d",&Max[i][j]);       
    }

    printf("\nEnter the elements of Allocation Matrix: \n");
    for(i=0; i<p; i++)
    {
        printf("Enter for process %d: ",i+1);
        for(j=0; j<r; j++)
            scanf("%d",&Allocation[i][j]);
    }

    do
    {
        printf("\n-------------------------------\n1. To enter available\n2. To display Allocation and Max\n3. To calculate Need Matrix\n4. To display available\n-------------------------------\n");
        printf("\nEnter your choice 1,2,3,4 : ");
        scanf("%d",&c);

        switch(c)
        {
            case 1:
                printf("\nEnter elements of Available Matrix: ");
                for(j=0; j<r; j++)
                    scanf("%d",&Available[j]);
            break;

            case 2:
                printf("\nAllocation matrix is: \n");
                for(i=0; i<p; i++)
                {
                    for(j=0; j<r; j++)
                        printf("%d\t",Allocation[i][j]);
                    printf("\n");
                }
                printf("\nMax matrix is: \n");
                for(i=0; i<p; i++)
                {
                    for(j=0; j<r; j++)
                        printf("%d\t",Max[i][j]);
                    printf("\n");
                }
            break;

            case 3:
                printf("\nNeed matrix is: \n");
                for(i=0; i<p; i++)
                {
                    for(j=0; j<r; j++)
                    {
                        Need[i][j] = Max[i][j] - Allocation[i][j];
                        printf("%d\t",Need[i][j]);
                    }
                    printf("\n");
                }
            break;

            case 4:
                printf("\nAvailable matrix is: \n");
                for(j=0; j<r; j++)
                {
                    printf("%d\t",Available[j]);
                }
            break;
        }
    } 
    while(c!=0);
    return 0;
}