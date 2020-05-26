#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <string.h>

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

NODE search(int item, NODE root)
{
	NODE temp=root;
	if(temp==NULL)return root;

	while(temp!=NULL)
	{
		if(item==temp->info)break;
		if(item<temp->info)
			temp=temp->llink;
		else
			temp=temp->rlink;
	}

	if(temp==NULL)
	{
		printf("Item not found\n");
		return root;
	}

	printf("successful search\n");
	return root;
}

NODE copy(NODE root)
{
	NODE temp;
	if(root==NULL)return root;

	temp=(NODE)malloc(sizeof(struct node));

	temp->info=root->info;
	temp->llink=copy(root->llink);
	temp->rlink=copy(root->rlink);
	return temp;

}

NODE delete(int item, NODE root)
{
	NODE cur,parent,suc,sbt;

	if(root==NULL)
	{
		printf("Empty tree.\n");
		return root;
	}

	parent=NULL;
	cur=root;

	while(cur!=NULL)
	{
		if(item==cur->info)break;
		parent=cur;
		cur=(item<cur->info)?cur->llink:cur->rlink;
	}

	if(cur==NULL)
	{
		printf("Unsuccessfull search\n");
		return root;
	}

	if(cur->llink==NULL)
		sbt=cur->rlink;
	else if(cur->rlink==NULL)
		sbt=cur->llink;
	else
	{
		suc=cur->rlink;
		while(suc->llink!=NULL)
			suc=suc->llink;

		suc->llink=cur->llink;
		sbt=cur->rlink;
	}

	if(parent==NULL)return sbt;

	if(cur==parent->llink)
		parent->llink=sbt;
	else
		parent->rlink=sbt;

	free(cur);
	return root;
}



void main( )
{
	NODE root=NULL;
	NODE newroot=NULL;
	int ch,item;

	clrscr();

	for(;;)
	{
		printf("\n 1:INSERT\n 2:SEARCH\n 3:COPY\n 4:DELETE\n 5:DISPLAY\n 6:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1: printf("\nEnter the item to be inserted:");
				scanf("%d",&item);
				root = insert(item,root);
				break;

			case 2: printf("\nEnter the item to search:");
				scanf("%d",&item);
				root = search(item,root);
				break;

			case 3: newroot = copy(root);
				printf("The Duplicate Tree is\n");
				display(newroot,0);
				break;

			case 4:	printf("\nEnter the item to be deleted:");
				scanf("%d",&item);
				root = delete(item,root);
				break;

			case 5: display(root,0);
				break;

			default:exit(0);
		}
	}

}

	