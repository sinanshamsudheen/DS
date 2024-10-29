//Muhammed Sinan D
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node* createNode(int data){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->right=NULL;
    new->left=NULL;
    new->data=data;
    return new;
}
struct Node* insert(struct Node* root,int val){
    if(root==NULL){
     return createNode(val);
    }
    if(val < root->data){
    root->left=insert(root->left,val);
    }
    else if(val > root->data){
        root->right=insert(root->right,val);
    }
    return root;
}
void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void main(){
    struct Node* root=NULL;
    root=insert(root,3);
    insert(root,6);
    insert(root,9);
    insert(root,1);
    insert(root,10);
    inorder(root);
    return;
}
//op-> 1 3 6 9 10