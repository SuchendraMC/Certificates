#include<stdio.h>
#include<stdio.h>
#include<conio.h>
int *add(int *m,int *n)
{
int *sum;
*sum=*m + *n;
return(sum);
}
main()
{

int a,b;
int *ps;
clrscr();
a=50,b=100;

ps=add(&a,&b);
printf("\nAdded through Pointer:   Sum of %d + %d = %d\n",a,b,*ps);
getch();
}