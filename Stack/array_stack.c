//Array Based Stack using global top, stack and item
#include<stdio.h>
#include<conio.h>
#include<process.h> // #include<stdlib.h>

#define STACK_SIZE 5
int top,s[' '],item;

void push( )
{
	if(top >= STACK_SIZE-1)
	{
		printf("stack Overflow\n");
		return;
	}
	top = top + 1;
	s[top] = item;
}

void pop()
{
    int del_item;

	if(top == -1)
	{
		printf("stack underflow\n");
		return;
	}

	del_item=s[top];

	top = top - 1;

	printf("Popped Item: %d",del_item);
}

void display()
{
    int i;

	if(top == -1)
	{
		printf("stack underflow\n");
		return;
	}

	for( i=top; i>=0; i--)
	{

	printf("stack[%d] = %d\n",i,s[i]);

	}
}

void main()
{
	int choice;
	clrscr();
	top = -1;

	for(;;)
	{

	  printf("\n 1: PUSH\n 2: POP\n 3: DISPLAY\n 4: EXIT\n");
	  printf("\n Enter your choice\n");
	  scanf("%d",&choice);
	  switch(choice)
		{
			case 1: printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				push( );
				break;

			case 2: pop();
				break;

			case 3: display( );
				break;
   
		       default: exit(0);

		}//end of switch

	}//end of for

}//end of main