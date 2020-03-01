//queue using LL - insert element-insert_end - remve - remove_front
#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node * next;
};
struct queue{
  struct node * front;
  struct node * rear;
};

struct node * create_node(int ele)              //create one node at end
{
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->next=NULL;
  newnode->data=ele;
  return newnode;

}

struct queue insert(struct queue q,int ele)    //insert element
{
  struct node * newnode;
if(q.front==NULL && q.rear==NULL)
{
newnode=create_node(ele);
q.front=newnode;
q.rear=newnode;
}
else
{
newnode=create_node(ele);
q.rear->next=newnode;
q.rear=q.rear->next;
}
return q;
}

struct queue rem(struct queue q)      // remove_front
{
  struct node * tmp;
if(q.front==NULL && q.rear== NULL)
  printf("Empty queue\n" );
else if(q.front==q.rear)
{   printf("removed element is : %d \n",q.front->data);
 q.front=NULL;
 q.rear=NULL;
 free(q.rear);
}
else
{
tmp=q.front;
printf("removed element is :%d\n",q.front->data );
q.front=q.front->next;
  tmp=NULL;
  free(tmp);
}
  return q;
}

void display(struct queue q)
{
  struct node * tmp;
  tmp=q.front;
  printf("%d\n",tmp->data);
  while(tmp->next!=NULL)
  {
   tmp=tmp->next;
   printf("%d\n",tmp->data);

  }
}
void main()
{
struct queue q;
struct node * head;
head=NULL;
q.front=NULL;
q.rear=NULL;
int choice,x,y;
do{
  printf("******MENUU*******\n");
printf("Enter 1 to insert an element into the queue \n 2 to remove element from the queue \n 3 to display existing queue \n 4 to exit the menu\n");
scanf("%d",&choice );
switch (choice) {
  case 1:printf("Enter element to push into the queue\n" );
         scanf("%d",&x);
        q=insert(q,x);
         display(q);
         break;
 case 2:q=rem(q);
        break;
 case 3:printf("Existing elements of the queue ::\n");
      display(q);
        break;
case 4:printf("Exitting the menu.....\n" );
        break;
default : printf("invalid choice??????????\n");
}
}while(choice!=4);
}
