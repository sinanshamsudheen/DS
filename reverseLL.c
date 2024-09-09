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
int stack[100];
int top=-1;
void push(int val){
    if(top>=69){
        printf("stack full");
    }
    else{
        top++;
        stack[top]=val;
    }
}
int pop(){
    if(top<0){
        printf("stack empty");
        return -1;
    }
    else{
        int val=stack[top];
        top--;
        return val;
    }
}

void reverseLL(struct Node** head) {
    struct Node* temp = *head;
    while(temp!=NULL){
        push(temp->data);
        temp=temp->next;
    }
    temp=*head;
    while(temp!=NULL){
        temp->data=pop();
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
}