//circular q using structure ...
#include<stdio.h>
#include<ctype.h>
#include<string.h>

struct queue
{
int arr[5];
int f;
int r;
}q;

void insert(int ele)
{
 if(q.f==-1 && q.r==-1)
 {
   q.f=0;
   q.r=0;
   q.arr[q.r]=ele;
  }
  else if(q.f==(q.r+1)%5)
printf("queue is full\n");
  else
  {q.r=(q.r+1)%5;
    q.arr[q.r]=ele;
  }
}

int rem()
{
  int a;
   if(q.f==q.r && q.r==-1)
  { printf("q is empty\n" );
  return (-1);
}
else if(q.f==q.r)
{
  a=q.arr[q.f];
  q.f=-1;
  q.r=-1;
  return (a);
}
else
{
  a=q.arr[q.f];
  q.f=(q.f+1)%5;
  return(a);
}

  }

void display()
{
  int i;
  for(i=q.f;i!=q.r;i=(i+1)%5)
  printf("%d\n",q.arr[i]);
printf("%d\n",q.arr[i]);
}

void main()
{
q.f=-1;
q.r=-1;

  int x,ele,y;
  do{
  printf("Enter 1 to insert an element in the queue , \n 2 Enter 2 to remove and element from the queue \n Enter 3 to display the exiting elements of queue \n Enter 4 exit the menu\n");
  scanf("%d",&x);
  switch (x) {
    case 1 : printf("Enter the element to be inserted");
             scanf("%d",&ele);
             insert(ele);
             display();
             break;
    case 2: y=rem();
            printf("REmoved element was % d\n",y );
             break;
    case 3: display();
            break;
    case 4: printf("Exitting the menu :) \n" );
             break;
    default : printf("invalid option\n" );
  }
}
while(x!=4);
}
