#include<stdio.h>

long int fact(int n)
{
  long int f;
  int i;
  f=1;
  
  if(n==0) return f;
  
  for(i=1;i<=n;i++)
  {
    f=f*i;
  }
  return f;
}

void main()
{
  int n;
  printf("Enter the N value\n");
  scanf("%d",&n);
  printf("factorial of %d is:%ld",n,fact(n));
}