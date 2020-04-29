#include<stdio.h>
#include<conio.h>
#include<process.h>

#define Q_SIZE 5
int item,Q[Q_SIZE],f,r,count;
void enqueue()
{

	if(count == Q_SIZE)
	{
		printf("Queue Full\n");
		return;
	}
	else
	{
	r=(r+1) % Q_SIZE;
	Q[r] = item;
	count=count+1;
	}

}
void dequeue()
{
    int del_item;

	if( count == 0)
	{
		printf("Queue Empty\n");
		return;
	}

	else

	{
	del_item = Q[f];

	printf("\n%d",del_item);

	f = (f + 1) % Q_SIZE;
	count=count-1;
	}

}

void display()
{
    int i,j;

	if(count==0)
	{
		printf("Queue Empty\n");
		return;
	}

	printf("Queue:\t");
        i=f; //points to first element
	for(j=1; j<=count; j++)
	{
	  printf("%d\t",Q[i]);
	  i=(i+1) % Q_SIZE;
	}
}

void main()
{
	int choice;
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
				enqueue();
				break;

			case 2:	dequeue();
				break;

			case 3: display();
				break;

		       default: exit(0);

		}//end of switch

	}//end of for
}
//end of main