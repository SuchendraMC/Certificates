// program to check the given string is Palindrome or not using stack
#include<string.h>
void main()
{
  int top=-1;
  char str[10],rev[10],s[10];
  int i,j=0;
  clrscr();

  printf("enter the string\n");
  scanf("%s",str);
  
  //pushing into stack( char by char )
  for(i=0;str[i]!='\0';i++)
   {
     s[++top]=str[i];
   }
   
   //poping out from stack( char by char )
   for(i=top;i>=0;i--)
    {
     rev[j++]=s[i];
    }
   rev[j]='\0';
   
   printf("Reversed string is %s\n",rev);
   if(strcmp(str,rev)==0)
      printf("Given string is a Palindrome");
    else
      printf("Given string is not a Palindrome");
   getch();
}
     