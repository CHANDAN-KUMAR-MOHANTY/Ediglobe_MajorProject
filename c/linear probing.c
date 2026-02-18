#include<stdio.h>
#include<stdlib.h>
#define max 10
int hashT[max];

int hash(int key){
    return key%max;
}

void Insert(int key){
    int Index=hash(key);
    while(hashT[Index]!=-1){
        Index=(Index+1)%max;
    }
    hashT[Index]=key;
}

void Search(int key){
    int Index=hash(key);
    while(Index<max){
        if(hashT[Index]==key){
            printf("Key is found at %d\n",Index);
            return ;
        }
        Index=(Index+1)%max;
        
    }
    printf("key is not found\n");
    return ;
}

void display(){
 printf("The Hashtable consists of:\n");
 for(int i=0;i<max;i++){
    printf(" Index: %d  ",i);
    if(hashT[i]==-1){
        printf("Empty\n");
    }
    else{
        printf("%d\n",hashT[i]);
    }
 }
}

int main(){
    for(int i=0;i<max;i++){
        hashT[i]=-1;
    }
    int ch, val;
    while(1){
        printf("enter your choice:\n");
        printf("1.Insert\n");
        printf("2.search\n");
        printf("3.display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("enter the value to insert: \n");
                     scanf("%d",&val);
                     Insert(val);
                     break;

            case 2: printf("enter the value to search: \n");
                    scanf("%d",&val);
                    Search(val);
                    break;

            case 3: display();
                    break;

            default: printf("enter the proper choice\n");
        }
    }

}