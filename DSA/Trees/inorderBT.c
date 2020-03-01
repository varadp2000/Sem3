#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *l,*r;
};
struct node *stack[20];
int top=-1;

struct node *create(){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->l=NULL;
    newnode->r=NULL;
    return newnode;
}

struct node *createTree(){
	int x;
	struct node *newnode;
	printf("Enter Data\n");
	scanf("%d",&x);	
	if(x==-1)
		return NULL;
	newnode=(struct node *)malloc(sizeof(struct node));	
	newnode->data=x;
	printf("Enter Left Child of %d",x);
	newnode->l=createTree();
	printf("Enter Right Child of %d",x);
	newnode->r=createTree();

	return newnode;
}
void push(struct node *t){
	if(top==-1){
      top=0;
      stack[++top]=t;
   }
	else if(top==19)
		printf("Stack is Full\n");
	else
		stack[++top]=t;
}
struct node *pop(){
	if(top==-1)
		return NULL;
	else
		return stack[top--];
}

void inorder(struct node *root){
	struct node *t=root;
	while(t!=NULL){
		push(t);
		t=t->l;
	}
	while(top!=-1){
		t=pop();
		printf("%d\t",t->data);
		t=t->r;
		while(t!=NULL){
			push(t);
			t=t->l;
		}
	}
}

void traverse_preorder(struct node *root){
    if(root==NULL)
        return;
    traverse_preorder(root->l);
    traverse_preorder(root->r);
    printf("%d\t",root->data);
}


void main(){
	printf("Create Tree\n");
	struct node *root;
	root=createTree();
	printf("Traversig\n");
	traverse_preorder(root);
	printf("\n");
	inorder(root);

}