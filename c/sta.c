#include<stdio.h>
#include<stdlib.h>
#define max 10
int st[max];
int top=-1;

void pop()
{
    if(top==-1){
        printf("the stack is empty\n");
    }
    else{
        printf("popped element :%d\n",st[top]);
        top--;
    }
}
void push(int data){
    if(top>=max-1){
        printf("the stack is full\n");
    }
    else{
        top++;
        st[top]=data;
        printf("successfully entered:%d\n",data);
    }
}

void display(){
    if(top==-1){
        printf("the stack is empty\n");
    }
    else{
        for(int i=0;i<=top;i++){
            printf("%d ",st[i]);
        }
    }
    printf("\n");
}

void peek(){
        if(top==-1){
        printf("the stack is empty\n");
    }
    else{
        printf("peek element is:%d \n",st[top]);
    }
}
int main(){
    int choice;
    int data;
 while(1){
    printf("enter choice from the menu:\n");
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.display\n");
    printf("4.peek\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:printf("enter the data:\n");
               scanf("%d",&data);
               push(data);
               break;

        case 2:pop();
               break;

        case 3:display();
               break;
  
        case 4:peek();
               break;

        default:printf("enter valid choice.\n");
    }
 }
}