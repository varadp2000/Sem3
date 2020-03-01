#include<stdio.h>
#include<string.h>
int top=-1;
char str[50];
char stack[50];
void push(int ele)
{
if(top==49)
printf("Stack is full\n" );
else
{top++;
  stack[top]=ele;
}
}
char pop()
{
if(top==-1)
printf("Stack underflow\n");
else
{top--;
return (stack[top+1]);
}
}

void main()
{
  char adc[50];
  int i;
  printf("Enter a string\n" );
scanf("%s",str);
 for(i=0;i<strlen(str);i++)
   push(str[i]);
 for(i=0;i<strlen(str);i++)
  adc[i]=pop();
  printf("Reverse string is\n");
  for(i=0;i<strlen(str);i++)
  {
    printf("%c ",adc[i]);
  }

}
