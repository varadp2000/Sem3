#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *l,*r;
};

struct node *stack[20];
int top=-1;

void push(struct node *t){
	if(top==-1){
		top=0;
		stack[++top]=t;
	}
	else if(top==19){
		printf("StackOverFlow\n");
	}
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
	struct node *newnode;
	int x;
	printf("Enter Data");
	scanf("%d",&x);
	if(x==-1)
		return NULL;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=x;
	printf("Enter left child of %d",x);
	newnode->l=create();
	printf("Enter right child of %d",x);
	newnode->r=create();

	return newnode;	
}

void traverse(struct node *root){
	struct node *t=root;
	while(t!=NULL){
		printf("%d\t",t->data);
		push(t);
		t=t->l;
	}
	while(top!=-1){
		t=pop();
		t=t->r;
		while(t!=NULL){
		printf("%d\t",t->data);
		push(t);
		t=t->l;
		}
	}
}

void main(){
	printf("create tree\n");
	struct node *root=create();
	printf("traverse\n");
	traverse(root);
}