#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
   int info;
   struct node *link;
};
typedef struct node *NODE;

NODE getnode();
NODE insert_first( int item, NODE h );
void display(NODE h);

void main( )
{
	NODE head;
	int ch,item;
	head=getnode();
	head->info=0;
	head->link=head;

	clrscr();
	for(;;)
	{
		printf("\n 1:INSERT_FRONT\n 2:DISPLAY\n 3:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1: printf("\nEnter the item to be inserted:");
				scanf("%d",&item);
				head = insert_first(item,head);
				break;

			case 2: display(head);
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

 

void display(NODE h)
{
	NODE temp;
	if(h->link==h)
	{
		printf("List is Empty\n");
		return ;
	}

	printf(" The content of the Singly Linked list:\n");
	temp = h->link;
	while( temp!=h )
	{
	   printf("%d\t",temp->info);
	   temp = temp->link;
	}
}


