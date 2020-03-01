//hash table
// collision resolved using linear Probing
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define size 5

int table[size];

struct item{
    int key;
    int value;
};


int hash(int key){
    return key%size;
}

void insert(struct item temp){

    int hashcode = hash(temp.key);
    int i;
    for(i=hashcode ; i<size; i=(i+1)%size){
        if(table[i] == -1){
          table[i] = temp.key;
          break;
        }
    }

}

void search(int key){

    int hashcode = hash(key);
    int i;

    for(i=hashcode ; i<size; i=(i+1)%size){
        if(table[i]==key){
            printf("Key found at index : %d \n ",i);
            break;
        }
    }
}

void print(){
  int i;
  puts("Hash Table Keys: \n");
  for(i=0;i<size;i++)
      printf("%d\t",table[i]);
}

void main(){
    struct item item1,item2,item3,item4,item5;
    int i;
    for(i=0;i<size;i++)
        table[i]=-1;

    int choice;
    item1.key = 3; item2.key = 5; item3.key = 15; item4.key = 1; item5.key = 11;
    item1.value = 100; item2.value = 200; item3.value = 300; item4.value = 400; item5.value = 500;

    insert(item1);
    insert(item2);
    insert(item3);
    insert(item4);
    insert(item5);

    int k;
    print();

    do{

        puts("\n 2: Search \n 3: Display \n 4: Exit \n");
        scanf("%d",&choice);

        switch (choice) {
          case 2:
                puts("Enter Key to search its index in the hash table");
                scanf("%d",&k);
                search(k);
                break;
          case 3:
                print();
                break;
          case 4:
                puts("Exiting menu");
                break;
          default:
                puts("Invalid choice");
        }

    }while(choice!=4);

}
