#include<stdio.h>
int main(){
    int count=0;
    char a[20];
    printf("enter a string:\n");
    scanf("%s",a);
    for(int i=0;a[i]!='\0';i++){
        count++;
    }
    printf("The length of the entered string is:%d",count);
}