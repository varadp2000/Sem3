//create tree, count no of leaf nodes, traverse in all 3 ways. w/o stack..
//binary tree
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


struct node {
int data;
struct node * left;
struct node * right;
};

struct node * create_tree(){                           //create a binary tree
  struct node * p;
  int x;
  printf("Enter data");
  scanf("%d",&x);
  if(x==-1)
   return NULL;
  p=(struct node *)malloc(sizeof(struct node));
  p->data=x;
  printf("Enter left child of %d",x);
  p->left=create_tree();
  printf("Enter right child of %d",x);
  p->right=create_tree();
  return p;
}

int count_noof_leaf(struct node * root){            //no of leaf nodes
 if(root==NULL)
  return 0;
 if(root->left==NULL && root->right == NULL)
  return 1;
 else
  return (count_noof_leaf(root->left)+count_noof_leaf(root->right));
}

void inorder_without_stack(struct node * root){        //inorder_without_stack

 if(root!=NULL){
   inorder_without_stack(root->left);
   printf("%d \t",root->data);
   inorder_without_stack(root->right);
}}



void preorder_without_stack(struct node * t){        //preorder_without_stack
  if(t==NULL)
  return;
  printf("%d\t",t->data);
  preorder_without_stack(t->left);
  preorder_without_stack(t->right);
}

void postorder_without_stack(struct node *t){             //postorder_without_stack

    if(t==NULL)
    return;
    postorder_without_stack(t->left);
    postorder_without_stack(t->right);
    printf("%d\t",t->data);

}




void main(){                                        //MAIN
  struct node * root;
  printf("******CREATEEE TREEE******** \n");
  root=create_tree();
  printf("\n");
  int x=count_noof_leaf(root);
  printf("Leaf Count is %d",x);
  printf("\n");
  printf("\n");
  printf("Inorder Traversal: \t ");
  inorder_without_stack(root);
  printf("\n");
  printf("Preorder Traversal: \t ");
  preorder_without_stack(root);
  printf("\n");
  printf("Postorder Traversal: \t");
  postorder_without_stack(root);
  printf("\n");


}
