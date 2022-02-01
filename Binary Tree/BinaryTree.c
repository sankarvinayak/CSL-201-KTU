#include <stdio.h>
#include <stdlib.h>

struct node
{
  char data;
  struct node *left;
  struct node *right;
};

void In_order_traversal(struct node *root){
  if (root == NULL)
  return;
  In_order_traversal(root->left);
  printf(" %c",root->data);
  In_order_traversal(root->right);
  
}

void Pre_order_traversal(struct node *root){
    if (root == NULL)
  return;
  printf(" %c",root->data);
  Pre_order_traversal(root->left);
  Pre_order_traversal(root->right);
}

void Post_order_traversal(struct node *root){
    if (root == NULL)
  return;
  Post_order_traversal(root->left);
  Post_order_traversal(root->right);
  printf(" %c",root->data);

}

struct node* createNode(char value){
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct node* insertLeft(struct node* root, char value) {
  root->left = createNode(value);
  return root->left;
}

struct node* insertRight(struct node* root, char value) {
  root->right = createNode(value);
  return root->right;
}

void delete(struct node* root){
  if (root == NULL)
  return;
  if(root->left!=NULL){
    delete(root->left);
  }
  if(root->right!=NULL){
    delete(root->right);
  }
  printf("\n%c deleted",root->data);
  free(root);
}

int main() {
  struct node* root = createNode('E');
  insertLeft(root, 'C');
  insertRight(root, 'D');
  insertLeft(root->left, 'A');
  insertRight(root->left, 'B');

  printf("Inorder traversal \n");
  In_order_traversal(root);

  printf("\nPreorder traversal \n");
  Pre_order_traversal(root);

  printf("\nPostorder traversal \n");
  Post_order_traversal(root);

  printf("\nDeleting Tree");
  delete(root);
  return 0;
}
