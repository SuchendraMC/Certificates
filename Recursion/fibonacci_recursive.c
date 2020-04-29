#include<stdio.h>
#include<conio.h>

int fib(int n)
{
  if(n==0)return 0;
  if(n==1)return 1;
  return fib(n-1)+fib(n-2);

}

void main()
{
  int i,n;
  clrscr();
  printf("\nEnter the n value:");
  scanf("%d",&n);

  printf("\n%d fibonacci numbers are:",n);
  for(i=0;i<n;i++)
  {
    printf("\nfib(%d):%d\n",i,fib(i));
  }
  getch();
}