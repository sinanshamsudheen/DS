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
void traverse(struct Node* head){
    struct Node* temp=head;
    printf("final list: ");
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void palindromeChk(struct Node** head){
    struct Node* temp=*head;
    int a1[100];
    int rev[100];
    int i=0;
    int j;
    while(temp!=NULL){
        a1[i]=temp->data;
        temp=temp->next;
        i++;
    }
    j=i-1;
    for(int k=0;k<i;k++,j--){
        rev[k]=a1[j];
    }
    int flag=0;
    for(int k=0;k<i;k++){
        if(a1[k]!=rev[k]){
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("Not pal");
    }
    else{
        printf("palindrome");
    }
}

//function to insert a node in the end

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
void ArrangeOddEven(struct Node** head,struct Node** head2){
    struct Node* temp=*head;
    while(temp!=NULL){
        if((temp->data)%2==0){
            insertAtEnd(head2,temp->data);
        }
        temp=temp->next;
    }
    temp=*head;
    while(temp!=NULL){
        if((temp->data)%2!=0){
            insertAtEnd(head2,temp->data);
        }
        temp=temp->next;
    }
}
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void LinkedSum(struct Node** head,struct Node** head2,struct Node** sumL){
    struct Node* temp=*head;
    struct Node* temp2=*head2;
    int i=0, j=0, sum=0;
    int a1[100],a2[100];

    while(temp!=NULL){
        a1[i]=temp->data;
        i++;
        temp=temp->next;
    }
    while(temp2!=NULL){
        a2[j]=temp2->data;
        j++;
        temp2=temp2->next;
    }
     while (i > 0 && j > 0) {
        sum = a1[i-1] + a2[j-1];
        insertAtBeginning(sumL, sum);
        i--;
        j--;
    }

    while (i > 0) {
        insertAtBeginning(sumL, a1[i-1]);
        i--;
    }

    while (j > 0) {
        insertAtBeginning(sumL, a2[j-1]);
        j--;
    }
}

void main(){
    struct Node* head=NULL;
    struct Node* head2=NULL;
    struct Node* sumhead=NULL;
    int n,a,m;
    printf("enter the limit for first:");
    scanf("%d",&n);
        printf("enter the values: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        insertAtEnd(&head,a);
    }
    printf("enter the limit for second:");
    scanf("%d",&m);
        printf("enter the values: ");

    for(int i=0;i<m;i++){
        scanf("%d",&a);
        insertAtEnd(&head2,a);
    }
    LinkedSum(&head,&head2,&sumhead);
    traverse(sumhead);
    // traverse(head);
    // traverse(head2);
    // palindromeChk(&head);
    // sumOfElements(&head);
    return;
}
//o/p,
// enter the limit:3
// enter the value u wanna insert next: 1 
// enter the value u wanna insert next: 2
// enter the value u wanna insert next: 1
// final list: 1 ->2 ->1 ->NULL
// palindrome