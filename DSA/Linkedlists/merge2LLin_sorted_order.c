//Merge 2 lL in sorted order..
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
newnode=(struct node *)malloc(sizeof(struct node));
tmp->next=newnode;
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
void print(struct node * head)                          //print entire linkedlist
{
struct node *tmp;
tmp=head;
while(tmp->next!=NULL)
{
printf("%d \t",tmp->data);
tmp=tmp->next;
}
printf("%d \t",tmp->data);
}

struct node * sort(struct node * head1,struct node * head2){   //joining 2  LL's and sorting 

      struct node * tmp;
      tmp=head1;
      int i,j;
      struct node * tmp1;
      tmp1=NULL;
      while(tmp->next!=NULL)
      {
      tmp=tmp->next;
      }
      tmp->next=head2;
      tmp=head1;
      int tmpdata;
      for(;tmp->next!=NULL;tmp=tmp->next){
        for(tmp1=tmp->next;tmp1!=NULL;tmp1=tmp1->next){
          if(tmp->data>tmp1->data){
             tmpdata=tmp->data;
             tmp->data=tmp1->data;
             tmp1->data=tmpdata;
          }
        }
      }

   return head1;

}



void main(){
  struct node *head1;
  struct node *head2;
head1= create_ll();
head2= create_ll();
printf("\n YOUR LINKEDLISTS : \n");
print(head1);
printf("\n");
print(head2);
printf(" \n YOUR LINKEDLISTS AFTER CONCATENATING IN SORTED ORDER: \n");
head1=sort(head1,head2);
print(head1);

}
