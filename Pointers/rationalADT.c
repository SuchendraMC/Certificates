//PGM TO IMPLEMENT THE RATIONAL NUMBER AS ADT
 
#include<stdio.h>
#include<conio.h>

int rational[2];

void make_rational(int a, int b)
{
	if(b!=0)
	{
	  rational[0]=a; // numerator
	  rational[1]=b; // denominator

	  printf("\n");
	  printf("rational[0]= %d",rational[0]);
	  printf("\n");
	  printf("rational[1]= %d",rational[1]);
	  return;
	}
	else
	{
	  printf("Denominator cannot be zero!!");
	  return;
	}
}

void mult(int a,int b,int c,int d)
{
   int mul[2];
   make_rational(a,b);
   mul[0]=rational[0]; //  first rational number: numerator
   mul[1]=rational[1]; //  first rational number: denominator

   make_rational(c,d);
   mul[0]=mul[0]*rational[0];
   mul[1]=mul[1]*rational[1];
   printf("\n\nMultiplication of Rational Numbers");
   printf("\nmul[0]= %d",mul[0]);
   printf("\nmul[1]= %d",mul[1]);
}

void add_rational(int a,int b,int c,int d)
{
   int add[2];
   make_rational(a,b);
   add[0]=rational[0]; //  first rational number: numerator
   add[1]=rational[1]; //  first rational number: denominator

   make_rational(c,d);
   add[0]=add[0]*rational[1]+add[1]*rational[0];
   add[1]=add[1]*rational[1];
   printf("\nAddition of Rational Numbers");
   printf("\nadd[0]= %d",add[0]);
   printf("\nadd[1]= %d",add[1]);
}


void  equal_rational(int a,int b,int c,int d)
{

int eq[2];
make_rational(a,b);

eq[0]=rational[0];
eq[1]=rational[1];
make_rational(c,d);

eq[0]=eq[0]*rational[1];
eq[1]=eq[1]*rational[0];

if(eq[0]==eq[1])  
   printf("rational number are equivalent\n");
 
else
  printf("rational number are not equivalent\n");
 
}

main()
{
	int x,y,m,n;
	clrscr();
	printf("\nEnter two integer value\n");
	scanf("%d%d",&x,&y);
	printf("\nEnter two integer value\n");
	scanf("%d%d",&m,&n);
	mult(x,y,m,n);

	printf("\nEnter two integer value\n");
	scanf("%d%d",&x,&y);
	printf("\nEnter two integer value\n");
	scanf("%d%d",&m,&n);
	add_rational(x,y,m,n);

	printf("\nEnter two integer value\n");
	scanf("%d%d",&x,&y);
	printf("\nEnter two integer value\n");
	scanf("%d%d",&m,&n);
	equal_rational(x,y,m,n);

	getch();
}






