#include<stdio.h>
void linearsearch(int a[],int n,int key){
   int found=0;int i;
    for( i=0;i<n;i++){
       
        if(a[i]==key){
           
            found=1;
            break;
        }
    }
    if(found!=0){
         printf("the key is found at:%d",i);
    }
    else
    {
        printf("the key element is not found in the array");
    }
}
int main(){
    int n;
    printf("enter the value of n: \n");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements of the array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int key;
    printf("enter key element: \n");
    scanf("%d",&key);
    linearsearch(a,n,key);
    return 0;

}