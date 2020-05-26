#include<stdio.h>
//#include<conio.h>

int visited[10];

void dft(int n,int a[10][10],int source)
 {
	int i,s[10],u;
	int top=1;

	visited[source]=1;  // marking source vertex visited
	s[top]=source;     // starting from source vertex

	while(top>0)
	{
		u=s[top];
		//printf("%d\t",u);//incase of integer nodes
		printf("%c\t",u+64);// incase of alphabetical nodes

		top=top-1;

		for(i=1;i<=n;i++)
                {
	           if(a[u][i]==1 && visited[i]==0)
		   {
			top=top+1;
			s[top]=i; //push the node
		 	visited[i]=1;
		   }
                }//end of for
 	} //end of while
   } //end of dft

int main()
  {
	int n,a[10][10],i,j,source;
	//clrscr();
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

	dft(n,a,source);

	for(i=1;i<=n;i++)
	 {
	   if(visited[i]==0)
	     printf("\n The node %d is not visited",i);
	   else
	     printf("\n The node %d is visited",i);
	  }
	//getch();
   }

