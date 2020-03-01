#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node * stack[20];
int top=-1;

struct node {
int data;
struct node * left;
struct node * right;
int flag;
};

struct node * create_tree(){                           //create a binary tree
  struct node * p;
  int x;
  printf("Enter data");
  scanf("%d",&x);
  if(x==-1)
   return NULL;
  p=(struct node *)malloc(sizeof(struct node));
  p->data=x;
  printf("Enter left child of %d",x);
  p->left=create_tree();
  printf("Enter right child of %d",x);
  p->right=create_tree();
  return p;
}

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
  return stack[--top];
}}


void preorder(struct node * t)                 //preorder traversal
{
  while(t!=NULL)
   {
     printf("%d \t",t->data);
     push(t);
     t=t->left;
   }
   while(top!=-1)
   {
    t=pop();
    t=t->right;
     while(t!=NULL)
       {
        printf("%d \t ",t->data);
        push(t);
        t=t->left;
        }
}}

void inorder(struct node *root)         //inorder Traversal
{
  struct node *t;
  t=root;
  while(t!=NULL){
    push(t);
    t=t->left;
  }
  while(top!=-1){
    t=pop();
    printf("%d \t",t->data);
    t=t->right;
    while(t!=NULL){
      push(t);
      t=t->left;
    }
}
}

void postorder(struct node * t)         //postorder Traversal
{
  while(t!=NULL){
    t->flag=0;
    push(t);
    t=t->left;
  }
  while(top!=-1){
    t=pop();
    if(t->flag==1)
      printf("%d\t",t->data);
     else{
      t->flag=1;
      push(t);
      t=t->right;
      while(t!=NULL){
        t->flag=0;
        push(t);
        t=t->left;
      }
  }
}
}
void main(){                                        //MAIN
  struct node * root;
  printf("******CREATEEE TREEE******** \n");
  root=create_tree();
  printf("\n");
  printf("Inorder Traversal: \t ");
  //inorder(root);
  printf("\n");
  printf("Preorder Traversal: \t ");
  //preorder(root);
  printf("\n");
  printf("Postorder Traversal: \t");
  //postorder(root);
  printf("\n");
}
