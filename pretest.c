#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* createnode(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void insertAtend(struct node** head,int data){
    struct node* newnode=createnode(data);
    if(*head==NULL){
        *head=newnode;
        return;
    }
    struct node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
void deleteAtNode(struct node** head,int key){
    struct node* temp=*head;
    while(temp!=NULL && temp->data!=key){
        temp=temp->next;
    }
    temp=temp->next->next;
    free(temp->next);

}

// Function to insert a node at the end
void traverse(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
   
void main(){
    int a;
    struct node* head=NULL;
    printf("enter the list: ");
    for(int i=0;i<3;i++){
        scanf("%d",&a);
        insertAtend(&head,a);
    }
    traverse(head);
    deleteAtNode(&head,2);
    traverse(head);
    return;
}