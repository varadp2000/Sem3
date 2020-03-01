//Priority queue using Linked List.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
  int data;
  int priority;
  struct node * next;
};

struct node * create(){

    struct node * tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->next=NULL;
    printf("Enter data \n");
    scanf("%d",&tmp->data);
    printf("Enter its priority\n");
    scanf("%d",&tmp->priority);

    return tmp;
}

struct node * enqueue(struct node * head){

    struct node *tmp,*tmp1,*newnode;

    if(head==NULL)
        head=create();

    else{

      tmp=head;
      tmp1=head;
      newnode=create();

      if(head->priority < newnode->priority){
          tmp=head;
          head=newnode;
          newnode->next=tmp;
      }else{
          while(tmp->next!=NULL && tmp->next->priority >= newnode->priority)
              tmp=tmp->next;
          newnode->next = tmp->next;
          tmp->next = newnode;
      }

    }

  return head;
}

struct node * dequeue(struct node * head){

    if(head==NULL)
        puts("Queue Empty");
    else{
        struct node * tmp;
        tmp=head;
        head=head->next;
        printf("Removed Element : %d",tmp->data);
        tmp->next=NULL;
        free(tmp);
    }

  return head;
}

void display(struct node * head){

    struct node * tmp = head;
    while(tmp!=NULL){
        printf("%d \t",tmp->data);
        tmp=tmp->next;
    }
}

void main(){

    struct node * head=NULL;
    int choice;

    do{

      puts("\n 1 : Enqueue \n 2 : Dequeue \n 3 : Display Queue \n 4 : Exit.");
      scanf("%d",&choice);

      switch (choice) {
        case 1:
              head=enqueue(head);
              break;
        case 2:
              head=dequeue(head);
              break;
        case 3:
              display(head);
              break;
        case 4:
              puts("Exiting the menu.");
              break;
        default:
              puts("Invalid choice.");
      }

    }while(choice!=4);

}
