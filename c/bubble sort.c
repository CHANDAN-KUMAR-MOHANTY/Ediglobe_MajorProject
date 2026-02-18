#include<stdio.h>
void bubblesort(int a[],int n){
    int temp=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
    int main(){
        int n;
        printf("enter the size of the array: \n");
        scanf("%d",&n);
        int a[n];
        printf("enter the elements into the array: \n");
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        bubblesort(a,n);
       for(int i=0;i<n;i++){
        printf("%d ",a[i]);
       }
       return 0;
    }
