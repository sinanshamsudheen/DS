// a+b*c -> ab*+
#include<stdio.h>

char stack[100];
char expression[1000];

int top = 0;

void push(char val) {
    if (top == sizeof(expression)) {
        printf("stack overflow\n");
    } else {
        stack[top] = val;
        top++;
    }
}
void pop() {
        char val;
    if (top < 0) {
        printf("stack empty\n");
    } else {
        val = stack[top];
        printf("%c", val);
        top--;
    }
}

int prec(char c){
    if(c=='+' || c=='-'){
        return 1;
    }
   
    if(c=='*' || c=='/'){
        return 3;
    }
    
    else{
        return -1;
    }
}
void display() {
    if (top < 0) {
        printf("stack is empty\n");
    } else {
        for (int i = 0; i <= top; i++) {
            printf("%c", stack[i]);
        }
        printf("\n");
    }
}
//(a-b/c)*(a/k-l)
void main(){
    int i;
    printf("enter ur expression:");
    scanf("%s",expression);
    
    for(i=0;expression[i]!='\0';i++){
        if(expression[i]=='('){
            push(expression[i]);
        }
        else if(expression[i]==')'){
            while(stack[top]!='('){
                pop(expression[i]);
            }
        }
        else if(expression[i]=='+' || expression[i]=='-' ||expression[i]=='*' ||expression[i]=='/'){
            if((prec(expression[i])) < (prec(stack[top]))){
                pop(stack[top]);
                stack[top]=expression[i];
                top++;
            }
            else{
                push(expression[i]);
                stack[top]=expression[i];
                top++;
            }
        }
        else if(expression[i]>='a' && expression[i]<='z' || expression[i]>='A' && expression[i]<='Z' ){
            printf("%c",expression[i]);
        }
    }
    display();
    return;
}