//Muhammed Sinan D - 347
#include <stdio.h>
int top = -1;
#define MAX 20
char stack[MAX];

void push(char value) {
    top++;
    stack[top] = value;
}

char pop() {
    char val = stack[top];
    top--;
    return val;
}

int isp(char x) {
    switch (x) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 4;
        case '^':
            return 5;
        case '#':
            return -1;
        default:
            return 0; // default case for safety
    }
}

int icp(char x) {
    switch (x) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 3;
        case '^':
            return 6;
        case '(':
            return 9;
        default:
            return 0; // default case for safety
    }
}

void eval(char value) {
    int r1, r2, res, i, re, num;
    if ((value >= 'a' && value <= 'z') || (value >= 'A' && value <= 'Z')) {
        printf("\nEnter the value of %c: ", value);
        scanf("%d", &num);
        push(num);
    } else {
        switch (value) {
            case '+':
                r1 = pop();
                r2 = pop();
                res = r2 + r1;
                push(res);
                break;
            case '-':
                r1 = pop();
                r2 = pop();
                res = r2 - r1;
                push(res);
                break;
            case '*':
                r1 = pop();
                r2 = pop();
                res = r2 * r1;
                push(res);
                break;
            case '/':
                r1 = pop();
                r2 = pop();
                res = r2 / r1;
                push(res);
                break;
            case '^':
                r1 = pop();
                r2 = pop();
                re = 1;
                for (i = 0; i < r1; i++) {
                    re = re * r2;
                }
                res = re;
                push(res);
                break;
        }
    }
}

void postfix(char infix[]) {
    int i, j = 0, k = 0;
    char e[100];
    char sym, result, value;
    stack[++top] = '#';
    for (i = 0; infix[i] != '#'; i++) {
        sym = infix[i];
        if ((sym >= 'a' && sym <= 'z') || (sym >= 'A' && sym <= 'Z')) {
            printf("%c", sym);
            e[j++] = sym;
        } else if (sym == ')') {
            while (stack[top] != '(') {
                result = pop();
                e[j++] = result;
                printf("%c", result);
            }
            pop(); // pop '('
        } else {
            while (isp(stack[top]) >= icp(sym)) {
                result = pop();
                e[j++] = result;
                printf("%c", result);
            }
            push(sym);
        }
    }
    while (stack[top] != '#') {
        result = pop();
        e[j++] = result;
        printf("%c", result);
    }
    e[j++] = '#';
    while (e[k] != '#') {
        value = e[k++];
        eval(value);
    }
}

int main(void) {
    int result;
    char expr[20];
    printf("Enter the string (end with #):\n");
    scanf("%s", expr);
    printf("The postfix expression is:\n");
    postfix(expr);
    printf("\nThe evaluated value is: ");
    result = pop();
    printf("%d\n", result);
    return 0;
}