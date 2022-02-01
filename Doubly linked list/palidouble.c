#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
typedef struct palidouble
{
    struct palidouble *left,*right;
    char data;
}node;
node *Left=NULL,*Right=NULL;
void insertRight(char c){
    node *temp=(node *)malloc(sizeof(node));
    temp->data=c;
    temp->left=NULL;
    temp->right=NULL;
    if(Left==NULL&&Right==NULL){
        Left=temp;
        Right=temp;
    }
    else
    {
        Right->right=temp;
        temp->left=Right;
        Right=temp;
    }
    
}
void insertLeft(char c){
    node *temp=(node *)malloc(sizeof(node));
    temp->data=c;
    temp->left=NULL;
    temp->right=NULL;
    if(Left==NULL&&Right==NULL){
        Left=temp;
        Right=temp;
    }
    else
    {
        Left->left=temp;
        temp->right=Left;
        Left=temp;
    }
    
}
void print(){
    node *temp=(node *)malloc(sizeof(node));
    temp=Left;
    if(Left==NULL&&Right==NULL){
        printf("Linked list is empty");
    }
    else
    {
      while (temp!=NULL)
      {
          printf("%c ",temp->data);
          temp=temp->right;
      }
      
    }
    free(temp);
    
}
bool isSameData(node *t1,node *t2){
    if (t1->data==t2->data)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    
}
bool isSameNode(node *t1,node *t2){
    if(t1->left==t2->left&&t1->right==t2->right)
    return true;
    else
    {
        return false;
    }
    
}
bool chechPali(){
    if(Left==NULL&&Right==NULL){
        printf("Linked list is empty");
        return true;
    }
    node *t1=(node *)malloc(sizeof(node));
     node *t2=(node *)malloc(sizeof(node));
     t1=Left;
     t2=Right;
   while (isSameData(t1,t2))
   {
       if(isSameNode(t1,t2))
       return true;
    t1=t1->right;
    t2=t2->left;
   }
   return false;
    

}
int main()
{
    int i;
    char c;
    while(1){
    printf("\n\n1-Insert left\n2-Insert right\n3-Print\n4-Check palindrome\nOthers-exit\n");
    scanf("%d",&i);
    switch (i)
    {
    case 1:
        printf("Enter the charactor\t");
        scanf("\t%c",&c);
        insertLeft(c);
        break;
    case 2:
        printf("Enter the charactor\t");
        scanf("\t%c",&c);
        insertRight(c);
        break;
    case 3:
        print();
        break;
    case 4:
        if (chechPali())
        {
            printf("The given string is a palindrome");
        }
        else
        {
            printf("The given string is not a palindrome");
        }
        
        break;
    default:
        return 0;
    }
    }
    
}

