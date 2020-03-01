//infix to prefix
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char stack[20];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)                            //priority
{
    if(x == '(' || x == ')')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
}

int isoperator(char symbol) {                      // is op
	switch(symbol) {
	         	case '+':
		        case '-':
		        case '*':
		        case '/':
		        case '^':
		        case '(':
		        case ')':
		        return 1;
		        break;
		        default: return 0;
		// returns 0 if the symbol is other than given above
	}
}

void main()
{
    char exp[20];
    char prefix[20];
    char x;
    printf("Enter the expression :: ");
    gets(exp);

    int j=0;
    strrev(exp);                       //reverse infix
     int i;
     j=0;
    for(i=0;i<strlen(exp);i++)
    {
       x=exp[i];
         if(isoperator(x)==0)
         {
           prefix[j]=x;
           j++;
         }else
         {
            if(x==')')
             {
               push(x);
             }
            else if(x=='(')
            {
              while (stack[top]!=')')
               {
				      	prefix[j]=pop();
					       j++;
               }
               pop();
            }
            else
            {
               if(priority(stack[top])<=priority(x))
               {
                 push(x);
               }
               else
               {
                 while(priority(stack[top])>=priority(x))
                 {
                   prefix[j]=pop();
                   j++;
                 }
                 push(x);
               }
            }
         }
       }
       while(top!=-1)
       {
         prefix[j]=pop();
         j++;
       }
       prefix[j]='\0';
       printf("Preffix exppn is\n" );
       strrev(prefix);
       puts(prefix);
     }
