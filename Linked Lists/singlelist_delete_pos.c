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
NODE delete_pos(int pos,NODE first);
NODE insert_pos(int pos, int item, NODE first);

void main( )
{
	NODE first=NULL;
	int ch,item,pos;
	clrscr();
	for(;;)
	{
		printf("INSERTING / DELETING AT GIVEN POSITION\n 1:INSERT_POS\n 2:DELETE_POS\n 3:DISPLAY\n 4:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1: printf("Enter the position & item to be inserted:");
				scanf("%d%d",&pos,&item);
				first = insert_pos(pos,item,first);
				break;

			case 2: printf("Enter the position to from which item to be deleted:");
				pos=0;
				scanf("%d",&pos);
				first=delete_pos(pos,first);
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

NODE insert_pos(int pos, int item, NODE first)
{
	NODE temp,prev,cur;
	int count;

	temp=getnode();
	temp->info= item;
	temp->link=NULL;

        if(first == NULL && pos==1) return temp;

	if(first == NULL)
	{
		printf("Invalid position\n");
		return first;
	}

	
	if( pos==1)
	{
		temp->link = first;
		return temp;
	}

	count= 1;

	prev=NULL;
	cur=first;

	while(cur!=NULL && count!=pos)
	{
		prev=cur;
		cur=cur->link;
		count++;
	}

	if(count==pos)
	{
		prev->link = temp;
		temp->link = cur;
		return first;
	}

	printf("Invalid postion\n");
	return first;
}

NODE delete_pos(int pos,NODE first)
{
	NODE temp,prev,cur;
	int count;

	
	if(first == NULL || pos<=0) 
	{
		printf("Invalid position\n");
		return NULL;
	}

	if( pos==1)
	{
		cur = first;
		first= first->link;
		free(cur);
		return first;
	}

	count= 1;

	prev=NULL;
	cur=first;

	while(cur!=NULL)
	{
		if(count==pos)break;
		prev=cur;
		cur=cur->link;count++;
	}

	if(count!=pos)
	{
		printf("End of the list, So Invalid Position\n");
		return first;
	}

	}

	prev->link = cur->link;
	free(cur);
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

