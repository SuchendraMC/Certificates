#include<stdio.h>
#include<conio.h>

void tower(int n,char s, char t, char d)
{

 if(n==1)
  {
     printf("Move disc %d from %c to %c\n",n,s,d);
     return;
  }

  tower(n-1,s,d,t);

  printf("Move disc %d from %c to %c\n",n,s,d);

  tower(n-1,t,s,d);
  
}

void main()
{
  int n;
  clrscr();

  printf("Enter the number of discs:\n");
  scanf("%d",&n);

  tower(n,'A','B','C');
  getch();
}