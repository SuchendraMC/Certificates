//PGM TO DEMONSTRATE THE WORKING OF TYPEDEF
#include<stdio.h>
#include<conio.h>
main()
{
typedef int AMOUNT;
AMOUNT amt=50;
clrscr();
printf("Defined by typedef:Amount:%d",amt);
getch();
}