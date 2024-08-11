#include<stdio.h>

void swap1(int a,int b){
    int temp=a;
    a=b;
    b=temp;
    printf("Result: %d, %d\n",a,b);
}






void swap2(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void main(){
    int x=9,y=2;
    int c=NULL;
    printf("Result: %d\n",&c);

    swap2(&x,&y);
    // printf("Result: %d, %d",x,y);


    // printf("Result: %d\n",x);

    int *ptr=&x;
    printf("Result: %d\n",ptr);



    return;
}