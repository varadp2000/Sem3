//add , remove and print elements in linked list
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *head = NULL;
void insert_end(int ele)            //insert_end
{
struct node *newnode;
struct node *tmp;
newnode=(struct node*)malloc(sizeof(struct node));
if(head==NULL)
{
newnode->next=NULL;
newnode->data=ele;
head=newnode;
}
else
{
tmp=head;
while(tmp->next!=NULL)
{
tmp=tmp->next; }
tmp->next=newnode;
newnode->next=NULL;
newnode->data=ele;
tmp->next=newnode;
}
}
void insert_begin(int ele)               //insert_begin
{
  struct node *newnode;
if(head==NULL)
{
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=ele;
  newnode->next=NULL;
  head=newnode;
}
else
{
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=ele;
  newnode->next=head;
  head=newnode;
}
}
void insert_posi(int ele,int posi)        //insert_posi
{ struct node *tmp;
  struct node *newnode;
  int i;
  if(head==NULL)
  {
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->next=NULL;
    head=newnode;
  }
  else
  { tmp=head;
    for(i=1;i<posi-1;i++)
    tmp=tmp->next;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->next=tmp->next;
    tmp->next=newnode;
  }}
void remove_begin()              //remove_begin
{struct node* tmp;
  if(head!=NULL)
{ tmp=head;
  head=tmp->next;
  tmp->next=NULL;
  free(tmp);
} else
printf("linked list empty\n" );
}
void remove_end()
{ struct node *tmp,*tmp1;
  if(head!=NULL){                             //remove_end
tmp=head;
while(tmp->next!=NULL)
{
  tmp1=tmp;
  tmp=tmp->next;
}
tmp1->next=NULL;
free(tmp);
}
else
printf("EMPTY LIST\n");
}

void remove_posi(int posi)                 //remove posi
{
int i=1;
 struct node *tmp,*tmp1;
 if(head!=NULL)
{ tmp=head;
 while(i<posi)
  {
    tmp1=tmp;
    tmp=tmp->next;
    i++;
  }
  tmp1->next=tmp->next;
  tmp->next=NULL;
  free(tmp);
}
else
printf("EMPTY LIST \n" );
}

void print()                          //print entire linkedlist
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




void main()
{
int s,choice,ele,x,posi;
do {
printf("Enter 1 to insert an element \n Enter 2 to remove an element \n Enter 3 to display the list \n Enter 4 to exit :) ");
scanf("%d",&choice);
switch (choice) {
  case 1: printf("Enter the element" );
          scanf("%d",&ele);
         printf("Where do u want to enter the element ? \n press 1 for begginning \n 2 for end \n 3 for posi u want to enter ");
        scanf("%d",&x);
        if(x==1)
        {
           insert_begin(ele);
          print();
         }
         else if(x==2)
         { insert_end(ele);
        print(); }
         else
        { s=size();
         printf("Enter position between 1 and %d",s);
          scanf("%d",&posi);
          insert_posi(ele,posi);
         print();
         }
     break;
  case 2:printf("Enter 1 to remove element from begginning \n Enter 2 to remove element from end \n Enter 3 to remove element from a posi u want to choose\n");
      scanf("%d",&x);
      if(x==1)
      {
          remove_begin();
          print();
        }
        else if(x==2)
        {
          remove_end();
          print();
        }
          else
          {
            s=size();
             printf("Enter position between 1 and %d",s);
            scanf("%d",&posi);
            remove_posi(posi);
            print();
          }
         break;
  case 3: print();
      break;
  case 4: printf("Exitting the menu good bye\n");
          break;
    default : printf("Invalid choice ??? \n");
}
}while(choice!=4);
}
