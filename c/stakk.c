#include<stdio.h>
#include<stdlib.h>

#define max 10
int st[max];
int top = -1;

// Function prototypes
void push(int data);
void pop();
void peek();
void display();

int main() {
    int ch = 0, data;

    // Main menu loop
    while(1) {
        printf("\nEnter your choice:\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        scanf("%d", &ch);  // Fixed input issue with scanf

        switch(ch) {
            case 1:
                printf("Enter the data:\n");
                scanf("%d", &data);
                push(data);
                break;
            
            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting the program...\n");
                return 0;  // Exit the program

            default:
                printf("Enter a valid choice\n");
        }
    }
}

// Function to push data onto the stack
void push(int data) {
    if(top >= max - 1) {
        printf("The stack is full\n");
    } else {
        top++;
        st[top] = data;
        printf("%d pushed to stack\n", data);
    }
}

// Function to pop data from the stack
void pop() {
    if(top == -1) {
        printf("There are no elements to pop\n");
    } else {
        printf("%d popped from stack\n", st[top]);
        top--;
    }
}

// Function to peek at the top element of the stack
void peek() {
    if(top == -1) {
        printf("There are no elements in the stack\n");
    } else {
        printf("Top element is %d\n", st[top]);
    }
}

// Function to display the stack
void display() {
    if(top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for(int i = 0; i <= top; i++) {
            printf("%d ", st[i]);
        }
        printf("\n");
    }
}
