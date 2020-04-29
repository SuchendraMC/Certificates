#include<stdio.h>
#include<conio.h>
#include<process.h>

#define STACK_SIZE 5

void push( int item,int *top,int s[])
{
	if(*top == STACK_SIZE-1)
	{
		printf("stack Overflow\n");
		return;
	}
	*top = *top + 1;
	s[*top] = item;
}

int pop(int *top,int s[])
{
    int del_item;

	if(*top == -1)
	{
		printf("stack underflow\n");
		return 0;
	}

	del_item=s[*top];

	*top = *top - 1;
	
	return del_item;
}

void display(int *top,int s[])
{
    int i;

	if(*top == -1)
	{
		printf("stack underflow\n");
		return;
	}

	for( i=*top; i>=0; i--)
	{

	printf("stack[%d] = %d\n",i,s[i]);
	
	}
}

void main()
{

	int s[10],top;
	int item,deleted_item,choice;
	clrscr();
	top= -1;
	
	for(;;)
	{
	
	  printf("\n 1: PUSH\n 2: POP\n 3: DISPLAY\n 4: EXIT\n");
	  printf("\n Enter your choice\n");
	  scanf("%d",&choice);
	  switch(choice)
		{
			case 1: printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				push(item,&top,s);	
				break;

			case 2:	deleted_item=pop(&top,s);	
				printf("Item deleted:%d",deleted_item);
				break;

			case 3: display(&top,s);
				break;

                       default: exit(0);

		}//end of switch
	      
	}//end of for

}//end of main