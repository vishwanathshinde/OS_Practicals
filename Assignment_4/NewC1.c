#include <stdio.h>

int main()
{
    int i, j, k, np, nf, frame[10], ref_string[50], count[10], page_found[25], min, next = 0, fault = 0;

    printf("Enter the length of reference string: ");
    scanf("%d", &np);

    printf("Enter the reference strings: ");
    for (i = 0; i < np; i++)
    {
        scanf("%d", &ref_string[i]);
        page_found[i] = 0;
    }
    printf("Enter the no of frames: ");
    scanf("%d", &nf);

    for (i = 0; i < nf; i++)
    {
        count[i] = 0;
        frame[i] = -1;
    }
    printf("The LRU page replacement process is: \n");

    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nf; j++)
        {
            if (frame[j] == ref_string[i]) // page requested compared with existing content of frame
            {
                page_found[i] = 1;
                count[j] = next;
                next++;
            }
        }
        if (page_found[i] == 0) // page requested is not found in frame
        {
            if (i < nf)
            {
                frame[i] = ref_string[i];
                count[i] = next;
                next++;
            }
            else
            {
                min = 0;
                for (j = 0; j < nf; j++)
                {
                    if (count[min] > count[j])
                        min = j;
                }
                frame[min] = ref_string[i];
                count[min] = next;
                next++;
            }
            fault++;
        }
        for (j = 0; j < nf; j++)
            printf("%d\t", frame[j]);
        if (page_found[i] == 0)
            printf(" PF no %d: ", fault);
        printf("\n");
    }
    printf("\nThe number of page faults using LRU are %d", fault);
}