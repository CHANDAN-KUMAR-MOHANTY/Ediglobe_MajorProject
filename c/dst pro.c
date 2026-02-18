#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for tree node
struct Node {
    char data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to create an expression tree from postfix expression  
struct Node* createExpressionTree(char postfix[]) {
    struct Node *stack[100];
    int top = -1;
    
    for (int i = 0; postfix[i]; i++) {
        struct Node* temp = newNode(postfix[i]);
        
        if (!isOperator(postfix[i])) {
            // Operand: push to stack
            stack[++top] = temp;
        } else {
            // Operator: pop two elements from stack
            if (top < 1) {  // Ensure there are at least two elements
                printf("Invalid postfix expression!\n");
                exit(1);
            }
            temp->right = stack[top--];
            temp->left = stack[top--];
            stack[++top] = temp;
        }
    }
    
    if (top != 0) {  // Stack should have exactly one element left (root)
        printf("Invalid postfix expression!\n");
        exit(1);
    }
    
    return stack[top];
}

// Function to print infix expression with proper parentheses
void infix(struct Node* root) {
    if (root) {
        if (isOperator(root->data))
            printf("(");
        infix(root->left);
        printf("%c", root->data);
        infix(root->right);
        if (isOperator(root->data))
            printf(")");
    }
}

// Function to print prefix expression
void prefix(struct Node* root) {
    if (root) {
        printf("%c", root->data);
        prefix(root->left);
        prefix(root->right);
    }
}

// Function to print postfix expression
void postfx(struct Node* root) {
    if (root) {
        postfx(root->left);
        postfx(root->right);
        printf("%c", root->data);
    }
}

// Function to free the tree memory
void freeTree(struct Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    // Example postfix expression: "ab+cde+**"
    char postfix[] = "ab+cde+**";
    
    printf("Original Postfix Expression: %s\n", postfix);
    
    // Create expression tree
    struct Node* root = createExpressionTree(postfix);
    
    // Print expressions
    printf("Infix Expression: ");
    infix(root);
    printf("\n");
    
    printf("Prefix Expression: ");
    prefix(root);
    printf("\n");
    
    printf("Postfix Expression: ");
   postfx(root);
    printf("\n");
    
    // Free allocated memory
    freeTree(root);
    
    return 0;
}

