#include<stdio.h>
void sort(int a[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main(){
    int n;
    printf("enter the size of the array:\n");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements into the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,n);
    int key;
    printf("enter the key element to find:\n");
    scanf("%d",&key);
    int found=0,first=0,last=n-1;
    int mid;
    while(first<=last){
        mid=(first+last)/2;
        if(a[mid]==key){
            found=1;
            printf("the key is found at : %d\n",mid);
            break;
        }
        else if (a[mid]>key)
        {
            last=mid-1;
        }
        else{
            first=mid+1;
        }
        
    }
    if(!found){
        printf("the entered element is not found in the array\n");
    }
}