#include<stdio.h>
int main(){
    int n;
    printf("enter the value of n:\n");
    scanf("%d",&n);
    int a[n][n];
    printf("enter the values into the array:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("the upper triangular matrix for the given matrix is:\n");
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>=i){
            printf("%d ",a[i][j]);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}