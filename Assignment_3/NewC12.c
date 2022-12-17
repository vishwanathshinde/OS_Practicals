#include <stdio.h>

int main()
{
    int i, j, p, r, Need[10][10];
    p = 5; // processes
    r = 4; // resources

    int Allocation[5][4] = {{0, 0, 1, 2},  // P0 // Allocation Matrix
                            {1, 0, 0, 0},  // P1
                            {1, 3, 5, 4},  // P2
                            {0, 6, 3, 2},  // P3
                            {0, 0, 1, 4}}; // P4

    int Max[5][4] = {{0, 0, 1, 2},  // P0 // MAX Matrix
                     {1, 7, 5, 0},  // P1
                     {2, 3, 5, 6},  // P2
                     {0, 6, 5, 2},  // P3
                     {0, 6, 5, 6}}; // P4

    int Availaible[4] = {1, 5, 2, 0}; // Available Resources

    printf("Need matrix is: \n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            Need[i][j] = Max[i][j] - Allocation[i][j];
            printf("%d\t", Need[i][j]);
        }
        printf("\n");
    }

    int k = 0, flag;
    int finish[10], safe_seq[10];

    for (i = 0; i < p; i++)
    {
        finish[i] = 0; // Declare as all processes are incomplete
    }

    for (i = 0; i < p; i++)
    {
        flag = 0;

        if (finish[i] == 0) // Execute incomplete processes
        {
            for (j = 0; j < r; j++) // check a need of each process
            {
                if (Need[i][j] > Availaible[j])
                {
                    flag = 1; // Break a loop as need is greater than avail and go to next process
                    break;
                }
            }
            if (flag == 0) // need is lesser than avail so complete process
            {
                finish[i] = 1;
                safe_seq[k] = i;
                k++;
                // add allocated resources of finished process in available resources
                for (j = 0; j < r; j++)
                    Availaible[j] += Allocation[i][j];
                // start checking from first process again
                i = -1;
            }
        }
    }
    flag = 0; // check all processes are complete

    for (i = 0; i < p; i++)
    {
        if (finish[i] == 0)
        {
            printf("\nThe system is in deadlock");
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("\nThe system is in safe state! \n Safe sequence is: ");
        for (i = 0; i < p; i++)
        {
            printf("P%d ", safe_seq[i]);
        }
    }
    return 0;
}