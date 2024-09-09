#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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

// Function to delete a node at the head
void deleteAtHead(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL){
        printf("Empty list.");
    }
    
    struct Node* temp = *head;
    struct Node* prev = NULL;
    
    // If there is only one node
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = NULL;
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
// Function to insert a node at the end
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




// Function to delete a node at the end

// Function to delete a node with a given key
void deleteAtPos(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    
    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    
    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    // If key was not present in list
    if (temp == NULL) return;
    
    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
}

// Function to insert a node at a specific position
void insertAtPos(struct Node** head, int data, int pos) {
    struct Node* newNode = createNode(data);
    if (pos == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Position out of bounds.\n");
        free(newNode);
    }
}

// Function to traverse and print the linked list


int main() {
    struct Node* head = NULL;

    // Insertions
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printf("Linked List after insertions: ");
    traverse(head);

    // Deletion at head
    deleteAtHead(&head);
    printf("Linked List after deletion at head: ");
    traverse(head);

    // Deletion at end
    deleteAtEnd(&head);
    printf("Linked List after deletion at end: ");
    traverse(head);

    // Insertion at specific position
    insertAtPos(&head, 25, 1);
    printf("Linked List after insertion at position 1: ");
    traverse(head);

    return 0;
}
