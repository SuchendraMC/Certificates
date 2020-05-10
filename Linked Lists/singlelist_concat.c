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
NODE insert_first( int item, NODE f );
NODE concat( NODE first,NODE sec );
void display(NODE f);

void main( )
{
	NODE first=second=NULL;
	int ch,item;
	clrscr();
	for(;;)
	{
		printf("\n 1:FIRST_LIST\n 2:SECOND_LIST\n 3:CONCATENATE\n 4:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1: printf("FIRSTLIST:\nEnter the item to be inserted:");
				scanf("%d",&item);
				first = insert_first(item,first);
				display(first);// display first list
				break;

			case 2: printf("SECONDLIST:\nEnter the item to be inserted:");
				scanf("%d",&item);
				Second = insert_first(item,second);
				display(second);//display second list 
				break;

			case 3: first=concat(first,second);
				display(first);// displays concatenated list
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

NODE concat(NODE first,NODE sec)
{
	NODE cur;
	if(first==NULL) return sec;
	if(sec==NULL) return first;
	cur=first;

	while(cur->link!=NULL)
	{
		cur= cur->link;
	}

	cur->link=sec;
	return first;
}
