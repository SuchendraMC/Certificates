#include<stdio.h>

int sum(int a[' '],int n)
{
  
  if(n==0)return a[n];
    
  return a[n]+sum(a,n-1);
}

void main()
{
  int n,i,a[' '],res;
  printf("Enter the N value\n");
  scanf("%d",&n);
  
  printf("Enter array elements\n");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);

  res=sum(a,n-1);

  printf("Sum is:%d",res);
}