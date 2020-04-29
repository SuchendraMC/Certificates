// PGM TO DEMONSTRATE THE WORKING OF POINTER TO POINTER
#include<stdio.h>
#include<conio.h>
int * add(int *m,int *n)
{
int *sum;
*sum=*m + *n;
return(sum);
}
main()
{

int a,b;
int *ps;
int **ptp;
clrscr();
a=50,b=100;

ps=add(&a,&b);
printf("\n Through First Pointer ps:   Sum of %d + %d = %d\n",a,b,*ps);

ptp=&ps;
printf("\n Through Pointer to Pointer ptp:   Sum of %d + %d = %d\n",a,b,**ptp);      

getch();
}