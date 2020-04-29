#include<stdio.h>
#include<conio.h>
main()
{

	int a[3][3]={{10,20,30},{40,50,60},{70,80,90}};
	int i,j;
	int (*p)[3];
	clrscr();
	p=&a;
	printf("\n 2-D Array Elements Through Pointer:\n");
	for(i=0;i<3;i++)
	{
	for(j=0;j<3;j++)
	{
	  printf("%d\t",*(*(p+i)+j));

	}
	printf("\n");
	}
	getch();
}