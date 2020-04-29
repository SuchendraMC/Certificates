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
float div(int c, int d)
{
	return((float)(c/d));
}
main()
{
	int (*fp)(int, int);
        float (*fp1)(int, int);
	float res1;
        int res;
	clrscr();
	fp=&add;
	res=(*fp)(10,20);
	printf("Addition result=%d\n",res);

	fp=&sub;
	res=(*fp)(100,60);
	printf("Subtraction result=%d\n",res);

	fp=&mul;
	res=(*fp)(10,6);
	printf("Multiplication result=%d\n",res);
        
        fp1=&div;
	res1=(*fp1)(5,2);
	printf("Division result=%f\n",res1);
	getch();
}