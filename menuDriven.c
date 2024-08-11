#include <stdio.h>

int stack[3], top = -1, maxsize = 3;

void push(int val) {
    if (top == maxsize - 1) {
        printf("stack overflow\n");
    } else {
        top++;
        stack[top] = val;
    }
}

void pop() {
    int val;
    if (top < 0) {
        printf("stack empty\n");
    } else {
        val = stack[top];
        printf("popped out %d\n", val);
        top--;
    }
}

void display() {
    if (top < 0) {
        printf("stack is empty\n");
    } else {
        printf("current stack is: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, val;
    do {
        printf("choose 1- push, 2- pop, 3-print, 4-exit\n");
        scanf("%d", &n);
        switch (n) {
            case 1: {
                printf("enter the value to push: ");
                scanf("%d", &val);
                push(val);
                display();
                break;
            }
            case 2: {
                pop();
                display();
                break;
            }
            case 3: {
                display();
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

    return 0;
}
