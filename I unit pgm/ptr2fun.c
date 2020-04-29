//POINTER TO FUNCTION
#include<stdio.h>
#include<conio.h>

int add(int c, int d)
{
	return(c+d);
}

main()
{
	int(*fp)(int,int);
	int res;
	clrscr();
        fp=add;
	res=(*fp)(10,20);
	printf("result=%d",res);
	getch();
}