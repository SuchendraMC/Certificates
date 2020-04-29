include<stdio.h>
#include<conio.h>
void main()
{
  char temp[20];
  char (*cp)[10];

  int i,j,n;
  clrscr();
  printf("Enter N value:");
  scanf("%d",&n);
  printf("Enter list of names\n");

  for( i=0; i<n ; i++ )
    scanf("%s", cp[i]);

  for( i=0; i<n-1; i++ )
    {
     for( j=i+1; j<n; j++ )
      {
	if( strcmp(cp[i],cp[j])>0 )
	  {
	    strcpy(temp,cp[i]);
	    strcpy(cp[i],cp[j]);
	    strcpy(cp[j],temp);
	  }
      }
    }

  printf("Sorted list of Names\n");
  for( i=0; i<n ; i++ )
    printf("%s\t", cp[i]);
  getch();
}

