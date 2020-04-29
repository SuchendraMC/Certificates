#include<stdio.h>
#include<conio.h>


int Bsearch(int key,int a[20],int low,int high)
{
  int mid;

  if(low>high) return -1;

  mid=(low+high)/2;

  if(key==a[mid])return mid;

  if(key<a[mid])
 
     return Bsearch(key,a,low,mid-1);

  else

     return Bsearch(key,a,mid+1,high); 

}

void main()
{
  int a[20],n,item,pos=-1,i;
  clrscr();

  printf("Enter the number of elements:\n");
  scanf("%d",&n);

  printf("\nEnter %d elements in ascending order:\n");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);

  printf("Enter the item to search:\n");
  scanf("%d",&item);

  pos=Bsearch(item,a,0,n-1);
  
  if(pos==-1)
     printf("Unsucessful search.\n");
  else
     printf("sucessful search: %d found at position:%d\n",item,pos);
  
  getch();
}