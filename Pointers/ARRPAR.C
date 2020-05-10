//PGM TO DEMONSTRATE PASSING ARRAY AS PARAMETER
#include<stdio.h>
#include<conio.h>

void Add(int a[' '], int n)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	{
	sum+=a[i];
	}
	printf("\nAddition of array elements= %d\n",sum);
}


main()
{
	int ar[' '],n,i;
	clrscr();
	printf("\nEnter array size:\n");
	scanf("%d",&n);


	printf("\nEnter %d array elements:\n",n);
	for(i=0;i<n;i++)
	scanf("%d",&ar[i]);
	Add(ar,n);

	getch();
}