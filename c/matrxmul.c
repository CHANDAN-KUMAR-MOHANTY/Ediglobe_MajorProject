#include<stdio.h>
int main(){
    int n;
    printf("enter the value of n:\n");
    scanf("%d",&n);
    int a[n][n],b[n][n];
    int c[n][n];
    printf("enter the values of the first matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

     printf("enter the values of the second matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j]=0;
            for(int k=0;k<n;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }

     printf("the values of the multiplied matrix are:\n");
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d",c[i][j]);
        }
        printf("\n");
    }
}