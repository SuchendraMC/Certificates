#include<stdio.h>
#include<conio.h>
#include<process.h>

#define Q_SIZE 5
#define Q_NUM 3

int Q[Q_NUM][Q_SIZE],f[Q_NUM],r[Q_NUM];


void enqueue(int item,int n)
{
	if(r[n] == Q_SIZE-1)
	{
		printf("Queue Overflow\n");
		return;
	}
	else
	{
	r[n]=r[n]+1;
	Q[n][r[n]] = item;
	}

}

void dequeue(int n)
{
    int del_item;
    if(f[n]>r[n])
    {
        printf("Queue empty\n");
	return;
    }

    printf("Deleted item:%d",Q[n][f[n]]);

    if(f[n]>r[n])
    {
	f[n]=0;
	r[n]=-1;
    }
}//end of dequeueing


void display(int n)
{
    int i;
   if(f[n]>r[n])
    {
        printf("Queue empty\n");
	return;
    }
    pirntf("content of Queue\n")
    for(i=f[n];i<=r[n];i++)
       printf("%d",Q[n][i]);

}//end of display


void main()
{


	int item,choice,n;
	clrscr();

	for(i = 0; i<Q_NUM; i++)
	{  
	  f[i]=0;
          r[i]=-1;
	}
	

	for(;;)
	{

	  printf("\n 1: Insert\n 2: Delete\n 3: DISPLAY\n 4:EXIT\n");
	  printf("\n Enter your choice\n");
	  scanf("%d",&choice);
	  switch(choice)
		{
			case 1: printf("Enter the Queue Priority and item:\n ");
				scanf("%d %d",&n,&item);
				enqueue(item,n-1);
				break;

			case 2:	n=0;
				if(f[0]>r[0])
				{
					printf("Queue 1 is empty\n);
					if(f[1]>r[1])
					{
					    printf("Queue 2 is empty\n");
					    if(qempty(f[2]>r[2])
					    	printf("Queue 3 is empty\n");
					    else n=3;
					}
					else n=2;
				}
				else n=1;
				if(n!=0)
				{
					printf("From Queue %d\n",n);
					dequeue(n-1);
				}

				break;

			case 3: for(i=0; i<Q_NUM;i++)
				{
				   printf("Queue %d\n",i+1);
				   display(i);
				}
				break;


		       default: exit(0);

		}//end of switch

	}//end of for

}
//end of main