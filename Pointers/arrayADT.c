//pgm to implement ADT ARRAY

#include<stdio.h>
#include<conio.h>

void store(int a[' '], int n, int pos, int ele)
{
	if(pos<0 || pos>=n)
	{
	  printf("Doest not exist"); 
          exit(0);
	}
	else
	{
	  a[pos]=ele;
	  printf("a[%d]= %d",pos,a[pos]);
	}
}

int extract(int a[' '], int n, int pos)
{
        int data;
	if(pos<0 || pos>=n)
	{
	  printf("Doest not exist"); 
          exit(0);
	}
	else
        {
	  data=a[pos];	
	  return(data);
	}
}

main()
{
	int ar[' '],n,ele,pos;
	clrscr();
	printf("Enter maximum length of the array\n");
	scanf("%d",&n);

	printf("\nEnter an array element  to store with position:");
	scanf("%d %d",&ele,&pos);
	store(ar,n,pos,ele);

	printf("\nEnter position to extract element from array:");
	scanf("%d",&pos);
	printf("%d",extract(ar,n,pos));

	getch();
}







