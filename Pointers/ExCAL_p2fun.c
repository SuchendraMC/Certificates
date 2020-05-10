#include<stdio.h>
#include<conio.h>

int add(int c, int d)
{
	return(c+d);
}

int sub(int c, int d)
{
	return(c-d);
}

int mul(int c, int d)
{
	return(c*d);
}


void operation(int a,int(*fp)(int,int),int b)
{
	int res=(*fp)(a,b);
	printf("result=%d\n",res);
}

main()
{
	clrscr();
	operation(10,add,20);
	operation(40,sub,20);
	operation(10,mul,10);

	getch();
}