/*PROGRAM TO SEARCH ELEMENT USING BINARY SEARCH TECHNIQUE..
	BINARY SEARCH IS TECHNIQUE TO SEARCH THE ELEMENT FROM LIST IT DIVIDES
	THE LIST IN TWO PARTS FROM MID POSITION AND COMPARES WITH MID ELEMENT.
	IF THE MID THEN ELEMENT FOUND ,OTHERWISE CHECK IT IS SMALLER OR
	GREATER IF SMALLER ,THEN SEARCH IN FIRST HALF PART OF THE LIST OTHERSIE SEARCH IN THE SECOND
	HALF .REPEAT THESE STEPS. BUT TO PERFORM BINARY SERCH DATA MUST BE IN SORTED FORM...*/


#include<stdio.h>
#include<conio.h>

void sort(int [],int);
void b_serch(int [],int); //prototype declaration of function

int main()
{
int n,a[10],i;
clrscr();
printf("Enter the value of n: ");
scanf("%d",&n);
printf("\n Enter the element in array:\n");
for(i=0;i<n;i++)
   scanf("%d",&a[i]);
printf("Serching using binary serch:\n ");
b_serch(a,n);
getch();
return;
}


//BINARY SERCH......
void b_serch(int a[],int n)
{
int m,l=0,h=n-1,e;
sort(a,n);
printf("\nEnter the element to serch: ");
scanf("%d",&e);
l=0;
while(l<=h)
{
m=(l+h)/2 ; 	//FINDING MID POSITION
	if(e==a[m])
	{
		printf("\nNumber found :");
		getch();
		exit();
	}
	else if(e<a[m])
	{
		h=m-1;
		l=l;
	}
	else
	{
		l=m+1;
		h=h;
	}
}
printf("\nNumber not found!!!");
}


//sorting of number because to perform binary serch data must be sorted
void sort(int a[],int n)
{
int i,j,temp,l;
for(i=1;i<n;i++)
{
temp=a[i];
l=0;
	for(j=i-1;j>=0&&!l;)
	{
		if(temp<a[j])
		{
		a[j+1]=a[j];
		j--;
		}
		else
		l=1;
	}
a[j+1]=temp;
}
}
