#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node* next;
};

struct node *head=NULL;

void InsertatBeg(){
    struct node *newNode;
    int val;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("\n enter Value to be inserted into the node: ");
    scanf("%d",&val);
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
    }

    void InsertatEnd(){
        struct node *newNode,*temp;
        int val;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("\n enter Value to be inserted into the node: ");
    scanf("%d",&val);
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    }

    void Insertatspec(){
            struct node *newNode,*temp;
            temp=head;
        int val,i,pos;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("\n enter Value to be inserted into the node: ");
    scanf("%d",&val);
    newNode->data=val;
    printf("\n enter the position after which you want to insert a node:");
    scanf("%d",&pos);
    
    }