//PGM TO IMPLEMENT THE STRING AS ADT
#include <stdio.h>
#include <conio.h>
#include <string.h>

void concat(char s1[' '],char s2[' '])
{
int i,j;

for(i=0;s1[i]!='\0';i++);// finds the length of the string

for(j=0;s2[j]!='\0';j++)
{ 
  s1[i++]=s2[j];
}

s1[i]='\0';
printf("Concatenated String is: %s",s1);

}// end of concat

void subst(char s1[' '],int i, int j)
{
char sbst[' '];
int k,t,len;

//precondition
for(len=0;s1[len]!='\0';len++);// finds the length of the string
//printf("length of string is %d",len);

if( (i<0 || i>len) || (j<0 || j>len-i) )
  {
     printf("Not possible to extract substring\n");
     exit(0);
  }
else
  {
   for(k=i,t=0; t<j; k++,t++)
      sbst[t]=s1[k];

      sbst[t]='\0';

   printf("Substring is: %s",sbst);
  }
}


void main()
{

char s1[' '],s2[' '];
int i,j;
clrscr();

printf("\nEnter two strings to concatenate:");
scanf("%s %s",s1,s2);
concat(s1,s2);

printf("\nEnter a string to find substring:");
scanf("%s",s1);
printf("\nEnter starting position:");
scanf("%d",&i);
printf("\nEnter length of substring:");
scanf("%d",&j);
subst(s1,i,j);

getch();
}