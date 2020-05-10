#include <stdio.h>
#include <alloc.h>
#include <process.h>
#include <conio.h>
#define SIZE 3

struct node
{
   int info;
   struct node *link;
};
typedef struct node * NODE;

NODE getnode();
NODE insert_first( int item, NODE f );
NODE delete_front( NODE f );
void display(NODE f);
int count=0;

void main( )
{
	NODE first=NULL;
	int ch,item;
	clrscr();
	for(;;)
	{
		printf("\n\n\n DYNAMIC-STACK using SINGLE LINKED LIST\n 1:PUSH\n 2:POP\n 3:DISPLAY\n 4:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: if(count<SIZE)
				{
				  count=count+1;
				  printf("Enter the item to be inserted:");
				  scanf("%d",&item);
				  first = insert_first(item,first);
				}
				else if(count==SIZE)
				printf("Stack Overflow");   
				break;

			
			case 2: first = delete_front(first);
				count=count-1;
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
		printf("STACK UNDERFLOW\n"); 
                return;
	}

	printf(" The content of the STACK:\n");
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
		printf("STACK UNDERFLOW\n"); 
		return f;
	}
	
	temp = f;
	temp = temp->link;

        printf(" The deleted item: %d\n",f->info );
	free(f);
	return temp;
}

