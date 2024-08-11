#include<stdio.h>
#include<stdlib.h>

//Daddy Node
struct Node{
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));//to create a node 
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    newNode->next = *head;
    *head = newNode;
}

//to print or display the list
void traverse(struct Node* head) {

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//to search for an element inside the list
int search(struct Node* head, int key) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            return 1; // Key found
        }
        temp = temp->next;
    }
    return 0; // Key not found
}
void main(){
    struct Node* head = NULL;
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 8);
    traverse(head);
    
    int key = 8;
    if (search(head, key)) {
        printf("Element %d is found in the linked list.\n", key);
    } else {
        printf("Element %d is not found in the linked list.\n", key);
    }
    return;
}