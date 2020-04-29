#include <stdio.h>
#include<string.h>

#include<conio.h>

#define STACK_SIZE 30
char infix[30], prefix[30];

int G(char symbol)
{   switch(symbol)
     {
       case '+':
       case '-': return 2;

       case '*':
       case '/':  return 4;

       case '^':
       case '$':  return 5;

       case '(':  return 0;

       case ')':  return 9;

       default:   return 7;
     }
}

int F(char symbol)//stack Precedence
 {
  switch(symbol)
  {
       case '+':
       case '-': return 1;

       case '*':
       case '/': return 3;

       case '^':
       case '$': return 6;


       case ')': return 0;

       case '#': return -1;

       default:   return 8;
   }
}

void infix_to_prefix(char infix[], char prefix[])
{
int top, i, j;
char s[STACK_SIZE],symbol;
top = -1;
s[++top] = '#';
j = 0;
strrev(infix);
for(i=0;i<strlen(infix);i++)             //scan for all symbols from input string
{
   symbol = infix[i];
   while(F( s[top] ) > G( symbol ))  // stack precedence is greater, pop out & place into postfix
    {
      prefix[ j ] = s[top--];
      j++;
    }

   if(F( s[ top ] ) != G( symbol ))   // push the input symbol
     s[++top] = symbol;
   else  top--;                      //discard  ‘(‘ from stack
}

while ( s[top] != '#')                   //pop out remaining symbols & place it into postfix
{
 prefix[ j++] = s[top--];
}

prefix[ j ] ='\0';                         // end to frame a string

strrev(prefix);
}

void main( )
{
clrscr();
  printf("Enter a valid infix expression\n");
  scanf("%s",infix);

  infix_to_prefix(infix, prefix);

  printf("The prefix expression is:\n");
  printf("%s",prefix);
getch();
}
