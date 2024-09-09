#include<stdio.h>
int n=6,m=6;

void sparseConv(int a[n][m],int s[100][3]){
    int k=1;
    s[0][0]=n;
    s[0][1]=m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=0){
                s[k][0]=i;
                s[k][1]=j;
                s[k][2]=a[i][j];
                k++;
            }
        }
                s[0][2]=k-1;
    }
}
void transpose(int t[100][3],int s[100][3]){
    t[0][0]=s[0][1];
    t[0][1]=s[0][0];
    t[0][2]=s[0][2];
    m=s[0][1],n=s[0][2];
    int k=1;
    for(int i=0;i<m;i++){
        for(int j=1;j<=n;j++){
            if(s[j][1]==i){
                t[k][0]=s[j][1];
                t[k][1]=s[j][0];
                t[k][2]=s[j][2];
                k++;
            }
        }
    }
}
// 15 0 0 22 0 -15 0 11 3 0 0 0 0 0 0 -6 0 0 0 0 0 0 0 0 91 0 0 0 0 0 0 0 28 0 0 0
void main(){
    int s[100][3],t[100][3],a[6][6];
    printf("pls enter the 6x6 array:\n");
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            scanf("%d",&a[i][j]);
        }
    }
    sparseConv(a,s);
    printf("The SPARSE matrix is:\nrow| col|value\n");
    for(int i=0;i<=s[0][2];i++){
        for(int j=0;j<3;j++){
            if(j==2){
                printf("%d   ",s[i][j]);
            }else{
                printf("%d  | ",s[i][j]);
            }
        }
        printf("\n");
    }

    transpose(t,s);
    printf("The TRANSPOSE matrix is:\nrow| col|value\n");
    for(int i=0;i<=s[0][2];i++){
        for(int j=0;j<3;j++){
            if(j==2){
                printf("%d   ",t[i][j]);
            }else{
                printf("%d  | ",t[i][j]);
            }
        }
        printf("\n");
    }
    return;
}