#include <stdio.h>
#include <alloc.h>
#include <process.h>
#include <conio.h>
struct node
{
   int info;
   struct node *link;
};
typedef struct node *NODE;

NODE getnode();
NODE insert_first( int item, NODE f );
NODE reverse(NODE first);

void display(NODE f);

void main( )
{
	NODE first=NULL;
	int ch,item;
	clrscr();
	for(;;)
	{
		printf("SINGLE LINKED LIST AND ITS BASIC OPERATIONS\n  1:INSERT\n 2:REVERSE_LIST\n 3:DISPLAY\n 4:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1: printf("\nEnter the item to be inserted:");
				scanf("%d",&item);
				first = insert_first(item,first);
				break;

			
			case 2: first=reverse(first);
				break;

			case 3: display(first);
				break;

			default:exit(0);
		}
	}

}

NODE getnode()
{
	NODE newnode;
	newnode=(NODE)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Out of Memory\n");
		exit(0);
	}
	return newnode;
}

NODE insert_first( int item, NODE f )
{
	NODE temp;
	temp = getnode();
	temp->info=item;
	temp->link=f;

	return temp;
}

void display(NODE f)
{
	NODE temp;
	if(f==NULL)
	{
		printf("List is Empty\n"); 
                return;
	}

	printf(" The content of the Singly Linked list:\n");
	temp = f;
	while( temp!=NULL )
	{
	   printf("%d\t",temp->info);
	   temp = temp->link;
	}
}

NODE reverse(NODE first)
{
	NODE cur, temp;
	
	cur=NULL;

	while(first!=NULL)
	{
		temp=first;
		first=first->link;
		temp->link=cur;
		cur=temp;
	}

	return cur;
}
