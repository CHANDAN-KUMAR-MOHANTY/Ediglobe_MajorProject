#include<stdio.h>
int main(){
    int n;
    printf("enter the value of n:\n");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements:\n");
    for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
    int key;int found=0;
    printf("enter the key element of the array:\n");
    scanf("%d",&key);
    for(int i=0;i<n;i++){
        if(a[i]==key){
            printf("the key is found at : %d",i);
            found=1;
            break;
        }
    }
    if(!found){
        printf("the key element is not found in the array\n");
    }
}