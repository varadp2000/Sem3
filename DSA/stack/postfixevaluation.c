//postfix evaluation
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void push(char);
char pop();
char stack[20];
int top = -1;
void main(){
char op1,op2;
  int i,res,x;
  char postfix[50];
printf("Enter postfix eqn to evaluate" );
scanf("%s",postfix);
for(i=0;postfix[i]!='\0';i++)
{
if(isalnum(postfix[i]))
 push(postfix[i]-'0');
 else{
 op2=pop();
 op1=pop();
 switch(postfix[i])
 {
case '*':res=(int)op1 * (int)op2;
 break;
 case '/': res = (int)op1/ (int)op2;
 break;
 case '+' : res=(int)op1 + (int)op2;
 break;
 case '-' : res=(int)op1-(int) op2;
 break;
 default: printf("Invalid Op");

 }
 push(res);
}}
x=pop();
  printf("result is %d \n",x);
}


char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
void push(char x)
{
    stack[++top] = x;
}
