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
NODE insert_rear( int item, NODE f );
NODE delete_front( NODE f );
NODE delete_rear( NODE f );
void display(NODE f);
void search(int key, NODE first);
void main( )
{
	NODE first=NULL;
	int ch,item;
	clrscr();
	for(;;)
	{
		printf("SINGLE LINKED LIST AND ITS BASIC OPERATIONS\n \nSingle Linked List\n 1:INSERT_FRONT\n 2:INSERT_REAR\n 3:DELETE_FRONT\n 4:DELETE_REAR\n 5:DISPLAY\n 6:SEARCH\n 7:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1: printf("Enter the item to be inserted:");
				scanf("%d",&item);
				first = insert_first(item,first);
				break;

			case 2: printf("Enter the item to be inserted:");
				scanf("%d",&item);
				first = insert_rear(item,first);
				break;
			
			case 3: first = delete_front(first);
				break;

			case 4: first = delete_rear(first);
				break;

			case 5: display(first);
				break;
			
			case 6: printf("Enter the key item to search in the list\n");
				scanf("%d",&key);
                                search(key,first);
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
NODE insert_rear( int item, NODE f )
{
	NODE temp,cur;
	temp = getnode();
	temp->info=item;
	temp->link=NULL;
	if(f==NULL)return temp;
	cur=f;
	while(cur->link!=NULL)
	{
	  cur=cur->link;
	}
	cur->link=temp;
	return f;
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

NODE delete_front( NODE f )
{
	NODE temp;
	if(f==NULL)
	{
		printf("List is Empty. Deletion is not possible\n"); 
		return f;
	}
	
	temp = f;
	temp = temp->link;

        printf(" The deleted item: %d\n",f->info );
	free(f);
	return temp;
}

NODE delete_rear( NODE f )
{
	NODE cur,prev;
	if(f==NULL)
	{
		printf("List is Empty. Deletion is not possible\n"); 
		return f;
	}
	
	if( f->link == NULL)
	{
		printf(" The deleted item: %d\n",f->info );
		free(f);
	}
	
	prev = NULL;
	cur = f;
	
	while(cur->link != NULL)
	{
		prev = cur;
		cur = cur->link;
	}

 	printf(" The deleted item: %d\n",cur->info );
	free( cur );
	
	prev->link = NULL;
	return f;
}

void search(int key, NODE first)
{
	NODE cur;
	if( first == NULL )
	{ 
		printf("list is empty\n");
		return;
	}
	
	cur=first;
	while(cur!=NULL)
	{
		if(key == cur->info) break;
		cur= cur->link;
	}

	if(cur == NULL)
	{
		printf("Search is unsuccessful\n");
		return;
	}
	
	printf(" Search is Successful\n");
}
