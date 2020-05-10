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
void display(NODE f);
NODE insert_pos(int pos,int item, NODE first);

void main( )
{
	NODE first=NULL;
	int ch,item,pos;
	clrscr();
	for(;;)
	{
		printf("SINGLE LINKED LIST AND ITS BASIC OPERATIONS\n  1:INSERT\n 2:DISPLAY\n 3:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1: printf("Enter the posistion & item to be inserted:");
				scanf("%d%d",&pos,&item);
				first = insert_pos(pos,item,first);
				break;
			
			case 2: display(first);
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

NODE insert_pos(int pos, int item, NODE first)
{
	NODE temp,prev,cur;
	int count;

	temp=getnode();
	temp->info = item;
	temp->link = NULL;

	if(first == NULL)
	{
		printf("Invalid position\n");
		return first;
	}

	if(first == NULL && pos == 1) return temp;

	if( pos == 1)
	{
		temp->link = first;
		return temp;
	}

	count = 1;

	prev = NULL;
	cur = first;

	while(cur != NULL && count != pos)
	{
		prev = cur;
		cur = cur->link;
		count++;
	}

	if(count == pos)
	{
		prev->link = temp;
		temp->link = cur;
	}

	printf("Invalid postion\n");
	return first;
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

