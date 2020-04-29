#include<stdio.h>
#include<conio.h>
#include<process.h>

#define Q_SIZE 5
int Q[Q_SIZE],f,r;

void enqueue(int item)
{
  int j;	
 	if(r == Q_SIZE-1)
	{
		printf("Queue Overflow\n");
		return;
	}
	else
	{
        
           j=r;

 	   while(j>=0 && item > Q[j])
            {
               Q[ j+1 ]=Q[ j ];
 
               j = j-1;
            }
 
           Q[ j+1 ]=item;

	   r=r+1;
	}

}

void dequeue()
{
    int del_item;

	if( f>r)
	{
		printf("Queue underflow\n");
		return;
	}

	else

	{
	del_item=Q[f];

	printf("\n%d",del_item);

	f = f + 1;
	}

	if(f>r)f=0,r=-1;

}

void display()
{
    int i;

	if(f>r)
	{
		printf("Queue underflow\n");
		return;
	}

	for( i=f; i<=r; i++)
	{

	printf("Queue[%d] = %d\n",i,Q[i]);

	}
}

void main()
{


	int item,choice;
	clrscr();

	f = 0;
	r = -1;

	for(;;)
	{

	  printf("\n 1: ENQUEUE\n 2: DQUEUE\n 3: DISPLAY\n 4: EXIT\n");
	  printf("\n Enter your choice\n");
	  scanf("%d",&choice);
	  switch(choice)
		{
			case 1: printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				enqueue(item);
				break;

			case 2:	dequeue(Q);
				break;

			case 3: display();
				break;

		       default: exit(0);

		}//end of switch

	}//end of for

}
//end of main