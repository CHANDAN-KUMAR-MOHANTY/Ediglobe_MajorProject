#include<stdio.h>
#include<stdlib.h>
#define max 10
int st[max];
int top=-1;

int main(){
int ch,data;
while(1){
    printf("enter your choice:\n");
    printf("1.PUSH\n");
    printf("2.POP\n");
    printf("3.PEEK\n");
    printf("4.DISPLAY\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:printf("enter the data:\n");
                   scanf("%d",&data);
                push(data);
                break;
        
        case 2:pop();
               break;

        case 3: peek();
               break;

        case 4: display();
               break;

        default : printf("enter a valid choice\n");
    }
}

}

void push(int data){
    if(top>=max-1){
        printf("the stack is full\n");
    }
    else{
        top++;
        st[top]=data;
    }
}

void pop(){
    if(top==-1){
        printf("there are no elements\n");
    }
    else{
        top--;
    }
}

void peek(){
    if(top==-1){
        printf("there are no elements\n");
    }
    else{
        printf("%d",st[top]);
    }

}

void display(){
    for(int i=0;i<=top;i++){
        printf("%d",st[i]);
    }
}