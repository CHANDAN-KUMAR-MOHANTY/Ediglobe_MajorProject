#include<stdio.h>
int main(){
    int n;
    printf("enter the value of n:\n");
    scanf("%d",&n);
    int a[n];
    printf("enter the values into the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=a[i];
            int j=i;
            while(j>=gap&&a[j-gap]>temp){
                a[j]=a[j-gap];
                j-=gap;
            }
            a[j]=temp;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

}