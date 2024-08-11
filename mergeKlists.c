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
void mergeSortedList(struct Node** head,struct Node** head2){
    struct Node* temp=*head;
    struct Node* temp2=*head2;
    // struct Node* temp3=*head3;
    while(temp!=NULL){
        insertAtEnd(head2,temp->data);
        temp=temp->next;
    }
}
void main(){
    struct Node* head=NULL;
    struct Node* headMerge=NULL;
    printf("enter the number of lists u wanna merge(K): ");
    int n,a,k;
    scanf("%d",&k);

    for(int i=0;i<k;i++){
        head=NULL;
        printf("enter the length of %dth list: ",i+1);
        scanf("%d",&n);

            printf("enter the list %d: ",i+1);
            for(int i=0;i<n;i++){
                scanf("%d",&a);
                insertAtEnd(&head,a);
            }
        mergeSortedList(&head,&headMerge);
        traverse(headMerge);
    }
    return;
}
