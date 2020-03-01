//Expression tree construction From Postfix
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

struct node * stack[20];                            //global stack
int top=-1;

struct node {                         //node
int data;
struct node * left;
struct node * right;
};

void push(struct node * t){                              //stack push
  if(top==-1){
    top=0;
    stack[top]=t;
    top++;
   }
  else if(top==19){
     printf("Stack full");
    }
  else{
   stack[top]=t;
   top++;
  }
}


struct node * pop(){                                   //stack pop
  if(top==-1){
   printf("Stack empty");
   return NULL;
 }else{
   top--;
  return stack[top];
}}


void inorder_without_stack(struct node * root){        //inorder_without_stack

 if(root!=NULL){
   inorder_without_stack(root->left);
   printf("%c\t",root->data);
   inorder_without_stack(root->right);
}}


struct node * expressionTree(char postfix[]){            //expressionTree from postfix.
  int i;
  struct node * p;
  for(i=0;i<strlen(postfix);i++){
    if(isalnum(postfix[i])){
        p=(struct node *)malloc(sizeof(struct node));
        p->left=NULL;p->right=NULL;
        p->data=postfix[i];
        push(p);
    }else{
      p=(struct node *)malloc(sizeof(struct node));
      p->data=postfix[i];
      p->right=pop();
      p->left=pop();
      push(p);
    }
  }
  p=pop();
return p;
}


void main(){
  char postfix[20];
  struct node * root;
  printf("Enter the postfix eqn.\n");
  gets(postfix);
  root=expressionTree(postfix);
  inorder_without_stack(root);
}
