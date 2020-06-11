#include<stdio.h>
//#include<conio.h>

void insertsort(int a[20],int n)
{
  int i,j,item;

  for(i=1; i<n; i++)
    {

     item=a[i];

     for(j=i-1; j>=0 && item < a[j]; j--)
      {
	  a[j+1]=a[j];
      }
      
     a[j+1]=item;
    }
}

int main()
{
  int i,a[20],n;
  //clrscr();
  
  printf("\n\n Enter the number of elements : ");
  scanf("%d",&n);
  
  printf("\n\n Enter the elments : \n");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  
  insertsort(a,n);
  
  printf("\n The sorted elements are \n");
  for(i=0;i<n;i++)
  printf("%d\t",a[i]);
  
  //getch();
}
