// a+b*c -> ab*+

#include<stdio.h>
#define maxsize 3
char stack[100];
char exp[1000];

int top = -1;

void push(char val) {
    if (top == maxsize - 1) {
        printf("stack overflow\n");
    } else {
        top++;
        stack[top] = val;
    }
}
void pop(char val) {
    if (top < 0) {
        printf("stack empty\n");
    } else {
        val = stack[top];
        printf("%c", val);
        top--;
    }
}
void display(){
    
        for (int i = 0; i <= top; i++) {
            printf("%c", stack[i]);
        }
        printf("\n");
}
int prec(char c){
    if(c=='+'){
        return 1;
    }
    if(c=='-'){
        return 2;
    }
    if(c=='*'){
        return 3;
    }
    if(c=='/'){
        return 4;
    }
    else{
        return -1;
    }
}
void main(){
    int i;
    printf("enter ur expression:");
    scanf("%s",exp);
    
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(exp[i]);
        }
        else if(exp[i]==')'){
            while(stack[top]!='('){
                pop(exp[i]);
            }
        }
        else if(exp[i]=='+' || exp[i]=='-' ||exp[i]=='*' ||exp[i]=='/'){
            if((prec[exp[i]]) > (prec[stack[top]])){
                pop(stack[top]);
                stack[top]=exp[i];
                top++;
            }
            else{
                push(exp[i]);
                stack[top]=exp[i];
                top++;
            }
        }
        else{
            printf("%c",exp[i]);
        }
    }
    return;
}