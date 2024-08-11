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

// Function to delete a node with a given key
void deleteNode(struct Node** head, int key) {
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

// Function to search for a node with a given key
int search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return 1; // Key found
        }
        current = current->next;
    }
    return 0; // Key not found
}





// Function to traverse and print the linked list
void traverse(struct Node* head) {

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}






// Driver Code
int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 8);
    traverse(head);
    
    int key = 10;
    if (search(head, key)) {
        printf("Element %d is found in the linked list.\n", key);
    } else {
        printf("Element %d is not found in the linked list.\n", key);
    }
    
    // // Insertion
    // insertAtEnd(&head, 10);
    // insertAtEnd(&head, 20);
    // insertAtEnd(&head, 30);
    // printf("Linked List after insertions: ");
    // traverse(head);
    
    // // Deletion
    // deleteNode(&head, 20);
    // printf("Linked List after deletion of 20: ");
    // traverse(head);
    
    // // Searching
    
    // // Traversal
    // printf("Final Linked List: ");
    
    return 0;
}
