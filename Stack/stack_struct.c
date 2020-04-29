//implementation of stack using structures and pointers

#include<stdio.h>
#include<conio.h>
#include<process.h>

#define STACK_SIZE 5

struct stack
{
	int stk[STACK_SIZE];
	int top;
};
typedef struct stack STACK;


int is_full(STACK *sp)
{
 if(sp->top >= STACK_SIZE-1)
   return 1;
 else
  return 0;
}

int is_empty(STACK *sp)
{
 if(sp->top == -1)
   return(-1);
 else
  return 0;

}

void push(int item,STACK *sp)
{
 if(is_full(sp))
  {
    printf("Stack Overflow\n");
    return;
  }

 sp->top = sp->top+1;
 sp->stk[sp->top] = item;
}

int pop(STACK *sp)
{
 int item;
 if(is_empty(sp))
  {
    printf("Stack underflow\n");
    return 0;
  }
 item = sp->stk[sp->top];
 sp->top = sp->top - 1;
 return(item);
}

void display(STACK *sp)
{
 int i;
 if(is_empty(sp))
  {
   printf("\n Stack Is Empty!");
   return;
  }

 printf("The contents of the stack\n");
  for(i=sp->top;i>=0;i--)
  printf("\n%d",sp->stk[i]);

}



void main()
{

	int item,deleted_item,choice;

	STACK s;  // local variable 's'
	clrscr();
	s.top = -1;

	for(;;)
	{

	  printf("\n 1: PUSH\n 2: POP\n 3: DISPLAY\n 4: EXIT\n");
	  printf("\n Enter your choice\n");
	  scanf("%d",&choice);
	  switch(choice)
		{
			case 1: printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				push(item,&s);
				break;

			case 2:	deleted_item=pop(&s);
				printf("Item deleted:%d",deleted_item);
				break;

			case 3: display(&s);
				break;

		       default: exit(0);

		}//end of switch

	}//end of for

}//end of main