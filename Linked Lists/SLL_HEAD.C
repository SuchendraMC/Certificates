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
NODE concat(NODE h1,NODE h2);
void display(NODE h);


void main( )
{
	NODE head1, head2;
	int ch,item;
	head1=getnode();
	head1->info=0;
	head1->link=NULL;

	head2=getnode();
	head2->info=0;
	head2->link=NULL;

	clrscr();
	for(;;)
	{
		printf("\n 1:FIRST_LIST\n 2:SECOND_LIST\n 3:CONCATENATE\n 4:DISPLAY_FIRST\n 5:DISPLAY_SECOND\n 6:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1: printf("FIRSTLIST:\nEnter the item to be inserted:");
				scanf("%d",&item);
				head1 = insert_first(item,head1);
				break;

			case 2: printf("SECONDLIST:\nEnter the item to be inserted:");
				scanf("%d",&item);
				head2 = insert_first(item,head2);
				break;

			case 3: head1=concat(head1,head2);
				break;

			case 4: display(head1);
				break;

			case 5: display(head2);
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

NODE insert_first( int item, NODE h )
{
	NODE temp;
	temp = getnode();
	temp->info=item;
	temp->link=h->link;
	h->link=temp;

	return h;
}


void display(NODE h)
{
	NODE temp;
	if(h->link==NULL)
	{
		printf("List is Empty\n");
		return;
	}

	printf(" The content of the Singly Linked list:\n");
	temp = h->link;
	while( temp!=NULL )
	{
	   printf("%d\t",temp->info);
	   temp = temp->link;
	}
}

NODE concat(NODE h1,NODE h2)
{
	NODE cur;
	if(h1->link==NULL) return h2;
	if(h2->link==NULL) return h1;
	cur=h1->link;

	while(cur->link!=NULL)
	{
		cur= cur->link;
	}

	cur->link=h2->link;
	return h1;
}
