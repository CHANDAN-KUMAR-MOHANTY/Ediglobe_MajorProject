#include<stdio.h>

int revStr(char a[],int n){
    for(int i=0;i<=n/2;i++){
      char key=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=key;
    }
 
   return ;
 
}

int main(){
    char a[20];
    printf("enter the string:\n");
    scanf("%s",a);
    printf("the reverse of the string:\n");
    int count=0,i=0;
    while(a[i]!='\0'){
        count++;
        i++;
    }
  revStr(a,count);
  printf("%s",a);
}