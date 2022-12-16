#include<stdio.h>
#include<string.h>

int main()
{
  int num,i,j,n,m,max[10][10], Need[10][10], avail[10][10], alloc[10][10];
  printf("Enter the no of processe and resources: ");
  scanf("%d%d", &i, &j);

  printf("Enter the elemens for Allocation Matrix: ");
  for(n=0; n<i; n++)
  {
    for(m=0; m<j; m++)
      scanf("%d", &alloc[n][m]);
  }

  printf("Enter the elements for Max Matrix: ");
  for(n=0; n<i; n++)
  {
    for(m=0; m<j; m++)
      scanf("%d", &max[n][m]);
  }

  do
  {
    printf("Enter a case(1,2,3,4): ");
    scanf("%d", &num);
    switch(num)
    {
	case 1:
		printf("Enter the elements for Avail Matrix: ");
		for(m=0; m<j; m++)
		scanf("%d", &avail[m]);
		break;
	case 2:
		printf("Allocation Matrix: ");
		for(n=0; n<i; n++)
		{
		  for(m=0; m<j; m++)
		  {
		    printf("%d\t", alloc[n][m]);
		  }
		  printf("\n");
		}	

		printf("Max Matrix: ");
		for(n=0; n<i; n++)
		{
		  for(m=0; m<j; m++)
		  {
		    printf("%d\t", max[n][m]);
		  }
		  printf("\n");
		}
		break;

	case 3:
		printf("Need Content Matrix: ");
		for(n=0; n<i; n++)
		{
		  for(m=0; m<j; m++)
		  {
		    Need[n][m]=max[n][m] - alloc[n][m];
 	            printf("%d\t:",Need[n][m]);
		  }
		  printf("\n");
		}
	        break;

	case 4:

		  for(m=0; m<j; m++)
		  {
 	            printf("%d\t:",avail[m]);
		  }
		  break;
		  printf("\n");
		  default:
		  printf("Exit");
     }
  }
  while(num!=0);
  return 0;
}
