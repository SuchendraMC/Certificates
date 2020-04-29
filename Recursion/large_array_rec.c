#include<stdio.h>

int large(int a[' '],int n)
{
  int; big;

  if(n==0)return a[n];

  big=large(a,n-1);

  if( a[n] > big )  
    return a[n];
  
  return big;
}

void main()
{
  int n,i,a[' '],big;
  printf("Enter the N value\n");
  scanf("%d",&n);
  
  printf("Enter array elements\n");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);

  big=large(a,n-1);

  printf("Largest element is:%d",big);
}