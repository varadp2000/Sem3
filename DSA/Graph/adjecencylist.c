#include<stdio.h>
#include<stdlib.h>
struct node{
	int v;
	struct node *next;
};
void create_graph(struct node *head[],int n){
	int neb,tmp;
	struct node *temp;
	for(int i=0;i<n;i++){
		temp=head[i];
		printf("Enter %d vertex\n",i);
		scanf("%d",&temp->v);
		printf("Enter no of Neighbours\n");
		scanf("%d",&neb);
		for(int j=0;j<neb;j++){
			struct node *newnode=(struct node *)malloc(sizeof(struct node));
			newnode->next=NULL;
			printf("Enter %d neighbour:",j+1);
			scanf("%d",&newnode->v);
			temp->next=newnode;
			temp=temp->next;
		}
	}
}

void display_graph(struct node *head[],int n){
	struct node *temp;
	for(int i=0;i<n;i++){
		temp=head[i];
		while(temp!=NULL){
			printf("%d\t",temp->v);
			temp=temp->next;
		}
		printf("\n");
	}
}

void main(){
	int n;
	printf("Enter no of vetices");
	scanf("%d",&n);
	struct node *head[n];
	for(int i=0;i<n;i++){
		head[i]=(struct node *)malloc(sizeof(struct node));
		head[i]->next=NULL;
	}
	create_graph(head,n);
	display_graph(head,n);
}