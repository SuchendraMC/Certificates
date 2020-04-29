#include<stdio.h>
#include<conio.h>
long int fact(long int n)
{
   //long int f; 
  if(n==0) return 1;
   //f=n*fact(n-1); return f;
  return n*fact(n-1);
}

void main()
{
  int n;
  clrscr();
  printf("Enter the N value:");
  scanf("%d",&n);
  printf("\nfactorial of %d is:%ld",n,fact(n));
  getch();
}