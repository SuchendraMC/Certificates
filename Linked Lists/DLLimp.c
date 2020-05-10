// Circular DLL with Header

#include <stdio.h>
#include <alloc.h>
#include <process.h>

struct node
{
  int info;
  struct node *llink;
  struct node *rlink;
};

typedef struct node* NODE;

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

NODE insert_front( int item, NODE head )
{
	NODE temp,cur;
	temp = getnode();
	temp->info=item;

	cur=head->rlink;

	head->rlink=temp;
	temp->llink=head;
	temp->rlink=cur;
	cur->llink=temp;

	return head;
}

NODE insert_rear( int item, NODE head )
{
	NODE temp,cur;
	temp = getnode();
	temp->info=item;

	cur=head->llink;

	head->llink=temp;
	temp->rlink=head;
	temp->llink=cur;
	cur->rlink=temp;

	return head;
}

NODE delete_front(  NODE head )
{
	NODE cur,next;
	if(head->rlink==head)
	{
		printf("list is empty.\n");
		return head;
	}


	cur=head->rlink;
	next=cur->rlink;

	head->rlink=next;
	next->llink=head;
	printf("The node to be deleted is %d\n",cur->info);
	free(cur);

	return head;
}

NODE delete_rear(  NODE head )
{
	NODE cur,prev;
	if(head->rlink==head)
	{
		printf("list is empty.\n");
		return head;
	}


	cur=head->llink;
	prev=cur->llink;

	head->llink=prev;
	prev->rlink=head;

	printf("The node to be deleted is %d\n",cur->info);
	free(cur);

	return head;
}

NODE delete_info( int key, NODE head )
{
	NODE prev,cur,next;
	if(head->rlink==head)
	{
		printf("list is empty.\n");
		return head;
	}
	cur=head->rlink;
	while(cur!=head)
	{
		if(key==cur->info)break;
		cur=cur->rlink;
	}
	if(cur==head)
	{
		printf("Item not found\n");
		return head;
	}
	prev=cur->llink;
	next=cur->rlink;
	prev->rlink=next;
	next->llink=prev;
	free(cur);
	return head;
}


NODE delete_info_all( int key, NODE head )
{
	NODE prev,cur,next,n_del;
	int count;

	if(head->rlink==head)
	{
		printf("list is empty.\n");
		return head;
	}
	count=0;
	cur=head->rlink;
	while(cur!=head)
	{
		if(key==cur->info) 
		{
			count++;
 			//holds prev and next node addresses
			prev=cur->llink;
			next=cur->rlink;
			
			//establishes the links b/n prev and next
			prev->rlink=next;
			next->llink=prev;

			//keep a copy cur node 			
			delnode=cur;
                        free(delnode);
                        
                        cur=next;
		}//end of if
                
              	cur=cur->rlink;	
	
        }//end of while

	if(count==0)
           printf("Item not found\n");
	else 
           printf("Item found  %d number of times and are deleted\n",count);

	return head;
}

NODE insert_info_right(int key, NODE head)
{
	NODE temp,cur,next;
	if(head->rlink==head)
	{
		printf("list is empty\n");
		return head;
	}
	cur=head->rlink;

	while(cur!=head)
	{
		if(key==cur->info)break;
		cur=cur->rlink;
	}

	if(cur==head)
	{
		printf("key not found\n");
		return head;
	}

	next=cur->rlink;

	printf("enter the item to insert towards right of %d:",key);

	temp=getnode();

	scanf("%d",&temp->info);

	cur->rlink=temp;
	temp->llink=cur;
	next->llink=temp;
	temp->rlink=next;

	return head;
}

NODE insert_info_left(int key, NODE head)
{
	NODE prev,temp,cur;
	if(head->rlink==head)
	{
		printf("list is empty\n");
		return head;
	}
	cur=head->rlink;
	while(cur!=head)
	{
		if(key==cur->info)break;
		cur=cur->rlink;
	}
	if(cur==head)
	{
		printf("key not found\n");
		return head;
	}

	prev=cur->llink;
	printf("enter the item to insert towards left of %d:",key);

	temp=getnode();
	scanf("%d",&temp->info);

	prev->rlink=temp;
	temp->llink=prev;
	cur->llink=temp;
	temp->rlink=cur;

	return head;
}

void display(NODE head)
{
	NODE temp;

	if(head->rlink==head)
	{
		printf("List is empty\n");
		return;
	}

	printf("contents of the list\n");
	temp=head->rlink;

	while(temp!=head)
	{
		printf("%d\t",temp->info);
		temp=temp->rlink;
	}
	printf("\n");
}

void main( )
{
	NODE head;
	int ch,item;
	head=getnode();
	head->info=0;
	head->llink=head;
	head->rlink=head;

	clrscr();
	for(;;)
	{
		printf("\n 1:INSERT_FRONT\n 2:INSERT_REAR\n 3:DELETE_FRONT\n 4:DELETE_REAR\n 5:DELETE_KEY\n 6:DELETE_KEY_ALL\n 7:INSERT_LEFT\n 8:INSERT_RIGHT\n 9:DISPLAY\n 10:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1: printf("\nEnter the item to be inserted:");
				scanf("%d",&item);
				head = insert_front(item,head);
				break;

			case 2: printf("\nEnter the item to be inserted:");
				scanf("%d",&item);
				head = insert_rear(item,head);
				break;

			case 3:	head = delete_front(head);
				break;

			case 4:	head = delete_rear(head);
				break;

			case 5:	printf("\nEnter the item to be deleted:");
				scanf("%d",&item);
				head = delete_info(item,head);
				break;

			case 6:	printf("\nEnter the item to be deleted:");
				scanf("%d",&item);
				head = delete_info_all(item,head);
				break;

			case 7: printf("\nEnter the key to search(left):");
				scanf("%d",&item);
				head = insert_info_left(item,head);
				break;

			case 8: printf("\nEnter the key search(right):");
				scanf("%d",&item);
				head = insert_info_right(item,head);
				break;

			case 9: display(head);
				break;

			default:exit(0);
		}
	}
}