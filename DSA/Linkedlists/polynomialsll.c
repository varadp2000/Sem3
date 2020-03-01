// add , subtract polynomials using linked list
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node {
int coeff;
int power;
struct node * next;
};

struct node *create_ll()
{
  int coeff1,power1,choice;
struct node * newnode;
struct node * head=NULL;
struct node * tmp;
head=(struct node *)malloc(sizeof(struct node));
head->next=NULL;
printf("Enter first coeff and power \n");
scanf("%d %d",&coeff1,&power1);
head->coeff=coeff1;
head->power=power1;
tmp=head;
do{
printf("Enter 1 to add another coeff to the eqn \n Enter 2 to save the polynomial  \n");
scanf("%d",&choice);
switch(choice) {
  case 1: printf("Enter the coeff and power of the variable ");
         scanf("%d %d",&coeff1,&power1);
         tmp->next=(struct node *)malloc(sizeof(struct node));
         tmp=tmp->next;
         tmp->coeff=coeff1;
         tmp->power=power1;
         break;
  case 2: printf("YOur polynomnial is  saved :\n");
       tmp->next=NULL;
         break;
default : printf("Invalid choice??\n ");
       }
     }while(choice!=2);

return head;
}
void display_ll(struct node * head)
{struct node * tmp;
  tmp=head;
while (tmp->next!=NULL) {
printf("%dx^%d + ",tmp->coeff,tmp->power);
tmp=tmp->next;
}
printf("%dx^%d",tmp->coeff,tmp->power);
printf("\n");
}

struct node * addll(struct node * head1, struct node * head2)
{
  struct node * tmp1 , * tmp2;
  for(tmp1=head1;tmp1->next!=NULL;tmp1=tmp1->next){
    for(tmp2=head2;tmp2->next!=NULL;tmp2=tmp2->next)
    { if(tmp1->power==tmp2->power)
      tmp1->coeff=tmp1->coeff+tmp2->coeff;
    }
  } if(tmp1->power==tmp2->power)
    tmp1->coeff=tmp1->coeff+tmp2->coeff;
return head1;
}
struct node * subtractll(struct node * head1 , struct node * head2){
  struct node * tmp1 , * tmp2;
  for(tmp1=head1;tmp1->next!=NULL;tmp1=tmp1->next){
    for(tmp2=head2;tmp2->next!=NULL;tmp2=tmp2->next)
    { if(tmp1->power==tmp2->power)
      tmp1->coeff=tmp1->coeff-tmp2->coeff;
    }
  } if(tmp1->power==tmp2->power)
    tmp1->coeff=tmp1->coeff-tmp2->coeff;
  return head1;

}


void main(){
  int choice;
  struct node * head1,* head2, *head3;
  printf("PS : MAKE SURE SECOND POLYNOMIAL IS NOT BIGGER THAN FIRST ONE\n ");
head1=create_ll();
display_ll(head1);
printf("\n");
head2=create_ll();
display_ll(head2);
printf("\n" );
printf("First polynomial is\n");
display_ll(head1);
printf("Second polynomial is \n" );
display_ll(head2);
printf("Enter 1 to add them and Enter 2 to subtract them... \n");
scanf("%d",&choice);
if(choice==1){
head3=addll(head1,head2);
printf("Their sum is\n" );
display_ll(head3);
}
else
{
head3=subtractll(head1,head2);
printf("Their subtraction is\n" );
display_ll(head3);
}}
