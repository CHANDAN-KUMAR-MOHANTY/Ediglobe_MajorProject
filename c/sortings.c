#include<stdio.h>
 void InsertionSort(int a[],int n){
    int temp;
    int j;
    for(int i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
 }

 void Shellsort( int a[],int n){
    int temp;int j;
    for(int gap=n/2;gap>0;gap=gap/2){
        for(int i=gap;i<n;i++){
            temp=a[i];
            j=i;
            while(j>=0 && a[j-gap]>temp){
                a[j]=a[j-gap];
                j=j-gap;
            }
            a[j]=temp;
        }
    }
     for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }

 }

 void Qsort(int a[],int start,int end){
    if(start>end){
        int temp,pi=start;
        int i=start;
        int j=end;
        while(i<j){
            while(i<end && a[i]<=a[pi]){
                i++;
            }
            while(a[j]>a[pi]){
                j--;
            }
            if(i<j){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }

        }        
          temp=a[pi];
          a[pi]=a[j];
          a[j]=temp;
                
                Qsort(a,start,j-1);
                Qsort(a,j+1,end);
    }            
        for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }          
 }      

void Merge(int a[],){
    int b[n];
    int i=low;
    int j=mid+1,k=low;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=high){
        b[k]=a[j];
        k++;
        j++;
    }
    for(i=low;i<=high;i++){
        a[i]=b[i];
    }
}

     void Mergesort(){
        if(low<high){
            int mid=(low+high)/2;
            Mergesort(low,mid);
            Mergesort(mid+1,high);
            Merge(low,mid,high);
        }
     }             