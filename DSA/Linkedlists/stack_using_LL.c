//stacks using LL   push-inert_front , pop-remove_front
#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node * next;
};
struct node * push(struct node* head, int ele)   //push i.e. insert_front to a ll
{
struct node * newnode,*tmp;
if(head==NULL)
{
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=ele;
  newnode->next=NULL;
  head=newnode;
}
else
{
newnode=(struct node *)malloc(sizeof(struct node));
newnode->next=head;
head=newnode;
head->data=ele;
}
return head;
}
struct node * pop(struct node * head)              //pop i.e. remove_front of ll
{int x;
struct node * tmp;
if(head==NULL)
printf("Empty stack\n" );
else {
tmp=head;
x=tmp->data;
head=tmp->next;
printf(" popped element is %d\n",x);
return head;
}}
void print(struct node * head2)                        //print entire linkedlist
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



void main()
{ struct node * head;
  head=NULL;
int choice,x,y;
do{
  printf("******MENUU*******\n");
printf("Enter 1 to push an element into the stack \n 2 to pop element from the stack \n 3 to display existing stack \n 4 to exit the menu\n");
scanf("%d",&choice );
switch (choice) {
  case 1:printf("Enter element to push into the stack\n" );
         scanf("%d",&x);
         head=push(head,x);
         print(head);
         break;
 case 2:head=pop(head);
        break;
 case 3:printf("Existing elements of the stack ::\n");
        print(head);
        break;
case 4:printf("Exitting the menu.....\n" );
        break;
default : printf("invalid choice??????????\n");
}
}while(choice!=4);
}
