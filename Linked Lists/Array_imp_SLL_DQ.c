#include <stdio.h>
#include <alloc.h>
#include <process.h>
#include <conio.h>
#define MAX_SIZE 100

struct node
{
   int info;
   int link;
};
struct node list[MAX_SIZE];
int avail;

int getnode();
void freenode( int x);
int insert_front( int item, int first );
int insert_rear( int item, int first );
int delete_front( int first );
int delete_rear( int first );
void display(int first);
void init();

void main( )
{
	int first=-1;
	int ch,item;
	
	init();
	
	clrscr();
	for(;;)
	{
		printf("\n 1:INSERT_FRONT\n 2:INSERT_REAR\n 3:DELETE_FRONT\n 4:DELETE_REAR\n 5:DISPLAY\n 6:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1: printf("\nEnter the item to be inserted:");
				scanf("%d",&item);
				first = insert_front(item,first);
				break;


			case 2: printf("\nEnter the item to be inserted:");
				scanf("%d",&item);
				first = insert_rear(item,first);
				break;

			case 3: first = delete_front(first);
				break;

			case 4: first = delete_rear(first);
				break;

			case 5: display(first);
				break;
		

			default:exit(0);
		}
	}

}

void init()
{
	int i;
	avail=0;

	for(i=0;i<MAX_SIZE-1;i++)
	{
		list[i].link=i+1;
	}

	list[MAX_SIZE-1].link=-1;
}


int getnode()
{
	int newx;
	
	if(avail==-1)
	{
		printf("Out of Memory\n");
		exit(1);
	}
	newx=avail;
	avail=list[avail].link;

	return newx;
}

void freenode(int index)
{
	list[index].link=avail;
	avail=index;
	return;
}

int insert_front( int item, int first )
{
	int temp;
	temp = getnode();

	list[temp].info=item;
	list[temp].link=first;

	return temp;
}

int insert_rear( int item, int first )
{
	int cur,temp;
	temp = getnode();

	list[temp].info=item;
	list[temp].link=-1;

	if(first==-1)
		return temp;

	cur=first;
	while(list[cur].link!=-1)
	{
		cur=list[cur].link;
	}

	list[cur].link=temp;
	return first;
}

int delete_front( int first )
{
	int temp;
	

	if(first==-1)
	{
		printf("List is empty\n");		
		return first;
	}

	temp=first;
	first=list[first].link;

	printf("Deleted Item is:%d\n",list[temp].info);
	freenode(temp);
	
	return first;
	
}

int delete_rear( int first )
{
	int cur,prev;
	

	if(first==-1)
	{
		printf("List is empty\n");		
		return first;
	}

	prev=-1;
	cur=first;

	while(list[cur].link!=-1)
	{
		prev=cur;
		cur=list[cur].link;
	}

	printf("Deleted Item is:%d\n",list[cur].info);
	freenode(cur);

	if(prev==-1)
	  first=-1;
	else 
	  list[prev].link=-1;
	
	return first;
		
}


void display(int first)
{
	int temp;
	if(first==-1)
	{
		printf("List is Empty\n");
		return ;
	}

	printf(" The content of the Singly Linked list:\n");
	temp = first;

	while( temp!=-1 )
	{
	   printf("%d\t",list[temp].info);
	   temp = list[temp].link;
	}
}


