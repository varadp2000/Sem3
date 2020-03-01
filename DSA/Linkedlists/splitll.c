//split linkedlist
#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
};
struct node* head=NULL;
struct node* create_ll()
{
int n;
printf("Enter the no. of nodes to create for the linkedlistl\n" );
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
}
int size()                             //sizeof linkedlist
{
int c=1;
struct node *tmp;
tmp=head;
while(tmp->next!=NULL)
{
tmp=tmp->next;
c++; }
return c;
}

void print(struct node * head2)                          //print entire linkedlist
{
struct node *tmp;
tmp=head2;
while(tmp->next!=NULL)
{
printf("%d \t",tmp->data);
tmp=tmp->next;
}
printf("%d \t",tmp->data);
printf("\n");
}

struct node * split()
{
struct node * head1;
struct node* tmp;
tmp=head;
int i;
i=1;
while(i<size()/2)
{
  tmp=tmp->next;
  head1=tmp->next;
  tmp->next=NULL;
}
  return head1;
}


void main()
{
create_ll();
int a;
a=size();
printf("size is %d \n",a);
print(head);
struct node * head1=split();
print(head1);
print(head);
}
