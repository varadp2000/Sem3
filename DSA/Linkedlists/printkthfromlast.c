//print K'th node from last of a lL
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

int size(struct node * head)                             //sizeof linkedlist
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

void print_Kth(struct node * head,int k){          //Print kth ele from last..
  struct node * tmp;
  tmp=head;
  int s=size(head);
  int b=s-k;
  int i;
  for(i=1;i<=b;i++){
    tmp=tmp->next;
  }
  printf("Data at Kth posi from the end is : %d \t",tmp->data );

}

void main(){
  int posi;
struct node * head;
head=create_ll();
printf("Enter Kth posi from end to check its data \n" );
scanf("%d",&posi);
print_Kth(head,posi);
}
