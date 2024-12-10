#include <stdio.h>
#include <stdlib.h>

void display(int arr[])
{
    for (int i=0;i<size;i++)
    {
        printf("%d,",arr[i]);
    }
    printf("\n");
}
void main()
{
    printf("Enter number of elements:");
    scanf("%d",&size);
    int arr[size];
    int temp[size];//used for merging
    printf("Enter the elements\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Before sorting:\n");
    display(arr);
    sort(arr,temp,0,size-1);
    printf("After Sorting:\n");
    display(arr);
}