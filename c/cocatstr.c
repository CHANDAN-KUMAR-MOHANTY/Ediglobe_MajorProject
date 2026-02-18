#include<stdio.h>
int main(){
    int i=0,j=0;
    char a[100];
    printf("enter the 1st string value:\n");
    scanf("%s",a);
      char b[100];
    printf("enter the 2nd string value:\n");
    scanf("%s",b);
      while(a[i]!='\0'){
        i++;
      }
while(b[j]!='\0'){
    a[i]=b[j];
    i++;
    j++;
}
a[i]='\0';

printf("%s",a);
}