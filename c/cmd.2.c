#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    if(argc!=3){
        printf("enter the arguments properly:\n");

    }
    int num1=atoi(argv[1]);
    int num2=atoi(argv[2]);

    int remainder=(num1%num2);
    printf("%d",remainder);
    return 0;

}