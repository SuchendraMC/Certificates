//PGM TO DEMONSTRATE THE POINTER CONCEPTS
#include<stdio.h>
#include<conio.h>
main()
{
int a,b;
int *pa,*pb;
int sum;
clrscr();
a=50,b=100;

pa=&a;
pb=&b;

printf("\nDirect variable's Value:a=%d \tb=%d\n",a,b);

printf("\nDirect Pointer variable's Value:pa=%u \tpb=%u\n",pa,pb);

printf("\nAccessing variable's Value through Pointers:*pa=%d \t*pb=%d\n",*pa,*pb);

printf("\nAddress through pointers:pa=%u \tpb=%u\n",pa,pb);

printf("\nAddress through variables by & operator:&a=%u \t&b=%u\n",&a,&b);

sum=*pa + *pb;
printf("\nAdded through Pointer:   Sum =%d\n",sum);

getch();
}