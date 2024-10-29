#include <stdio.h>
#include <stdlib.h>

#define N 5
int front = 0, rear = 0;
int Q[N];
void enqueue(int val)
{
    if (((rear + 1) % N) == front)
    {
        printf("Queue is Full\n");
    }
    else
    {
        Q[rear] = val;
        rear = (rear + 1) % N;
    }
    printf("Displaying Queue:\n");
    for (int i = 0; i < rear; i++)
    {
        printf("%d,", Q[i]);
    }
}
void dequeue()
{
    if (rear == front)
    {
        printf("Stack Empty!\n");
    }
    else
    {
        printf("Dequeued Element:%d\n", Q[front]);
        front = (front + 1) % N;
    }
}
void show()
{
    int i;
    if (rear == -1 && front == -1)
    {
        printf("QUEUE Empty!\n");
    }
    printf("The Queue:\n");
    while (i != rear)
    {
        printf("%d\t", Q[i]);
        i = (i + 1) % N;
    }
}
void main()
{
    int ch;
    while (1)
    {
        printf("\nQueue Operations:\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int val;
            printf("Enter value to enqueue:");
            scanf("%d", &val);
            enqueue(val);
            show();
            break;
        }

        case 2:
            dequeue();
            show();
            break;
        case 3:
            show();
            break;
        case 4:
            printf("Thank You!");
            exit(0);
        default:
            printf("Invalid Choice");
        }
    }
}