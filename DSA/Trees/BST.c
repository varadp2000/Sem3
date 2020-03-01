#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *l,*r;
};
struct node *create(){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter Data\n");
	scanf("%d",&newnode->data);
	newnode->l=NULL;
	newnode->r=NULL;
	return newnode;
}
struct node *insert(struct node *root){
	if(root==NULL){
		root=create();
	}
	else{
		struct node *temp=root,*temp1=NULL,*newnode=create();
		while(temp!=NULL){
			temp1=temp;
			if(temp->data<newnode->data)
				temp=temp->r;
			else
				temp=temp->l;
			}
		if(temp1->data<newnode->data)
			temp1->r=newnode;
		else
			temp1->l=newnode;

	}
	return root;
}

int search(struct node *root,int ele){
	int flag=0;
	if(root==NULL){
		printf("Tree Empty\n");
		return 0;
	}
		else{
		struct node *p=root;
		while(p!=NULL){
			if(p->data==ele){
				flag=1;
				break;
			}
			if(ele>p->data)
				p=p->l;
			else
				p=p->r;
        }
        if(flag==1)
            return 1;
        else
            return 0;
    }
}

struct node *delete(struct node *root,int ele){
	if(root==NULL)
		return root;
	else{
		struct node *p=root,*q=NULL;
		int flag=0;
		while(p!=NULL){
			if(p->data==ele){
				flag=1;
				break;
			}
			q=p;
			if(ele>p->data)
				p=p->r;
			else
				p=p->l;
		}
		if(flag==1){
			if(p->l==NULL&&p->r==NULL){
				if(p==q->l)
					q->l=NULL;
				else
					q->r=NULL;
				free(p);
			}
			else if(p->l!=NULL&&p->r==NULL){
				if(p==q->l)
					q->l=p->l;
				else
					q->r=p->l;
				free(p);
			}
			else if(p->l==NULL&&p->r!=NULL){
				if(p==q->l)
					q->l=p->l;
				else
					q->r=p->l;
				free(p);
			}
			else{
				q=p;
				p->r;
				while(p->l!=NULL)
					p=p->l;
				int x=p->data;
				delete(root,p->data);
				q->data=x;
			}
		}
		return root;
	}

}

void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->l);
		printf("%d\t",root->data);
		inorder(root->r);
	}
	printf("\t");
	return;
}

void main(){
	struct node *root=NULL;
	int ch,temp;
	while(ch!=5){
		printf("\n\n1:insert\n2:search\n3:delete\n4:inorder\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			root=insert(root);
			break;
			case 2:
			printf("Enter Element to Search\n");
			scanf("%d",&temp);
			temp=search(root,temp);
			printf("\n\n%d\n\n",temp);
			break;
			case 3:
			printf("Enter Eement to Delete\n");
			scanf("%d",&temp);
			root=delete(root,temp);
			break;
			case 4:
			inorder(root);
			break;
		}
	}
}
