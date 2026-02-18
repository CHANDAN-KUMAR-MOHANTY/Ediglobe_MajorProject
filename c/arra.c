#include<stdio.h>
int main(){
int n;
printf("enter the no.of array elements");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);

}
for(int i=0;i<n;i++){
    printf("%d",arr[i]);
}
printf("\n");
int temp;
for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1-i;i++){
        temp=0;
        if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;

        }
        
    }

}
for(int i=0;i<n;i++){
    printf("%d",arr[i]);
}
return 0;

}