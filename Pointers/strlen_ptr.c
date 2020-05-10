//to find the length of a string using POINTERS
#include<stdio.h>
#include<conio.h>

	
main()
{
	char *str;
	char *name;
	int length;
	clrscr();
	printf("Enter a string\n");
	scanf("%s",name);
	
	str=name;
	while(*str != '\0')
	{
		printf("\n%c is stored at address %p\n",*str,str);    
		str++;
	}
	length=str-name;
	printf("String Length is %d\n",length);
	getch();
}