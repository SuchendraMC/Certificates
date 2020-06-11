
/*SORTING OF NUMBER USING BUBBLE SORT
BUBBLE SORT IS TECHNIQE TO SORT THE NUMBER EACH TIME IT COMPARES THE NUMBER
WITH ITS SUCCESSOR X[i] TO X[i+1] AND INTERCHANGE THE ELEMENT. IF X[i]
IS GREATER THAN X[i+1] IN EACH PASS BIGGEST ELEMENT COMES TO LAST*/

#include<stdio.h>
//#include<conio.h>
int main()
{
  int a[20],n,i,j,temp;
  //clrscr();
  printf("Enter the array size ");
  scanf("%d",&n);
  
  printf("enter the elements now: \n");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);

  for(i=0;i<n-1;i++)
  {
	for(j=0;j<n-i-1;j++)
	{
		if (a[j] > a[j+1])
		{
		  temp=a[j];
		  a[j]=a[j+1];
		  a[j+1]=temp;
		}
	}
  }
  printf("sorted elements using bubble sort: \n");
  for(i=0;i<n;i++)
  printf("%d\t",a[i]);
  //getch();
}

