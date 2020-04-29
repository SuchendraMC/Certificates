#include<stdio.h>
#include<conio.h>
#include<process.h>

#define Q_SIZE 5

void enqueue(int item,int Q[],int *r,int *count)
{
	if(*count == Q_SIZE)
	{
		printf("Queue Full\n");
		return;
	}
	else
	{
	*r=(*r+1)%Q_SIZE;
	Q[*r] = item;
	*count+=1;
	}

}
void dequeue(int Q[],int *f,int *count)
{
    int del_item;

	if( *count == 0)
	{
		printf("Queue Empty\n");
		return;
	}

	else

	{
	del_item=Q[*f];

	printf("\n%d",del_item);

	*f = (*f + 1)%Q_SIZE;
	*count-=1;
	}

}

void display(int Q[],int f,int count)
{
    int i;

	if(count==0)
	{
		printf("Queue Empty\n");
		return;
	}

	printf("Queue:\t");

	for( i=1; i<=count; i++)
	{
	printf("%d\t",Q[f]);
	f=(f+1) % Q_SIZE;

	}
}

void main()
{


	int item,choice;
	int Q[Q_SIZE],f,r,count;
	clrscr();

	f=  0;
	r= -1;
	count=0;

	for(;;)
	{

	  printf("\n CIRCULAR QUEUE\n");
	  printf("\n 1: ENQUEUE\n 2: DQUEUE\n 3: DISPLAY\n 4: EXIT\n");
	  printf("\n Enter your choice\n");
	  scanf("%d",&choice);
	  switch(choice)
		{
			case 1: printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				enqueue(item,Q,&r,&count);
				break;

			case 2:	dequeue(Q,&f,&count);
				break;

			case 3: display(Q,f,count);
				break;

		       default: exit(0);

		}//end of switch

	}//end of for

}
//end of main