#include<stdio.h>
#include<conio.h>

int gcd(int m,int n)
{
  if(n>m) return gcd(n,m);

  if(n==0) return m;

  return gcd(n,m % n);
}
void main()
{
  int m,n,res;
  clrscr();
  printf("\nEnter the m value:");
  scanf("%d",&m);
  printf("\nEnter the n value:");
  scanf("%d",&n);
  res=gcd(m,n);
  printf("\ngcd(%d,%d)is:%d",m,n,res);
  getch();
}