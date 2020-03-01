#include<stdio.h>
int stack[5];
int top=-1;
void push(int ele)
{
   if(top>=4)
   {
     printf("stack overflow\n" );
   }
   else
   {
     top++;
     stack[top]=ele;
      }
}
void pop()
{
   if(top==-1)
   {
     printf("underflow\n" );
   }
   else
   {
     printf("popped element is %d\n",stack[top] );
     top--;

   }
}
int stacktop()
{
  if (top==-1) {
     printf("Empty stack\n" );
  }
  else
  {
    printf("stack top is %d \n",stack[top]);
  }


}
void main()
{
  int x,y,z,a,b,c,i,j,k;

do{
printf("Enter 1 for push \n 2 for pop \n 3 for stacktop \n 4 to display current stack \n 5 to exit the menu \n" );
scanf("%d",&x );
switch (x)

 {
  case 1:printf("Enter a value to push to the stack\n" );
         scanf("%d",&y );
         push(y);
         printf("Current stack is\n" );
         for ( i = top; i>=0; i--)
          printf("%d\n",stack[i] );
          break;

  case 2: pop();
   break;
   case 3: stacktop();
   break;
   case 4: printf("The current stack is \n" );
   for ( i = top; i>=0; i--)
    printf(" %d \n ",stack[i] );
    break;
    case 5: printf("exitting menu goodbye \n" );
          break;
    default: printf("invalid option \n" );
  }}while (x!=5);
}
