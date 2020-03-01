//Priority queue using Array.
// int data is the priority itself.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int priQueue[10];
int f=-1,r=-1;

void enqueue(){

  int data,i,j;

    if(f==-1 && r==-1){
        r=0;
        f=0;
        printf("Enter Data\n");
        scanf("%d",&data);
        priQueue[r]=data;
    }
    else if(r==9){
        puts("Overflow");
    }
    else{
        printf("Enter Data\n");
        scanf("%d",&data);

        for(i=r;i>=0;i--){
            if(data > priQueue[i])
                priQueue[i+1] = priQueue[i];
            else
                break;
          }
        priQueue[i+1] = data;
        r++;
      }
  }

int dequeue(){

  if(r==-1){
      puts("Empty Queue");
      return 0;
  }
  else if(f==9){
      f==0;
      r==0;
      return priQueue[9];
  }
  else{
      return priQueue[f++];
  }
}

void display(){
  int i;
    if (f==r && r==-1)
        puts("\nQueue is empty");
    else{
        for(i=f; i<= r; i++)
            printf("%d\t", priQueue[i]);
      }
}

void main(){

    int choice;
    int data;
    do{

      puts("\n 1 : Enqueue \n 2 : Dequeue \n 3 : Display Queue \n 4 : Exit.");
      scanf("%d",&choice);

      switch (choice) {
        case 1:
              enqueue();
              break;
        case 2:
              data=dequeue();
              printf("Removed Element : %d \n",data);
              break;
        case 3:
              display();
              break;
        case 4:
              puts("Exiting the menu.");
              break;
        default:
              puts("Invalid choice.");
      }
    }while(choice!=4);

}
