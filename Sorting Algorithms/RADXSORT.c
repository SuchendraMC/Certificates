//RADIX SORT Technique

#include<stdio.h>
#include<math.h>

struct node
{
  int info;
  struct node *link;
};

typedef struct node *NODE;

//returns jth digit of the item
int seperate(int item, int j)
{
  return ( item/(int)pow(10,j-1)%10 );
}

//returns largest of n items
int largest(int a[], int n)
{
  int i, big;
  big = a[0];
  for( i = 1; i<n; i++)
  {
    if(a[i] > big)
      big = a[i];
  }
  return big;
}

NODE insert_rear(int item, NODE first)
{
  NODE temp, cur;

  temp = (NODE)malloc(sizeof(struct node));
  temp->info = item;
  temp->link = NULL;

  if(first == NULL)
     return temp;

  cur = first;

  while(cur->link != NULL)
  {
    cur = cur->link;
  }

  cur->link = temp;
  return first;
}

void display(NODE first)
{
	NODE temp;
	if(first==NULL)
	{
		printf("NULL\n");
		return;
	}

	temp = first;
	while( temp!=NULL )
	{
	   printf("%d\t",temp->info);
	   temp = temp->link;
	   if(temp==NULL) printf("\n");
	}
}

void radix_sort( int a[], int n)
{
  int i, j, k, m, big, digit;
  NODE p[10], temp;

  big = largest(a, n);
  m = log10(big) + 1;  // m holds total number of digits 

  for( j=1; j<=m; j++) // till the number of digits of an element
  {
    for(i=0; i<=9; i++) // initializing array of pointers to NULL
      p[i] = NULL;

    for(i=0; i<n; i++)
    {
      digit = seperate(a[i], j);
      p[digit] = insert_rear( a[i], p[digit] ); //insert item in respective index
    }

    k = 0;
    printf("\nArray of linked lists:\n");
    for(i=0;i<=9;i++)// for each bucket 0 to 9
    {
      temp = p[i];
      printf("\np[%d]= ",i);
      display(temp);
      while(temp != NULL)
      {
	a[k++] = temp->info;
	temp = temp->link;
      }
    }
  }// end of outer for loop(j)
}//end of radix_sort()


void main()
{
  int i, n, a[20];
  clrscr();

  printf("\nRADIX SORT\n");
  printf("\nEnter the size of the list :");
  scanf("%d", &n);

  printf("\nEnter %d items :",n);
  for(i = 0; i<n ; i++)
  {
     scanf("%d",&a[i]);
  }

  radix_sort(a,n);

  printf("\nSorted List:\n\n");
  for(i = 0; i<n ; i++)
  {
     printf("%d\t",a[i]);
  }
  getch();
}
