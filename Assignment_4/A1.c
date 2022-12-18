#include<stdio.h>

int main()
{
  int i, j, k, np, nf, frame[10], ref_string[50], page_found, fcount=0;

  printf("Enter the no of pages: ");
  scanf("%d",&np);

  printf("Enter the page reference strings: ");
  for(i=0; i<np; i++)
    scanf("%d",&ref_string[i]);

  printf("Enter the no of frames: ");
  scanf("%d",&nf);

  for(i=0; i<nf; i++)
    frame[i]=-1;  //initializing all frames to -1
  j=0;  //initializing page frame pointer

  printf("\n Ref_string \t Page Frames \t Hit/Fault \n");

  for(i=0; i<np; i++)
  {
    printf("%d\t\t",ref_string[i]);
    page_found=0; //default value of page available is 0
    for(k=0; k<nf; k++)
    {
      if(frame[k] == ref_string[i]) //input of  page  requested is compared with existing content of FRAME
      {
        page_found=1; //as page found availaible is turned 1
        for(k=0; k<nf; k++)
        {
          printf("%d\t",frame[k]); //print current state of k
        }
        printf("H"); //indicating of page hit
      }
    }
    if(page_found==0) // input page requested is not available in frame
    {
      frame[j] = ref_string[i]; // place page requested at j th place
      j=(j+1) % nf;  //update j for the next cycle
      fcount++;     //increment counter for page fault
      for(k=0; k<nf; k++)
        printf("%d\t", frame[k]); //print current state of frame
      printf("F");  //indication of page fault
    }
    printf("\n");
  }
  printf("page fault is%d: ",fcount);
  return 0;
}