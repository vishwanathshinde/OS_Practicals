// Banker's Algorithm
#include <stdio.h>
int main()
{
    // P0, P1, P2, P3, P4 are the Process names here

    int p, r, i, j, k;
    p = 5;                                 // Number of processes
    r = 4;                                 // Number of resources
    int Allocation[5][4] = {{0, 1, 0, 2},  // P0 // Allocation Matrix
                            {1, 0, 0, 0},  // P1
                            {1, 3, 5, 4},  // P2
                            {0, 6, 3, 2},  // P3
                            {0, 0, 1, 4}}; // P4

    int Max[5][4] = {{0, 0, 1, 2},  // P0 // MAX Matrix
                     {1, 7, 5, 0},  // P1
                     {2, 3, 5, 6},  // P2
                     {0, 6, 5, 2},  // P3
                     {0, 6, 5, 6}}; // P4

    int Available[4] = {1, 5, 2, 0}; // Available Resources

    int finish[10], safe_sequence[10], ind = 0;

    for (i = 0; i < p; i++)
    {
        finish[i] = 0;
    }
    int need[10][10];
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
            need[i][j] = Max[i][j] - Allocation[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < p; i++)
        {
            if (finish[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < r; j++)
                {
                    if (need[i][j] > Available[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    safe_sequence[ind++] = i;
                    for (y = 0; y < r; y++)
                        Available[y] += Allocation[i][y];
                    finish[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < p; i++)
    {
        if (finish[i] == 0)
        {
            flag = 0;
            printf("The following system is not safe");
            break;
        }
    }

    if (flag == 1)
    {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < p - 1; i++)
            printf(" P%d ->", safe_sequence[i]);
        printf(" P%d", safe_sequence[p - 1]);
    }
    return (0);
}
