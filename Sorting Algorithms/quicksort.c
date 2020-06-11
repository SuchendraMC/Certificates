#include<stdio.h>
//#include<conio.h>

int partition(int a[20],int low,int high)
{
  int i,j,temp,key;
  key=a[low];
  i=low+1;
  j=high;
  while(1)
   {
     while( i < high && key >= a[i] ) i++;
     while( key < a[j] ) j--;

     if(i<j) // exchange ith and jth elements
      {
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
      }
     else    // exchange key and jth elements
      {
       temp=a[low];
       a[low]=a[j];
       a[j]=temp;
       return j;  // returns the position of key 
     }
   }//end of while
}//end of function


void quicksort(int a[20],int low,int high)
{
 int j;

 if(low<high)
  {
    j=partition(a,low,high);

    quicksort(a,low,j-1);

    quicksort(a,j+1,high);
  }
}

int main()
 {
   int i,n,a[20];
   //clrscr();

   printf("\n Enter the number of elements : ");
   scanf("%d",&n);

   printf("\n Enter the elements \n");
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);

   quicksort(a,0,n-1);

   printf("\n The sorted elements are \n");
   for(i=0;i<n;i++)
   printf("%d\n",a[i]);

   //getch();
 }
