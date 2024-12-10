#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->next=NULL;
    newNode->prev=NULL;
    newNode->data=data;
    return newNode;
}
void insertAtend(struct Node** head,int data){
    struct Node* new=createNode(data);
	if(*head==NULL){
        *head=new;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
    new->prev=temp;
}
void insertAtpos(struct Node** head,int data,int key){
    struct Node* new=createNode(data);
    struct Node* temp=*head;
    while(temp->next!=NULL && temp->data!=key){
        temp=temp->next;
    }
    if(temp->next==NULL){
        printf("key not found!\n");
        return;
    }
    new->next=temp->next;
    temp->next=new;
}
void deleteAtend(struct Node** head){
    if(*head==NULL){
        return;
    }
    struct Node* temp=*head;
    struct Node* prev=*head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}
void deleteAthead(struct Node** head){
    if(*head==NULL){
        return;
    }
    struct Node* temp=*head;
    temp=temp->next;
    *head=temp;
}
void traverse(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        temp=temp->next;
    }printf("NULL\n");
}

void main(){
    struct Node* head=NULL;
    insertAtend(&head,1);
    insertAtend(&head,2);
    insertAtend(&head,3);
    insertAtend(&head,4);
    traverse(head);
    deleteAtend(&head);
    traverse(head);
    deleteAthead(&head);
    traverse(head);
    insertAtpos(&head,9,2);
    traverse(head);
    return;
}