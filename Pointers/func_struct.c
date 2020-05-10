//PGM TO DEMONSTRATE PASSING STRUCTURE VARIABLE AS PARAMETER
#include<stdio.h>
#include<conio.h>

int area(struct rectangle);//prototype

struct rectangle
{
  int length;
  int breadth;
};

main()
{
	struct rectangle rect;
	
	clrscr();
	pritnf("Enter the length and breadth of a rectangle\n"	);
	scanf("%d %d",&rect.length,&rect.breadth);
	pritnf("area of a rectangle:%d\n",area(&rect));
	getch();

}

int area(struct rectangle *rct)
{
	int res = rct->length * rct->breadth;
        return(res);
}



