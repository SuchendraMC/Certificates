#include<stdio.h>
#include<conio.h>
#include<process.h>

#define STACK_SIZE 20
int top;
char s[20];
void push( char str )
{
  char item;
  int i;
  
  for(i=0;i<=strlen(str);i++)
    {
	item=str[i];

	if(top == STACK_SIZE-1)
	{
		printf("stack Overflow\n");
		return;
	}
	top = top + 1;
	s[top] = item;

    }//end of for
}//end of push

void pop( )
{
    char rev_str[20];
    while(top!=-1)
     {  	
	if(top == -1)
	{       rev_str[i]='\0';
		printf("%s",rev_str);
		printf("stack underflow\n");
		return 0;
	}

	rev_str[i++]=s[top];
		
	top = top - 1;

     }//end of while
	
}

void display( )
{
    int i;

	if(top == -1)
	{
		printf("stack underflow\n");
		return;
	}

	for( i=top; i>=0; i--)
	{

	printf("stack[%c] = %d\n",i,s[i]);
	
	}
}

void main()
{

	char str[20];
	int choice;
	clrscr();
	top= -1;
	
	for(;;)
	{
	
	  printf("\n 1: READ A STRING\n 2: REVERSING A STRINNG\n 3: EXIT\n");
	  printf("\n Enter your choice\n");
	  scanf("%d",&choice);
	  switch(choice)
		{
			case 1: printf("Enter the item to be inserted\n");
				scanf("%s",str);
				push(str);	
				break;

			case 2:	pop();	
				break;
			
                       default: exit(0);

		}//end of switch
	      
	}//end of for

}//end of main