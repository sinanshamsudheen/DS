#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* CreateNode(int data){
    struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode->data=data;
    NewNode->next=NULL;
    return NewNode;
}

void insertAtbegin(struct Node **head,int data){
    struct Node* NewNode=CreateNode(data);
    NewNode->data=data;
    NewNode->next=*head;
    *head=NewNode;
}

void insertAtend(struct Node **head,int data){
    struct Node* NewNode=CreateNode(data);
    if(*head==NULL){
        *head=NewNode;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=NewNode;
}

//to delete a node which contains a given key value
void deleteNode(struct Node **head,int key){
        struct Node* temp=*head;
        struct Node* prev=NULL;
    //if key is in the head node itself
    if(temp!=NULL && *head==key){
        *head=temp->next;
        free(temp);
    }

    while(temp!=NULL && temp->data!=key){
    prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("key not found!");
    }
    prev->next=temp->next;
    free(temp);
}

void deleteAtNode(struct Node** head,int keyData){
    struct Node* temp=*head;
    struct Node* prev=*head;
    if(temp!=NULL && temp->data==keyData){
        *head=temp->next;
        free(temp);
    }
    while(temp!=NULL && temp->data!=keyData){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("data not found!");
        return;
    }
   prev->next=temp->next;
   free(temp);
}
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void main(){
    struct Node* head=NULL;
    insertAtbegin(&head,10);
    insertAtbegin(&head,20);
    insertAtbegin(&head,30);
    insertAtend(&head,50);
    traverse(head);
    deleteNode(&head,20);
    traverse(head);
    // struct node n1,n2,n3;
    // struct node *p;
    // p=&n1;
    // n1.next=&n2;
    // n2.next=&n3;
    // n3.next=NULL;

    // n1.data=1;
    // n2.data=3;
    // n3.data=2;

    // printf("reading the list..");
    // while(p!=NULL){
    //     printf("%d ",data);
    //     p++;
    // }
    // printf("deleting..");

    return;
}