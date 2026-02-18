#include<stdio.h>
int main(){
    int count=0;
    char a[20];
    printf("enter a string:\n");
    scanf("%s",a);
    for(int i=0;a[i]!='\0';i++){
        count++;
    }
    printf("The length of the entered string is:%d\n",count);

    char b[20];
    for(int i=0;i<count;i++){
        b[i]=a[count-i-1];
    }
    b[count]='\0';
    
        printf("%s\n",b);
    
}