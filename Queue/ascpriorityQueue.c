/************************************************************
Program for implementing the ascending priority Queue
 ************************************************************/
/*Header Files*/
#include<stdio.h>
#include<conio.h>
#include<process.h>
#define size 5

int rear,front;
int que[size];
/*
 The Qfull function
 Input:none
 Output:1 or 0 for Qfull or not resp.
 Called By:main
 Calls:none
*/
Qfull()
{
if(rear ==size-1)
 return 1;
 else
  return 0;
}

/* The insert function
 Input:none
 Output:none
 Called By:main
 Calls:priority
*/
void insert()
{     int item;
	void priority();
	printf(“\nEnter the element\n”);
	scanf(“%d”,&item);
	if(front ==-1)
	front++;
	que[++rear]= item;
	priority();
}
/*
 The priority function
 Input:none
 Output:none
 Called By:insert
 Calls:none
*/
void priority()
{
 int i,j,temp;
 for(i=front;i<=rear-1;i++)
  for(j=front;j<rear;j++)
	if(que[j]>que[j+1])
	{
	 temp = que[j];
	 que[j] = que[j+1];
	 que[j+1] =temp;
	}
 }
/*
 The Qempty function
 Input:none
 Output:1 or 0
 Called By:main
 Calls:none
*/
Qempty()
{
 if((front==-1)||(front>rear))
  return 1;
 else
  return 0;
}
/* 
 The delet function
 Input:none
 Output:none
 Called By:main
 Calls:none
*/
void delet()
{
  int item;
  item=que[front];
  printf(“\n The item deleted is %d”,item);
  front++;
}
/*
 The display function
 Input:none
 Output:none
 Called By:main
 Calls:none
*/
void display()
{ int i;
 printf(“\n The queue is:”);
 for(i=front;i<=rear;i++)
 printf(“  %d”,que[i]);
}
/*
	Name:main()
	Input:none
	Output:none
	Calls:Qfull,Qempty,insert,delet,display
*/
void main(void)
   {
	int choice;
	char ans;
	clrscr();
	front=rear=-1;
	printf(“\n\t\t Priority Queue\n”);
	do
	{
	 printf(“\n Main Menu”);
	 printf(“\n1.Insert\n2.Delete\n3.Display”);
	 printf(“\n Enter Your Choice”);
	 scanf(“%d”,&choice);
	 switch(choice)
	 {
	  case 1:if(Qfull())
			   printf(“\n Queue IS full”);
			 else
			   insert();
			 break;
	  case 2:if(Qempty())
			   printf(“\n Cannot delete element”);
			  else
			   delet();
			  break;
	  case 3:if(Qempty())
			  printf(“\n Queue is empty”);
			 else
			  display();
			 break;
	   default:printf(“\n Wrong choice”);
			   break;
	 }
	  printf(“\n Do You Want TO continue?”);
	  ans =getche();
  }while(ans==’Y’ ||ans==’y’);
 getch();
}
