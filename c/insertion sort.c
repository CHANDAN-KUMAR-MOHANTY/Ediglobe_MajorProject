#include<stdio.h>
int main(){
    int n;
    printf("enter the value of n:\n");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements into the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int key;
    for(int i=1;i<n;i++){
        key=a[i];
    int j=i-1;
        while(j>=0&& a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }

printf("the sorted array is:\n");
     for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
}