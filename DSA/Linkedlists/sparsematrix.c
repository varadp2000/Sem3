//Sparse Matrix..
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
  int row;
  int col;
  struct node * row;
  struct node * col;
};
struct node * create_row(struct node * head){
  head=(struct node *)malloc(sizeof(struct node));
  printf("Enter m and n \n");
  int m,n;
  scanf("%d",&m,&n);
  head->row=m;
  head->col=n;
  struct node * tmp;
  tmp=head;
  tmp->row=(struct node *)malloc(sizeof(struct node));
  tmp=tmp->row;
  
}
