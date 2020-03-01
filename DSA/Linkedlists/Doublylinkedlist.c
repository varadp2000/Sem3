//insert remove and traverse doubly linkedlist
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
struct node *prev;
};

struct node * traverse_frwd(struct node *);
int size(struct node *);

struct node * insert_begin(struct node * head,int ele){ //insert_begin
  struct node *newnode;
if(head==NULL)
{
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=ele;
  newnode->next=NULL;
  newnode->prev=NULL;
  head=newnode;
}else{
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=ele;
  newnode->next=head;
  newnode->prev=NULL;
  head=newnode;
}
return head;
}


struct node * insert_end(struct node * head,int ele){  //insert_end
  struct node *newnode;
  struct node *tmp;
  newnode=(struct node*)malloc(sizeof(struct node));
  if(head==NULL)
  {
  newnode->next=NULL;
  newnode->prev=NULL;
  newnode->data=ele;
  head=newnode;
  }
  else{
   tmp=head;
   tmp=traverse_frwd(tmp);
   tmp->next=newnode;
   newnode->next=NULL;
   newnode->prev=tmp;
   newnode->data=ele;
  }
return head;
}
struct node * insert_posi(struct node * head,int ele,int posi){  //insert_posi
    struct node *tmp;
    struct node *newnode;
    int i;
    if(head==NULL)
    {
      newnode=(struct node*)malloc(sizeof(struct node));
      newnode->data=ele;
      newnode->prev=NULL;
      newnode->next=NULL;
      head=newnode;
    }
    else{
        tmp=head;
        for(i=1;i<posi-1;i++)
        tmp=tmp->next;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=ele;
        newnode->next=tmp->next;
        newnode->prev=tmp;
        tmp->next=newnode;
    }
return head;
}

struct node * remove_end(struct node * head){
  struct node *tmp,*tmp1;
    if(head!=NULL){                                   //remove_end
  tmp=head;
  while(tmp->next!=NULL)
  {
    tmp1=tmp;
    tmp=tmp->next;
  }
  tmp1->next=NULL;
  tmp->prev=NULL;
  free(tmp);
  }
  else
  printf("EMPTY LIST\n");
  return head;
  }


  struct node * remove_begin(struct node * head){     //remove_begin
    struct node* tmp;
      if(head!=NULL)
    { tmp=head;
      head=tmp->next;
      head->prev=NULL;
      tmp->next=NULL;
      free(tmp);
    } else{
    printf("linked list empty\n" ); }
    return head;
  }


  struct node * remove_posi(struct node * head,int posi)                 //remove posi
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
    tmp->next->prev=tmp1;
    tmp->next=NULL;
    tmp->prev=NULL;
    free(tmp);
  }
  else{
  printf("EMPTY LIST \n" ); }
  return head;
  }


void print(struct node * head)                          //print entire linkedlist
{

if(head==NULL){
  printf("EMpty linkedlist \n");
}else{

struct node *tmp;
tmp=head;
while(tmp->next!=NULL)
{
printf("%d \t",tmp->data);
tmp=tmp->next;
}
printf("%d \t",tmp->data);
printf("\n");
}}

struct node * traverse_frwd(struct node * tmp){     //traverse_frwd
  while(tmp->next != NULL){
    tmp=tmp->next;
  }
  return tmp;
}
struct node * traverse_prev(struct node * tmp){       //traverse_prev
  while(tmp->prev!=NULL){
    tmp=tmp->prev;
  }
  return tmp;
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

void main()                                             //main
{
  struct node * head;
  head=NULL;
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
           head=insert_begin(head,ele);
           print(head);
         }
         else if(x==2)
         { head=insert_end(head,ele);
        print(head);
         }
         else
        { s=size(head);
         printf("Enter position between 1 and %d",s);
          scanf("%d",&posi);
          head=insert_posi(head,ele,posi);
          print(head);
         }
     break;
  case 2:printf("Enter 1 to remove element from begginning \n Enter 2 to remove element from end \n Enter 3 to remove element from a posi u want to choose\n");
      scanf("%d",&x);
      if(x==1)
      {
          head=remove_begin(head);
          print(head);
        }
        else if(x==2)
        {
          head=remove_end(head);
          print(head);
        }
          else
          {
            s=size(head);
             printf("Enter position between 1 and %d",s);
            scanf("%d",&posi);
            head=remove_posi(head,posi);
            print(head);
          }
         break;
  case 3: print(head);
      break;
  case 4: printf("Exitting the menu good bye\n");
          break;
    default : printf("Invalid choice ??? \n");
}
}while(choice!=4);
}
