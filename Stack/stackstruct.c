//implementation of stack using structures and functions

#include<stdio.h>

#include<conio.h>
#include<process.h>

#define STACK_SIZE 5

typedef struct 
{
	int stk[STACK_SIZE];
	int top;
}stack;

stack s;  //global decleration of 's'

int is_full()
{
 if(s.top >= STACK_SIZE-1)
   return 1;
 else
  return 0;
}

int is_empty()
{
 if(s.top == -1)
   return 1;
 else
  return 0;

}

void push(int item)
{
 if(is_full())
  {
    printf("Stack Overflow\n");
    return;
  }

 s.top = s.top+1;
 s.stk[s.top] = item;
}

int pop()
{
 int item;
 if(is_empty())
  {
    printf("Stack underflow\n");
    return 0;
  }
 item = s.stk[s.top];
 s.top = s.top - 1;
 return(item);
}

void display()
{
 int i;
 if(is_empty())
  {
   printf("\n Stack Is Empty!");
   return;
  }

  printf("The contents of the stack\n");
  for(i=s.top ;i>=0; i--)
  printf("\n%d",s.stk[i]);

}



void main()
{

	int item,deleted_item,choice;
	clrscr();
	s.top= -1;

	for(;;)
	{

	  printf("\n 1: PUSH\n 2: POP\n 3: DISPLAY\n 4: EXIT\n");
	  printf("\n Enter your choice\n");
	  scanf("%d",&choice);
	  switch(choice)
		{
			case 1: printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				push(item);
				break;

			case 2:	deleted_item=pop();
				printf("Item deleted:%d",deleted_item);
				break;

			case 3: display();
				break;

		       default: exit(0);

		}//end of switch

	}//end of for

}//end of main