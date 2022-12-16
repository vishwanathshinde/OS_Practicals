#include<stdio.h>

int main()
{
  int Max[10][10], need[10][10], alloc[10][10], avail[10][10];
  int p,r,i,j;

  printf("Enter the no of processe: ");
  scanf("%d", &p);
  
  printf("Enter the no of resources: ");
  scanf("%d", &r);

  printf("Enter the no Max Matrix: ");
  for(i=0; i<p; i++)
  {
    printf("\nFor Process %d: ", i+1);
    for(j=0; j<r; j++)
      scanf("%d", &Max[i][j]);
  }

  printf("Enter the Allocation Matrix: ");
  for(i=0; i<p; i++)
  {
    printf("\nFor Process %d: ", i+1);
    for(j=0; j<r; j++)
      scanf("%d", &alloc[i][j]);
  }

  printf("Need Matrix:\n");
  for(i=0; i<p; i++)
  {
    for(j=0; j<r; j++)
    {
	need[i][j]=Max[i][j] - alloc[i][j];
        printf("%d\t",need[i][j]);
    }
  printf("\n");
  }
  return 0;
}

