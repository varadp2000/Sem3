#include<stdio.h>
int stack[20];
int top1=-1,top2=20;
void push(int ele,int pushnumber)
{
  int f,k;
  if(top2-top1==1)
  {
     printf("stack overflow\n" );
  }
  else
  {
    if(pushnumber==1)
    {
      top1++;
      stack[top1]=ele;
      printf("Current stack 1 is \n" );
      for(k=top1;k>=0;k--)
      printf("%d\n",stack[k] );
    }
    else if(pushnumber==2)
    { top2--;
      stack[top2]=ele;

    printf("Current stack 2is \n" );
    for(f=19;f>=top2;f--)

      printf("%d\n",stack[f]);

}}}

void pop()
{
  int b;
  printf("Enter stack number to pop from\n");
              scanf("%d",&b);
   if(b==1)
  {
if(top1==-1)
{
  printf("underflow\n" );
}
    else
{  printf("popped element is %d\n",stack[top1]);
    top1--;
  }}
else if(b==2)
{
  if(top2==20)
  {
    printf("underflow\n" );
  }else
  {printf("popped element is %d \n",stack[top2]);
  top2++;
}}
else
printf("invalid stack number\n");
   }
   void main()
{
int x,y,z,a,b,c,d,i,j;
do{
printf("Enter 1 , 2 , 3 for  push pop display and 4 for exit \t  " );
scanf("%d",&x );
switch (x)
{
  case 1:printf("Enter element and stack number \n" );
          scanf("%d %d",&y,&z);
         push(y,z);
             break;
 case 2:  pop();
        break;
  case 3:     printf("Current stack 1 is \n" );
               for(c=top1;c>=0;c--)
                 printf("%d\n",stack[c] );
                 printf("Current stack 2is \n" );
                 for(i=19;i>top2;i--)
                   printf("%d\n",stack[i]);
                break;
           case 4: printf("Exitting menu :) goodbye..... \n");
           break;
        default: printf("invalid option \n" );
      }}
      while (x!=4);
}
