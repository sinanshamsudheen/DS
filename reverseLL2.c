#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void traverse(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void reverseLL(struct Node** head){
    struct Node* temp=*head;
    struct Node* prev=*head;
    struct Node* ptr=*head;

    while(temp!=NULL){
        ptr=ptr->next;
        if(ptr->data<prev->data){
            swap(&ptr->data,&prev->data);
        }
        prev=ptr;
        temp=temp->next;
    }
}
void main(){
    struct Node* head=NULL;
    insertAtHead(&head,1);
    insertAtHead(&head,2);
    insertAtHead(&head,3);
    insertAtHead(&head,4);
    printf("Original List: ");
    traverse(head);
    reverseLL(&head);
    printf("Reversed List: ");
    traverse(head);
    return;
    return;
}