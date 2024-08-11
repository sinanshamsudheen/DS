#include <stdio.h>
#define SIZE 100

int front = -1;
int rear = -1;
int Q[SIZE];
char res[SI]

void enqueue(int item) {
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = rear + 1;
        Q[rear] = item;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        int item = Q[front];
        printf("Removed %d\n", item);
        front = front + 1;
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Current queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", Q[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(4);
    display();
    enqueue(3);
    display();
    enqueue(7);
    display();
    dequeue();
    display();
    return 0;
}
