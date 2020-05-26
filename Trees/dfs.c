#include<stdio.h>
#include<conio.h>
int visited[10];

void dft(int n,int a[10][10],int source)
  {
   int i;
   visited[source]=1;
   for(i=1;i<=n;i++)
     if(a[source][i]==1 && visited[i]==0)
     dft(n,a,i);
  }

void main()
{
 int i,j,source;
 int n,a[10][10];
 int count=0;
 clrscr();
 printf("\n Enter the number of nodes : ");
 scanf("%d",&n);
 printf("\n Enter the paths (0 if edge is not present,1 if present\n");
 for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
       scanf("%d",&a[i][j]);
 printf("\nEnter the source vertex :");
 scanf("%d",&source);
 for(i=1;i<=n;i++)
 visited[i]=0;
 dft(n,a,source);
 for(i=1;i<=n;i++)
 {
  if(visited[i])
    count=count+1;
 } 
 if(count==n)
    printf("\n The graph is connected \n");
 else
    printf("\n The graph is not connected \n");
 getch();
}
