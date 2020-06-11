
#include<stdio.h>
#include<conio.h>

void heapify(int a[],int n)
{
  int i,j,k,item;
 
 for(k=1;k<n;k++)
   {
    item=a[k];       // item to be inserted
    i=k;             //@ ith posistion
    j=(i-1)/2;	     //obtains the position of parent
    
    while(i>0 && item > a[j])	// parent exist & item > parent
     {
      a[i]=a[j];		//move parent down to child
      i=j;			//make parent as child
      j=(i-1)/2;		// obtain new parent for child
     }

     a[i]=item;			// insert item into child's position
   }
}

void adjust(int a[],int n)
{
  int item,i,j;
  j=0;				//parent
  item=a[j];			
  i=2*j+1;			//left child


  while(i<=n-1)			//as long as left child exists
  {
      if(i+1 <= n-1)		// if right child exists
      {
	if(a[i]<a[i+1]) i++;	// get the position of largest child
      }
   
     if(item<a[i])		//item is lessthan the largest child
     {
     	a[j]=a[i];		//move child to parent  position
	j=i;			//make child as parent
        i=2*j+1;		//obtain left child of new parent
     }
     else  break;		//proper position of item found
  }
   a[j]=item;			//insert item to parent position
}


void heapsort(int a[],int n)
{
 int i,temp;
 
 heapify(a,n);

 for(i=n-1;i>0;i--)
  {
    temp=a[0]; // Exchanging root element with last element
    a[0]=a[i]; // in a heapified tree
    a[i]=temp;
    adjust(a,i); //Re-heapifying
  }
}


void main()
{
int i,n,a[20];
clrscr();
printf("\n Enter the number of elements : ");
scanf("%d",&n);

printf("\n Enter the elements \n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);

heapsort(a,n);

printf("\n The sorted array is \n");
for(i=0;i<n;i++)
printf("%d\n",a[i]);
getch();

}

