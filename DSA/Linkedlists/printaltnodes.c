//print alternade nodes of a lL
#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
};
struct node* create_ll()                  //create ll
{
  struct node* head=NULL;
int n;
printf("Enter the no. of nodes to create for the linkedlist\n" );
scanf("%d",&n);
struct node* newnode;
head=(struct node *)malloc(sizeof(struct node));
head->next=NULL;
printf("Enter data \n");
scanf("%d",&head->data);
struct node* tmp;
tmp=head;
int i=1;
do
{
tmp->next=(struct node *)malloc(sizeof(struct node));
tmp=tmp->next;
printf("Enter data \n");
scanf("%d",&tmp->data);
i++;
}while(i<n);
tmp->next=NULL;
return head;
}

void print(struct node * head2)                          //print entire linkedlist
{
struct node *tmp;
tmp=head2;
while(tmp->next!=NULL)
{
printf("%d \t",tmp->data);
tmp=tmp->next->next;
}
printf("%d \t",tmp->data);
printf("\n");
}




void main(){
 struct node * head1;
 head1=create_ll();
 print(head1);

}