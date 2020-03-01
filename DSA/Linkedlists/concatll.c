//concat 2linkedlists    also // copy one ll into another
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
tmp=tmp->next;
}
printf("%d \t",tmp->data);
printf("\n");
}

struct node* concat(struct node* head1,struct node* head2)  //concat
{
struct node* tmp;
tmp=head1;
while(tmp->next!=NULL)
{
tmp=tmp->next;
}
tmp->next=head2;
return head1;
}


void copy(struct node * head)           //copy 1 ll into another
{
  struct node * head3;
  struct node * tmp,*tmp1;
  tmp=head;
  head3=(struct node *)malloc(sizeof(struct node));
  tmp1=head3;
  tmp1->data=tmp->data;
  while(tmp->next!=NULL)
  {
    tmp1->next=(struct node *)malloc(sizeof(struct node));
    tmp=tmp->next;
    tmp1=tmp1->next;
    tmp1->data=tmp->data;
  }
  tmp1->next=NULL;
  print(head);
  print(head3);


}
void main()                 //main
{
struct node* head1;
struct node* head2;
head1=create_ll();
print(head1);
head2=create_ll();
print(head2);
concat(head1,head2);
print(head1);
copy(head1);
}
