//pgm to illustrate the pointer to structures
#include<stdio.h>
#include<conio.h>

struct rectangle
{
  int length;
  int breadth;
};

main()
{
	struct rectangle rect;
	struct rectangle *ptr;
	clrscr();
	pritnf("Enter the length and breadth of a rectangle\n"	);
	scanf("%d %d",&rect.length,&rect.breadth);
	printf("Using structure variable:\n"	);
	printf("area of a rectangle:%d\n",rect.length * rect.breadth);

	ptr=&rect;
	printf("\nUsing pointer to structure :\n"	);
	printf("Using structure variable:\n"	);
	printf("area of a rectangle:%d\n",ptr->length * ptr->breadth);
//	printf("area of a rectangle:%d\n",(*ptr).length * (*ptr).breadth);


	getch();

}