#include <stdio.h>
#include <stdlib.h>
//#include <process.h>
#include <string.h>
#include <conio.h>

struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};
typedef struct node *NODE;

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

void inorder(NODE root)
{
	if(root==NULL)return;
	
	inorder(root->llink);
	printf("%d\t",root->info);
	inorder(root->rlink);
}

void display(NODE root, int level)
{
	int i;
	if(root==NULL)return;
	
	display(root->rlink,level+1);
	
	for(i=0;i<level;i++)
	printf("   ");
	
	printf("%d\n",root->info);
	display(root->llink,level+1);
}

NODE insert_BST(int item, NODE root)
{
	NODE temp,cur,prev;
		
	temp=getnode();
	temp->info=item;
	temp->llink=temp->rlink=NULL;	

	if(root==NULL)return temp;
	prev=NULL;
	cur=root;
	while(cur!=NULL)
	{
		prev=cur;
		if(item<cur->info)
			cur=cur->llink;
		else   
		 	cur=cur->rlink;
	}

	if(item<prev->info)
		prev->llink=temp;
	else
		prev->rlink=temp;
	
	return root;
	
}

int main( )
{
	NODE root=NULL;
	int ch,item;

	clrscr();

	for(;;)
	{
		printf("\nBinary Tree Sorting \n 1:INSERT\n 2:INORDER\n 3:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1: printf("\nEnter the item to be inserted:");
				scanf("%d",&item);
				root = insert_BST(item,root);
				break;

			
			case 2:	if(root==NULL)
				   printf("\nTree is Empty\n");
				else
				{
					printf("The given tree is \n");
					display(root,1);
					printf("Sorted List (Inorder Traversal) is \n");
					inorder(root);
					printf("\n");
				}				
                                break;

			default:exit(0);
		}
	}

}

	
