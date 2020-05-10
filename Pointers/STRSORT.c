#include<stdio.h>
#include<conio.h>
main()
{
  char name[10][20],temp[20];
  int i,j,n;
  clrscr();
  printf("Enter N value:");
  scanf("%d",&n);
  printf("Enter list of names\n");
  for( i=0; i<n ; i++ )
    scanf("%s", name[i]);

  for( i=0; i<n-1; i++ )
    for( j=i+1; j<n; j++ )
      {
	if( strcmp(name[i],name[j])>0 )
	  {
	    strcpy(temp,name[i]);
	    strcpy(name[i],name[j]);
	    strcpy(name[j],temp);
	  }
      }
  printf("Sorted list of Names\n");
  for( i=0; i<n ; i++ )
    printf("%s\t", name[i]);
  getch();
}
