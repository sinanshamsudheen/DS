#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) 
{
    if (top == MAX - 1) 
    {
        printf("Stack Overflow\n");
    } else 
    {
        stack[++top] = item;
    }
}

char pop() 
{
    if (top == -1) 
    {
        printf("Stack Underflow\n");
        return '#'; // Return least precedence operator if stack underflows
    } else 
    {
        return stack[top--];
    }
}

int isOperator(char ch) 
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int isp(char op) 
{
    switch (op) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 4;
        case '^':
            return 5;
        case '(':
            return 0;
        case '#':
            return -1;
        default:
            return 0;
    }
}

int icp(char op) 
{
    switch (op) {
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
        case '#':
            return -1;
        default:
            return 0;
    }
}
void infixToPostfix(char* ex,char* postfix){
    int k=0;
    push('#');
    for(int i=0;ex[i]!='\0';i++){
        char sym=ex[i];
        if(ex[i] >= 'A' && ex[i] <= 'Z' || ex[i] >= 'a' && ex[i] <= 'z'){
            postfix[k++]=sym;
        }
        else if(sym=='('){
            push(sym);
        }
        else if(sym==')'){
            while(stack[top]!='(' && top != -1){
                postfix[k++]=pop();
            }
            pop();
        }
        else if(isOperator(sym)){
            if(isp(stack[top])>=icp(sym) && top!=-1){
                postfix[k++]=pop();
            }
            else{
                push(sym);
            }
        }
       
    }
   
    while (top != -1 && stack[top] != '#') {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int postfixEval(char* postfix){
    int val[MAX],valTop=-1,value;
    for(int i=0;postfix[i]!='\0';i++){
        char sym=postfix[i];
        if(sym >= 'A' && sym <= 'Z' || sym >= 'a' && sym <= 'z'){
            printf("enter a value for %c",sym);
            scanf("%d",&value);
            valTop++;
            val[valTop]=value;
        }
        else if(isOperator(sym)){
            int op2=val[valTop--];
            int op1=val[valTop--];
            int result;
            switch (sym)
            {
            case '+':
                result=op1+op2;
                break;
            case '-':
                result=op1-op2;
                break;
            case '*':
                    result=op1*op2;
                    break;
                case '/':
                    if (op2!=0)
                    {
                        result=op1/op2;
                    }
                    else{printf("Division by Zero error\n");}
                    break;
                case '^':
                    result=pow(op1,op2);
                    break;
            default:
                break;
            }
            valTop++;
            val[valTop]=result;
        }

    }
    return val[valTop];
}
int main(){
    char expr[MAX];
    char postfix[MAX];

    printf("Enter ur expression: ");
    scanf("%s",expr);
    infixToPostfix(expr,postfix);
    printf("Postfix expression: %s",postfix);
    int res = postfixEval(postfix);
    printf("Postfix evaluation: %d",res);
    return 0;
}