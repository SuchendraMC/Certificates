//Program to demonstrate the use of dynamic memory functions

#include<stdio.h>
#include<alloc.h>
#include<conio.h>
void main()
{
  float *fp1, *fp2;
  int i;
  clrscr();
  //using malloc()
  printf("Dynamic Array created using malloc() :\n");
  fp1=(float *)malloc(16);

  printf("Enter Four Floating Point values:\n");
  for(i=0;i<4;i++)
    scanf("%f",(fp1+i));

  printf("Given Dynamic Array Elements:\n");
  for(i=0;i<4;i++)
    printf("fp1[%d] = %f address = %p\t",i,*(fp1+i),(fp1+i));

  //using calloc()
  printf("\nDynamic Array created using calloc() :\n");
  fp2=(float *)calloc(4,4);

  printf("Enter Four Floating Point values:\n");
  for(i=0;i<4;i++)
    scanf("%f",(fp2+i));

  printf("Given Dynamic Array Elements:\n");
  for(i=0;i<4;i++)
    printf("fp2[%d] = %f address = %p\t",i,*(fp2+i),(fp2+i));

  //using realloc()
  printf("\nModified Dynamic Array for 5 elements:\n");
  fp1=(float *)realloc(fp1,20);

  printf("Enter Five Floating Point values:\n");
  for(i=0;i<5;i++)
    scanf("%f",(fp1+i));

  printf("Given Dynamic Array Elements:\n");
  for(i=0;i<5;i++)
    printf("fp1[%d] = %f address = %p\t",i,*(fp1+i),(fp1+i));


  //using free()
  printf("\nFreed Memory through free()\n");
  free(fp1);
    fp1=NULL;
  free(fp2);
    fp2=NULL;
  printf("\nfp1=%p \tfp2=%p",fp1,fp2);
  getch();
}



