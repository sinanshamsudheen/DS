#include<stdio.h>
#include<stdlib.h>
int DQ[5];
int front=-1,rear=-1,size=5;


void insertFront(int val){
    if(front==0 && rear==size-1){
        printf("Dq is full.");
    }
    else if(front==-1 && rear==-1){
        front=0;
        rear=0;
        DQ[front]=val;
    }
    else if(front>0){
        front--;
        DQ[front]=val;
    }
    else{
        for(int i=rear;i>=0;i--){
            DQ[i+1]=DQ[i];
        }
        DQ[front]=val;
        rear=rear+1;
    }
}
void deleteFront(){
    if(front==-1 && rear==-1){
        printf("empty.");
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        printf("deleted %d",DQ[front]);
        front++;
    }
}
void insertRear(int val){
    if(front==0 && rear==size-1){
        printf("full");
    }
    else if(front==-1 && rear==-1){
        front=0;
        rear=0;
        DQ[rear]=val;
    }
    else if(rear<size-1){
        rear++;
        DQ[rear]=val;
    }
    else{
        for(int i=front;i<=rear;i++){
            DQ[i-1]=DQ[i];
        }
        DQ[rear]=val;
        front--;
    }
}
void deleteRear(){
    if(front==rear==-1){
        printf("empty");
    }
    else if(front==rear){
        printf("deleted element %d",DQ[front]);
        front=-1;
        rear=-1;
    }
    else{
        printf("deleted element %d",DQ[rear]);
        rear--;
    }
}
void display(){
    if(front==-1 && rear==-1){
        printf("empty");
    }else{
        printf("current deque: ");
        for(int i=front;i<=rear;i++){
            printf("%d\t",DQ[i]);
        }
    }
    printf("\n");
}
void main(){
    int n,val;
    do{ 
        printf("choose 1-insertFront 2-insertRear 3- deleteFront 4- deleteRear 0- exit\n");
        scanf("%d",&n);
        
        switch(n){
            case 1:{
                printf("enter val to insert: ");
                scanf("%d",&val);
                insertFront(val);
                display();
                break;
            }
            case 2:{
                printf("enter val to insert: ");
                scanf("%d",&val);
                insertRear(val);
                display();
                break;
            }
            case 3:{
                deleteFront();
                display();
                break;
            }
            case 4:{
                deleteRear();
                display();
                break;
            }
            case 0: break;
        }

    }while(n!=0);
    
    return;
}