//All Bst functions of 6.1
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node * stack[20];                            //global stack
int top=-1;

struct node {                         //node
int data;
struct node * left;
struct node * right;
int flag;
};

void push(struct node * t){                              //stack push
  if(top==-1){
    top=0;
    stack[top]=t;
    top++;
   }
  else if(top==19){
     printf("Stack full");
    }
  else{
   stack[top]=t;
   top++;
  }
}


struct node * pop(){                                   //stack pop
  if(top==-1){
   printf("Stack empty");
   return NULL;
 }else{
   top--;
  return stack[top];
}}



int count_noof_leaf(struct node * root){            //no of leaf nodes
 if(root==NULL)
  return 0;
 if(root->left==NULL && root->right == NULL)
  return 1;
 else
  return (count_noof_leaf(root->left)+count_noof_leaf(root->right));
}

int count_noof_interior(struct node * root){       //no of interior nodes
     if (root == NULL || (root->left == NULL && root->right == NULL))
       return 0;
     else
       return 1 + count_noof_interior(root->left) +
              count_noof_interior(root->right);
}

int count_noof_nodes(struct node * root){        //no of nodes
  int count=1;

 if(root == NULL)
      return 0;
 else{

   if (root->left != NULL) {
      count += count_noof_nodes(root->left);
    }

    if (root->right != NULL) {
       count += count_noof_nodes(root->right);
    }
    return count;
   }
 }

void inorder(struct node *root)         //inorder Traversal
{
  struct node *t;
  t=root;
  while(t!=NULL){
    push(t);
    t=t->left;
  }
  while(top!=-0){
    t=pop();
    printf("%d \t",t->data);
    t=t->right;
    while(t!=NULL){
      push(t);
      t=t->left;
    }
  }
}

struct node * insert(struct node * t,int ele){           //insert an element to the binary tree
  struct node * r=(struct node *)malloc(sizeof(struct node));
  r->data=ele;
  r->right=NULL;r->left=NULL;
  struct node * p=t;
  struct node * q;
  if(t==NULL){
    return r;
  }

  while(p!=NULL){
    q=p;
    if(ele<p->data)
      p=p->left;
    else
      p=p->right;
}
  if(ele<q->data)
    q->left=r;
  else
    q->right=r;
  return t;
}

int search(struct node * root,int ele){            //search for an element
   struct node * tmp;
   tmp=root;
   if(root==NULL){
    printf("Empty tree \n");
  }else{
   int flag=0;
   while(tmp!=NULL){
     if(ele==tmp->data){
       flag=1;
       break;
     }else if(ele<tmp->data){
       tmp=tmp->left;
     }else{
       tmp=tmp->right;
     }
   }

    if(flag==1){
      printf("The Element Exists in the tree.\n");
      return 1;
    }else{
      printf("The Element does not exist.\n");
      return 0;
    }
  }

}

struct node * delete(struct node * root,int x){       //4 cases of delete from the bt
  if(search(root,x)==0){
     printf("Node does not exist\n");
     return root;
  }
  else{
    struct node * q;
    struct node * tmp=root;
    int flag=0;
      while(tmp!=NULL){
        if(x==tmp->data){
          flag=1;
          break;
        }
        else if(x<tmp->data){
          q=tmp;
          tmp=tmp->left;
        }
        else{
          q=tmp;
          tmp=tmp->right;
        }
      }
      if(flag==1){
       //case 1 : Leaf Node
       if(tmp->left==NULL && tmp->right==NULL){
            if(tmp==q->right)
                q->right=NULL;
           }else
                q->left=NULL;
       //case2: left subtree
      else if(tmp->left!=NULL && tmp->right==NULL){
            if(tmp==q->left)
                q->left=tmp->left;
            else
                q->right=tmp->left;
           }
        //case3: right subtree
        else if(tmp->right!=NULL && tmp->left ==NULL){
            if(tmp==q->right)
                q->right=tmp->right;
            else
                q->left=tmp->right;
           }
        //case4: Both the subtrees
        else{
          struct node * p=tmp->right;
          while(p->left!=NULL){
            p=p->left;
            int n=p->data;
            delete(root,p->data);
            tmp->data=n;
          }
        }
      }
      return root;
   }
}


void main()         //main
{
  struct node * root=NULL;
  int choice;
  do{
    puts(" \n Enter 1 to insert an element \n Enter 2 to Delete an element \n Enter 3 to Traverse(in inorder way and print the tree) \n Enter 4 to Search  an element in the tree \n Enter 5 to Count the no. of nodes in the tree \n Enter 6 to count no. of leaf nodes \n Enter 7 to count no of interior nodes \n Enter 8 to exit the menu..\n ");
    scanf("%d",&choice);
    switch (choice) {
      case 1:printf("Enter the element\n");
             int ele;
            scanf("%d",&ele);
            root=insert(root,ele);
            break;
      case 2:printf("Enter the node u want to delete\n");
             int deleteNode;
             scanf("%d",&deleteNode);
             root=delete(root,deleteNode);
            break;
      case 3:printf("The tree in inorder traversal is : \n" );     //minute bug : fixed.
            inorder(root);
            break;
      case 4:printf("Enter the element you want to search .\n" );
            int searchele;
            scanf("%d",&searchele);
            search(root,searchele);
            break;
      case 5:printf("The total no of nodes in the tree is : %d\n",count_noof_nodes(root));
            break;
      case 6:printf("The total no of leaf nodes in the tree is : %d \n",count_noof_leaf(root));
            break;
      case 7:printf("The total no of interior nodes in the tree is : %d \n",count_noof_interior(root));
            break;
      case 8:printf("Exitting the menu.....\n");
            break;
      default: printf("Invalid Choice... \n");
    }
  }while(choice!=8);
}
