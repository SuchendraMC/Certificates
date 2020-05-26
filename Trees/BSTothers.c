#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <string.h>
#include <conio.h>
struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};
typedef struct node *NODE;
int cnode=0;
int cleaf=0;

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


NODE insert(int item, NODE root)
{
	NODE temp,cur,prev;
	char dir[20];
	int i;
	
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

NODE maximum(NODE root)
{
	NODE temp;
	if(root==NULL)return root;
	temp=root;
	while(temp->rlink!=NULL)
	{
	
		temp=temp->rlink;
	}
	return temp;

}

NODE minimum(NODE root)

{
	NODE temp;
	if(root==NULL)return root;
	temp=root;
	while(temp->llink!=NULL)
	{
	
		temp=temp->llink;
	}
	return temp;

}

void countnodes(NODE cur)
{

	if(cur==NULL)return;

	countnodes(cur->llink);
	cnode++;
	countnodes(cur->rlink);
}

void countleaf(NODE cur)
{
	if(cur==NULL)	return;
	countleaf(cur->llink);
	if(cur->llink==NULL && cur->rlink==NULL)cleaf++;
	countleaf(cur->rlink);
}

int maxx(int a,int b)
{
	return(a>b)?a:b;
}

int height(NODE root)
{
	if(root==NULL) return -1;
	return 1+(maxx(height(root->llink),height(root->rlink)));
}


void main( )
{
	NODE root=NULL;
	NODE maxitem,minitem;
	int ch,item,ht;

	clrscr();

	for(;;)
	{
		printf("\n 1:INSERT\n 2:MAX.ITEM\n 3:MIN.ITEM\n 4:COUNT_NODES\n 5:COUNT_LEAF\n 6:HEIGHT\n 7:DISPLAY\n 8:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1: printf("\nEnter the item to be inserted:");
				scanf("%d",&item);
				root = insert(item,root);
				break;

			case 2: maxitem = maximum(root);
				printf("%d",maxitem->info);
				break;

			case 3: minitem = minimum(root);
				printf("%d",minitem->info);
				break;

			case 4:	countnodes(root);
				printf("\nNumber of nodes of the given tree is %d:",cnode);
				break;

			case 5:	countleaf(root);
				printf("\nNumber of nodes of the given tree is %d:",cleaf);
				break;
		
			case 6: ht=height(root);
			    	printf("\nHeight of the given tree is %d:",ht);
				break;

			case 7: display(root,0);
				break;

			default:exit(0);
		}
	}
}

	