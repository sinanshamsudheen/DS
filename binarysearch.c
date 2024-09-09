#include<stdio.h>
    int arr[]={1,2,3,4,5};

void binarySearch(int key){
    int flag=0;
    int low=0,high=5;
    while(low<=high){
        int mid=(low+high)/2;
        if(key==arr[mid]){
            flag=1;
            break;
        }
        else if(key<=arr[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(flag){
        printf("found");
    }else{
        printf("not found");
    }
}
void main(){
    binarySearch(3);

    return;
}