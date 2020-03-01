//double ended queue
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct dequeue {
int Q[10];
int f,r;
}dq;

void insert_rear(int ele){

    if(dq.r == 9)
       printf("queue is full\n");
    else if(dq.f==-1 && dq.r==-1){
         dq.f=0;
         dq.r=0;
         dq.Q[dq.r]=ele;
      }
    else{
          dq.r++;
          dq.Q[dq.r]=ele;
      }

}


int remove_rear(){

    int x;
    if(dq.r==-1)
        printf("Underflow \n" );
    else if (dq.f==dq.r){
        x=dq.Q[dq.r];
        dq.f=-1; dq.r=-1;
        return x;
    }
    else{
        x=dq.Q[dq.r];
        dq.r--;
        return x;
    }

}

void insert_front(int ele){

    if(dq.r==9)
        printf("queue is full\n");
    else if(dq.f==-1){
        dq.f=0;
        dq.Q[dq.f]=ele;
        dq.r=0;
    }
    else if(dq.f==0){
        dq.f=9;
        dq.Q[dq.f]=ele;
    }
    else{
        dq.f--;
        dq.Q[dq.f]=ele;
    }

}
int remove_front(){

      int a;
      if(dq.f==-1 && dq.r==-1)
          printf("q is empty\n" );
      else if(dq.f==dq.r){
          a=dq.Q[dq.f];
          dq.f=-1;
          dq.r=-1;
          return(a);
      }
      else{
          a=dq.Q[dq.f];
          dq.f=(dq.f+1)%10;
          return(a);
        }
}

void display(){
      int i;
      for(i=dq.f;i!=dq.r;i=(i+1)%10)
          printf("%d\t",dq.Q[i]);
      printf("%d\t",dq.Q[i]);
}

  void main()
  {
    dq.f=-1;
    dq.r=-1;
    int x,ele,y;
    do{
    printf("\n Enter 1 to insert an element in the queue from front , \n 2 Enter 2 to remove and element from front\n Enter 3 to insert element from rear \n Enter 4 to remvove element from rear \n Enter 5 to display the existing elements of queue \n Enter 6 exit the menu\n");
    scanf("%d",&x);
    switch (x) {
      case 1 : printf("Enter the element to be inserted from front \n");
               scanf("%d",&ele);
               insert_front(ele);
               display();
               break;
      case 2: y=remove_front();
              printf("REmoved element was %d\n",y );
               break;
      case 3:printf("Enter element to be inserted from rear \n" );
             scanf("%d",&ele);
            insert_rear(ele);
            display();
            break;
      case 4:y=remove_rear();
              printf("Removed element was %d\n",y );
               break;
      case 5: display();
              break;
      case 6: printf("Exitting the menu :) \n" );
               break;
      default : printf("invalid option\n" );
    }
  }
  while(x!=6);
}
