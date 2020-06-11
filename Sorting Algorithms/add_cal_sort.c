//ADDRESS CALCULATION SORT OR HASH SORT

#include<stdio.h>
#include<math.h>

struct node
{
  int info;
  struct node * link;
};

typedef struct node *NODE;

NODE order_insert(int item, NODE first)
{
  NODE temp, prev, cur;

  temp = (NODE)malloc(sizeof(struct node));
  temp->info = item;
  temp->link = NULL;
 
  if(first == NULL)
     return temp;

  if(item < first->info)
  {
    temp->link = first;
    return temp;
  }
 
  prev = NULL;
  cur = first;
  
  while(cur != NULL && item >= cur->info)
  {
    prev = cur;
    cur = cur->link;
  }

  prev->link = temp;
  temp->link = cur;
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

int hash( int a[20], int n )
{
  int big, i;
  big = a[0];
  for(i = 1; i < n ; i++)
  {
    if(a[i] > big)
       big = a[i];
  }

  i = log10(big); 

  return (pow(10,i)); // returns place value of MSD of the big
}

void hashsort( int a[20], int n )
{
  NODE b[10], temp;
  int i, j, digit,hashvalue;

  hashvalue = hash(a,n);

  for(i = 0; i < 10; i++)
  {
     b[i] = NULL; // initializing array of roots with NULL
  }

  for(i = 0; i < n; i++)
  {
     digit = (a[i]/hashvalue);   // digit represents location

     b[digit] = order_insert(a[i], b[digit]);
  }
  
  j=0;
  printf("\nArray of linked lists:\n");
  for( i = 0;  i<10 ; i++)//buckets 0-9
  {
     temp = b[i];
     printf("\nb[%d]= ",i);
     display(temp);

     while(temp != NULL)
     {
	a[j++] = temp->info;
	temp = temp->link;
     }
  }
}//end of hashsort

void main()
{
  int i, n, a[20];
  clrscr();

  printf("\nADDRESS CALCULATION SORT\n");
  printf("\nEnter the size of the list :");
  scanf("%d", &n);

  printf("\nEnter %d items :",n);
  for(i = 0; i<n ; i++)
  {
     scanf("%d",&a[i]);
  }

  hashsort(a,n);

  printf("\nSorted List:\n\n");
  for(i = 0; i<n ; i++)
  {
     printf("%d\t",a[i]);
  }
  getch();
}
