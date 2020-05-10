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
NODE insert(int item, NODE first);

void main( )
{
	NODE first=NULL;
	int ch,item;
	clrscr();
	for(;;)
	{
		printf("\nORDERED SINGLE LINKED LIST \n 1:INSERT\n 2:DISPLAY\n 3:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1: printf("Enter the item to be inserted:");
				scanf("%d",&item);
				first = insert(item,first);
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

NODE insert(int item, NODE first)
{
	NODE temp,prev,cur;
	temp=getnode();
	temp->info= item;
	temp->link=NULL;

	if(first == NULL) return temp;

	if( item < first->info)
	{
		temp->link = first;
		return temp;
	}

	prev=NULL;
	cur=first;
	while(cur!=NULL && item >cur->info)
	{
		prev=cur;
		cur=cur->link;
	}

	prev->link=temp;
	temp->link=cur;

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

