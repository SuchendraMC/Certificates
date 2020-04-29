 #include<stdio.h>
#include<conio.h>
#include<process.h>

#define Q_SIZE 5
int Q[Q_SIZE],f,r,item;

void insertRearEnd( )
{
	if(r >= Q_SIZE-1)
	{
		printf("Queue Overflow\n");
		return;
	}
	else
	{
	r=r+1;
	Q[r] = item;
	}

}

void deleteFrontEnd( )
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

void insertFrontEnd( )
{
	if(f == 0 && r == -1)

	   Q[++r] = item;

	else if ( f != 0 )

	   Q[--f] = item;
	
	else
           printf("Insertion at Front End is not Possible");

}

void deleteRearEnd( )
{
    int del_item;

	if( f>r)
	{
		printf("Queue underflow\n");
		return;
	}

	else

	{
	del_item=Q[r];

	printf("\n%d",del_item);

	r = r - 1;
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


	int choice;
	clrscr();

	f= 0;
	r= -1;

	for(;;)
	{

	  printf("\n 1: InsertRearEnd\n 2: DeleteFrontEnd\n 3: InsertFrontEnd\n 4: DeleteRearEnd\n 5: DISPLAY\n 6: EXIT\n");
	  printf("\n Enter your choice\n");
	  scanf("%d",&choice);
	  switch(choice)
		{
			case 1: printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				insertRearEnd( );
				break;

			case 2:	deleteFrontEnd( );
				break;
			
			case 3: printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				insertFrontEnd( );
				break;

			case 4: deleteRearEnd( );
				break;

			case 5: display( );
				break;

		       default: exit(0);

		}//end of switch

	}//end of for

}
//end of main