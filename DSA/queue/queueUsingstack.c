//Queue Functions like insert and remove using Stack
#include<stdio.h>
#include<ctype.h>
int stack1[10],stack2[10];
int top1=-1;
int top2=-1;
void push1(int data){                       // push to the first stack
  if(top1==-1)
  {
    top1=0;
    stack1[top1]=data;
  }else if(top1==9){
    printf("Queue is full \n");
  }
  else{
    top1++;
    stack1[top1]=data;
  }
}
int pop1(){                              // pop from first stack
  if(top1==-1){
    printf("Queue is empty \n");
    return -1;
  }else{
    return stack1[top1--];
  }
}

void push2(int data){                       // push to the Secnd stack
  if(top2==-1){
    top2=0;
    stack2[top2]=data;
  }else if(top2==9){

  }
  else{
    top2++;
    stack2[top2]=data;
  }
}

int pop2(){                              // pop from Second stack
  if(top2==-1){
    printf("Queue is empty \n");
    return -1;
  }else{
    return stack2[top2--];
  }
}

void insert(int data){                               // insert to the queue
 push1(data);
}

int remove_queue(){                                       // remove one element from the queue
 int tmp;
 if(top2==-1){
   while(top1!=-1){
     tmp=pop1();
     push2(tmp);
   }
 } int x=pop2();
   printf("\n");
   return x;
}

void display()
{
 int i,j;
 for(i=top2;i>-1;i--){
    printf("%d \t",stack2[i]);
 }
 for(j=0;j<=top1;j++){
    printf("%d \t",stack1[j]);
 }
 printf("\n");
}


void main()
{ printf(" ******This is a Linear Queue***** \n");
 int ele,choice,x;
  do{
      printf(" Enter 1 to Insert Element , 2 to Remove Element , 3 to Display the Queue , 4 to exit the menu.\n");
      scanf("%d",&choice);
      switch (choice)
       {
        case 1: printf("Enter the Element to be inserted \n" );
                scanf("%d",&ele);
                insert(ele);
                display();
                break;
        case 2: x = remove_queue();
                printf("Popped Element is : %d ",x);
                printf("\n");
                break;
        case 3: display();
                break;
        case 4: printf("Exiting the menu ......\n");
                break;
        default:printf("Invalid choice\n");
       }
  }while(choice!=4);
}
