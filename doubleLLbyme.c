#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createNode(int data){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->next=NULL;
    newNode->prev=NULL;
    newNode->data=data;
    return newNode;
}
void insertAtpos(struct node** head,int data){
    struct node* ptr=*head;
    
}
void main(){
    
    return;
}