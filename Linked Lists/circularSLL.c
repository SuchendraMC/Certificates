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
NODE insert_front( int item, NODE last );
NODE insert_rear( int item, NODE last );
NODE delete_front( NODE last );
NODE delete_rear( NODE last );
void display(NODE last);

void main( )
{
	NODE last=NULL;
	int ch,item,key;
	clrscr();
	for(;;)
	{
		printf("CIRCULAR SINGLE LINKED LIST AND ITS BASIC OPERATIONS\n 1:INSERT_FRONT\n 2:INSERT_REAR\n 3:DELETE_FRONT\n 4:DELETE_REAR\n 5:DISPLAY\n 6:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1: printf("Enter the item to be inserted:");
				scanf("%d",&item);
				last = insert_front(item,last);
				break;

			case 2: printf("Enter the item to be inserted:");
				scanf("%d",&item);
				last = insert_rear(item,last);
				break;
			
			case 3: last = delete_front(last);
				break;

			case 4: last = delete_rear(last);
				break;

			case 5: display(last);
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

NODE insert_front( int item, NODE last )
{
	NODE temp;
	temp = getnode();
	temp->info=item;

	if(last==NULL) last=temp;
	else 	temp->link=last->link;

	last->link=temp;

	return last;
}
NODE insert_rear( int item, NODE last )
{
	NODE temp;
	temp = getnode();
	temp->info=item;

	if(last==NULL)last=temp;
	else temp->link=last->link;

	last->link= temp;

	return temp;
}


void display(NODE last)
{
	NODE temp;
	if(last==NULL)
	{
		printf("List is Empty\n"); 
                return;
	}

	printf(" The content of the Singly Linked list:\n");
	temp = last->link;
	while( temp!=last )
	{
	   printf("%d\t",temp->info);
	   temp = temp->link;
	}
	printf("%d\n",temp->info);
}

NODE delete_front( NODE last )
{
	NODE temp,first;
	if(last==NULL)
	{
		printf("List is Empty. Deletion is not possible\n"); 
		return NULL;
	}
	if(last->link==last)
	{
	        printf(" The deleted item: %d\n",last->info );
		free(last);
		return NULL;
	}
	first=last->link;
	last->link=first->link;
	        printf(" The deleted item: %d\n",first->info );
		free(first);
		return last;
	
}

NODE delete_rear( NODE last )
{
	NODE prev;
	if(last==NULL)
	{
		printf("List is Empty. Deletion is not possible\n"); 
		return NULL;
	}
	
	if( last->link ==last)
	{
		printf(" The deleted item: %d\n",last->info );
		free(last);
		return NULL;
	}
	
	prev = last->link;
	while(prev->link!=last)
	{
		prev=prev->link;
	}

	prev->link = last->link;
	
	printf(" The deleted item: %d\n",last->info );
	free(last);
	return prev;
	
}

