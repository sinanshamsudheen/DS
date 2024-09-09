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

// void deleteAtEnd(struct Node** head) {
//     if (*head == NULL){
//         printf("Empty list.");
//     }
    
//     struct Node* temp = *head;
//     struct Node* prev = NULL;
    
//     // If there is only one node
//     if (temp->next == NULL) {
//         free(temp);
//         *head = NULL;
//         return;
//     }
    
//     while (temp->next != NULL) {
//         prev = temp;
//         temp = temp->next;
//     }
    
//     prev->next = NULL;
//     free(temp);
// }

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
    int n, val;
    do {
        printf("choose 1- enqueue, 2- dequeue, 3-print, 4-exit\n");
        scanf("%d", &n);
        switch (n) {
            case 1: {
                printf("enter the value to push: ");
                scanf("%d", &val);
                insertAtBeginning(&head,val);
                traverse(head);
                break;
            }
            case 2: {
                deleteAtHead(&head);
                traverse(head);
                break;
            }
            case 3: {
                traverse(head);
                break;
            }
            case 4: {
                break;
            }
            default: {
                printf("wrong choice\n");
            }
        }
    } while (n != 4);

    return;
}

