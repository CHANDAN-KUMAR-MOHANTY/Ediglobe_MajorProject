#include<stdio.h>
int main(){
    int n;
    printf("enter the value of n:\n");
    scanf("%d",&n);
    int a[n][n],b[n][n];
    printf("enter the values to the array:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){   
scanf("%d",&a[i][j]);
    }
}
printf("the transposed matrix for the given matix is:\n");
for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){   
        printf("%d ",a[j][i]);
    }
    printf("\n");
}
}
