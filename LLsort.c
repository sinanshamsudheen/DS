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
    return newNodeoooo;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(struct Node** head){
    int len=0,arr[100];
    struct Node* temp=*head;
    while(temp!=NULL){
        arr[len]=temp->data;
        len++;
        temp=temp->next;
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    struct Node* head2=NULL;
    for(int i=0;i<len;i++){
        insertAtEnd(&head2,arr[i]);
    }
    printf("sorted list: ");
    traverse(head2);
}
void main(){
    struct Node* head=NULL;
    int n,a;
    printf("enter the limit: ");
    scanf("%d",&n);
    printf("enter the list: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        insertAtEnd(&head,a);
    }
    traverse(head);
    sortList(&head);
    return;
}
// op,
// enter the limit: 3
// enter the list: 5 8 2
// 5 -> 8 -> 2 -> NULL
// sorted list: 2 -> 5 -> 8 -> NULL