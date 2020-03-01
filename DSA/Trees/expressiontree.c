#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node{
	char data;
	struct node *l,*r;
};

struct node *stack[20];
int top=-1;

void push(struct node *t){
	if(top==19)
		printf("StackOVerFlow");
	else
		stack[++top]=t;
}

struct node *pop(){
	if(top==-1)
		return NULL;
	else
		return stack[top--];
}

struct node *create(){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->l=NULL;
	newnode->r=NULL;
	return newnode;
}

struct node *tree(char postfix[]){
	struct node *t;
	int i;
	for(i=0;i<strlen(postfix);i++){
		if(isalnum(postfix[i])){
			t=create();
			t->data=postfix[i];
			push(t);
		}
		else{
			t=create();
			t->data=postfix[i];
			t->l=pop();
			t->r=pop();
			push(t);
		}
	}
	t=pop();
	return t;
}

void inorder(struct node *root){
	if(root!=NULL){
	inorder(root->l);
	printf("%c\t",root->data);
	inorder(root->r);
}
}
void main(){
	char postfix[10];
	printf("Enter Postfix\n");
	scanf("%s",postfix);
	struct node *root=NULL;
	root=tree(postfix);
	inorder(root);

}