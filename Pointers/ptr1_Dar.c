//PGM TO DEMONSTRATE THE POINTER TO 1D ARRAY
#include<stdio.h>
#include<conio.h>
main()
{

	int a[3]={10,20,30};
	int i;
	int *p;
	clrscr();
	p=&a; // p= &a[0];
	printf("\n 1-D Array Elements Through Pointer:\n");
	for(i=0;i<3;i++)
	{
	  printf("\n 1-D Array Elements Through Pointer: %d\t",*(p+i));
	}
	printf("\n");
	getch();
}