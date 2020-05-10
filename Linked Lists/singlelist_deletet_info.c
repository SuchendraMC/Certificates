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
NODE delete_info(int key,NODE first);

void main( )
{
	NODE first=NULL;
	int ch,item,key,pos;
	clrscr();
	for(;;)
	{
		printf("\n 1:INSERT_POSITION\n 2:DELET_INFO\n 3:DISPLAY\n 4:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1: printf("Enter the position & item to be inserted:");
				scanf("%d%d",&pos,&item);
				first = insert_pos(pos,item,first);
				break;

			case 2: printf("Enter the key to be deleted:");
				scanf("%d",&key);
				first = delete_info(key,first);
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

NODE delete_info(int key,NODE first)
{
	NODE prev,cur;
	if(first == NULL)
	{
		printf("List is empty\n");
		return NULL;
	}

	if(key == first->info)
	{
		cur=first;
		first=first->link;
		free(cur);
		return first;
	}

	prev=NULL;
	cur=first;

	while(cur!=NULL)
	{
		if(key==cur->info)break;
		prev=cur;
		cur=cur->link;
	}

	if(cur==NULL)
	{
		printf("Key not found\n");
		return first;
	}

	prev->link = cur->link;
	free(cur);
	return first;
}