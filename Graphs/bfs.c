#include<stdio.h>
#include<conio.h>
int visited[10];

void bft(int n,int a[10][10],int source)
 {
	int i,q[10],u;
	int front=1,rear=1;

	visited[source]=1;  // marking source vertex visited
	q[rear]=source;     // starting from source vertex

	while(front<=rear)
	{

		u=q[front];
		//printf("%d\t",u);//incase of integer nodes
		print("%c\t",u+64);// incase of alphabetical nodes

		front=front+1;

		for(i=1;i<=n;i++)
		if(a[u][i]==1 && visited[i]==0)
		{
			rear=rear+1;
			q[rear]=i;
			visited[i]=1;
		}
	} //end of while
   } //end of bft

void main()
  {
	int n,a[10][10],i,j,source;
	clrscr();
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	printf("\n Enter the adjacency matrix\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);

	printf("\n Enter the source :");
	scanf("%d",&source);

	for(i=1;i<=n;i++)
	visited[i]=0;  //not visited any vertices

	bft(n,a,source);
	for(i=1;i<=n;i++)
	 {
	   if(visited[i]==0)
	     printf("\n The node %d is not visited",i);
	   else
	     printf("\n The node %d is visited",i);
	  }
	getch();
   }

