#include <stdio.h>
#include <stdlib.h>
//#include <process.h>
#include <string.h>
#include <ctype.h>
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

void preorder(NODE root)
{
	if(root==NULL)return;
	printf("%d",root->info); // processing root
	preorder(root->llink); //visiting left subtree
	preorder(root->rlink);  //visiting right subtree
}

void inorder(NODE root)
{
	if(root==NULL)return;
	
	inorder(root->llink);
	printf("%d",root->info);
	inorder(root->rlink);
}

void postorder(NODE root)
{
	if(root==NULL)return;
	
	postorder(root->llink);
	postorder(root->rlink);
	printf("%d",root->info);

}


void search(int item, NODE root, int *flag)
{
	if(root==NULL)return;

	if(item==root->info)
	{
		*flag=1;
		return;
	}
	search(item,root->llink,flag);
	search(item,root->rlink,flag);
}

void display(NODE root, int level)
{
	int i;
	if(root==NULL)return;
	
	display(root->rlink,level+1); //visiting Rightsubtree
	
	for(i=0;i<level;i++)
	printf("     ");                 //giving level spaces
	
	printf("%d\n",root->info);   // processing root info
	display(root->llink,level+1); // visiting leftsubtre
}

NODE insert(int item, NODE root)
{
	NODE temp,cur,prev;
	char dir[20];
	int i;
	
	temp=getnode();
	temp->info=item;
	temp->llink=NULL;
        temp->rlink=NULL;	

	if(root==NULL)return temp;

	printf("Give the directions where is to be inserted\n");
	scanf("%s",dir);
	toupper(dir);

	prev=NULL;
	cur=root;

	for(i=0;i<strlen(dir);i++)
	{
		if(cur==NULL)break;
		prev=cur;
		
		if(dir[i]=='L')
			cur=cur->llink;
		else
			cur=cur->rlink;
	}

	if(cur!=NULL || i!=strlen(dir))
	{
		printf("Insertion is not possible\n");
		free(temp);
		return root;
	}

	if(dir[i-1]=='L')
		prev->llink=temp;
	else
		prev->rlink=temp;

	return root;
}
int main( )
{
	NODE root=NULL;
	int ch,item,flag;

	clrscr();

	for(;;)
	{
		printf("\n 1:INSERT\n 2:PREORDER\n 3:INORDER\n 4:POSTORDER\n 5:SEARCH\n 6:EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1: printf("\nEnter the item to be inserted:");
				scanf("%d",&item);
				root = insert(item,root);
				break;

			case 2: if(root==NULL)
					printf("\nTree is Empty\n");
				else
				{
					printf("The given tree is \n");
					display(root,1);
					printf("Preorder Traversal is \n");
					preorder(root);
					printf("\n");
				}
				break;

			case 3:	if(root==NULL)
					printf("\nTree is Empty\n");
				else
				{
					printf("The given tree is \n");
					display(root,1);
					printf("Inorder Traversal is \n");
					inorder(root);
					printf("\n");
				}				
                                break;

			case 4:if(root==NULL)
					printf("\nTree is Empty\n");
				else
				{
					printf("The given tree is \n");
					display(root,1);
					printf("Postorder Traversal is \n");
					postorder(root);
					printf("\n");
				}
				break;

			case 5:	if(root==NULL)
					printf("\nTree is Empty\n");
				else
				{
					printf("The given tree is \n");
					display(root,1);

					printf("Enter item to search\n");
					scanf("%d",&item);
					flag=0;
					search(item,root,&flag);
				
					if(flag==1)
                                           printf("Successful search\n");
					else 
                                           printf("UnSuccessful search\n");
				}
				break;

			default:exit(0);
		}
	}

}

	
