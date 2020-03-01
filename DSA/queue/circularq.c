#include<stdio.h>
int r=-1,f=-1;
int q[5];
void insert(int);
int rem();
void display();
void main()

{int x,ele,y;
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

void insert(int ele)
{
 if(f==-1 && r==-1)
 {f=0;
   r=0;
   q[r]=ele;
  }
  else if(r==4)
printf("queue is full\n");
  else
  {r=(r+1)%5;
    q[r]=ele;
  }
}

int rem()
{
  int a;
   if(f==r && r==-1)
  { printf("q is empty\n" );
}
else if(f==r)
{
  a=q[f];
  f=-1;
  r=-1;
  return (a);
}
else
{
  a=q[f];
  f=(f+1)%5;
  return(a);
}

  }

void display()
{
  int i;
  for(i=f;i!=r;i=(i+1)%5)
  printf("%d\n",q[i]);
printf("%d\n",q[i]);
}
