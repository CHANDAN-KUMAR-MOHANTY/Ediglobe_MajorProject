#include<stdio.h>
int main(){
     int n;
    printf("enter the value of n:\n");
    scanf("%d",&n);
    int a[n][n];
    printf("enter the value into the 1st matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
     scanf("%d",&a[i][j]);
        }
    }
 printf("enter the values into the 2nd matrix:\n");
int b[n][n];
 for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
     b[j][i]=a[i][j];
        }
 }

  for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
     printf("%d ",b[i][j]);
        }
        printf("\n");
    }
}