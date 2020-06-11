#include<stdio.h>
#include<conio.h>

void merge(int a[15],int low,int mid,int high)
 {
   int i,j,k,b[15];
   i=low;
   j=mid+1;
   k=low;
   while((i<=mid) && (j<=high))
    {
     if(a[i]<a[j])
      {
	  b[k]=a[i];
	  k=k+1;
	  i=i+1;
      }
     else
      {
	  b[k]=a[j];
	  k=k+1;
	  j=j+1;
      }
   }//end of while

   while(i<=mid) //copy remaining elements of left list
    {
       b[k]=a[i];
       k=k+1;
       i=i+1;
    }
  while(j<=high) //copy remaining elements of right list
   {
     b[k]=a[j];
     k=k+1;
     j=j+1;
   }
  for(i=low;i<=k-1;i++)
  a[i]=b[i];

}//end of merge

void mergesort(int a[],int low,int high)
{
 int mid;
 if(low<high)
  {
    mid=(low+high)/2;
    mergesort(a,low,mid); //left list
    mergesort(a,mid+1,high); //right list
    merge(a,low,mid,high); //merges left and right lists
  }
}

int main()
 {
   int i,n,a[15];
   //clrscr();
   printf("\n Enter the number of elements : ");
   scanf("%d",&n);
   printf("\n Enter the elements\n");
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);

   mergesort(a,0,n-1);

   printf("\n The sorted elements are\n");
   for(i=0;i<n;i++)
   printf("%d\n",a[i]);
   //getch();
 }
