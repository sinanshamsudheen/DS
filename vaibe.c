#include <stdio.h>
int arr[10][10],dense[10][10],trans[10][10];
int row,cols,i,j,k;
void sparseDense(int arr[10][10])
{
    dense[0][0]=row;        //row count
    dense[0][1]=cols;       //column count
    k=1;
    for(i=0;i<row;i++)
    {
        for (j=0;j<cols;j++)
        {
            if(arr[i][j]!=0)
            {
                
                dense[k][0]=i;        //row 
                dense[k][1]=j;        //column
                dense[k][2]=arr[i][j];       //adding the element to dense
                k++;
            }
        }
    }
    dense[0][2]=k-1; 
    
}
void Transpose()
{
    trans[0][0]=dense[0][1]; //interchange rows and columns
    trans[0][1]=dense[0][0];
    trans[0][2]=dense[0][2];
    
    k=1;
    for (i=0;i<dense[0][1];i++)
    {
        for (j=1;j<=dense[0][2];j++)
        {
            if (dense[j][1]==i)
            {
                trans[k][0]=dense[j][1];
                trans[k][1]=dense[j][0];
                trans[k][2]=dense[j][2];
                k++;
            }
        }
    }
}
void main()
{
    printf("Enter no of rows and columns:");
    scanf("%d%d",&row,&cols);
    printf("Enter the Elements with more ZEROS:");
    for(i=0;i<row;i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("Sparse[%d][%d]:",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    sparseDense(arr);
    printf("The SPARSE matrix is:\nrow| col|value\n");
    for(int i=0;i<=dense[0][2];i++){
        for(int j=0;j<3;j++){
            if(j==2)
            {
                printf("%d   ",dense[i][j]);
            }
            else
            {
                printf("%d  | ",dense[i][j]);
            }
        }
        printf("\n");
    }
    Transpose();
    printf("The TRANSPOSE matrix is:\nrow| col|value\n");
    for(int i=0;i<=dense[0][2];i++){
        for(int j=0;j<3;j++){
            if(j==2)
            {
                printf("%d   ",trans[i][j]);
            }
            else
            {
                printf("%d  | ",trans[i][j]);
            }
        }
        printf("\n");
    }
}