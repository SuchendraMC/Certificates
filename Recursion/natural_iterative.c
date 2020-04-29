#include<stdio.h>
#include<conio.h>
int mul(int m,int n)
{
 int sum=0,i;
 for(i=1;i<=n;i++)
  {
    sum=sum+m;
  } 
 return sum;
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