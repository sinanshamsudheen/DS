#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->data=data;
    return newNode;
}
void insert(struct Node** root,int data){
    struct Node* newNode=createNode(data);
    if(*root==NULL){
        *root=newNode;
        return;
    }
    struct Node* Q[100];
    struct Node* temp;
    int front=-1,rear=-1;
    Q[++rear]=*root;
    while(front!=rear){
        temp=Q[++front];
        if(temp->left==NULL){
            temp->left=newNode;
            return;
        }
        else{
            Q[++rear]=temp->left;
        }
        if(temp->right==NULL){
            temp->right=newNode;
            return;
        }
        else{
            Q[++rear]=temp->right;
        }
    }
}
void delete(struct Node** root,int item){
    if(*root==NULL){
        printf("Tree is empty.\n");
        return;
    }
    if((*root)->left==NULL && (*root)->right==NULL){
        if((*root)->data==item){
            free(*root);
            *root=NULL;
            return;
        }else{
            printf("item not found");
        }
    }
    struct Node* temp=NULL;
    struct Node* keyNode=NULL;
    struct Node* Q[100];
    int front=-1,rear=-1;

    while(front!=rear){
        temp=Q[++front];
        if(temp->data==item){
            keyNode=temp;
        }
        if(temp->left!=NULL){
            Q[++rear]=temp->left;
        }
        if(temp->right!=NULL){
            Q[++rear]=temp->right;
        }
    }
    //this is incomplete :)
}
void inorderTraversal(struct Node* root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}

void main(){
    struct Node* root=NULL;
    insert(&root,9);
    insert(&root,4);
    insert(&root,3);
    insert(&root,12);
    insert(&root,2);
    inorderTraversal(root);
    return;
}