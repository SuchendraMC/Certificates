#include<stdio.h>
#include<conio.h>
int mul(int m,int n)
{
  if(m==0 || n==0) return 0;
  if(n==1) return m;
  if(m==1) return n;
  return mul(m,n-1)+m;
}

void main()
{
  int m,n;
  clrscr();
  printf("Enter the m value:");
  scanf("%d",&m);
  printf("\nEnter the n value:");
  scanf("%d",&n);
  printf("\nmultiplication of %d & %d is:%d",m,n,mul(m,n));
  getch();
}