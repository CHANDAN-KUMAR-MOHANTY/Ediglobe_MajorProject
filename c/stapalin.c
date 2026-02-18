#include<stdio.h>
#include<string.h>
int ispalindrome(char str[],int size){
    for(int i=0;i<size;i++){
        if(str[i]!=str[size-1-i]){
            return 0;
        }
    }
    return 1;
}
int main(){
    char s[100];
printf("enter the string:\n");
scanf("%s",s);
int size=strlen(s);
int result=ispalindrome(s,size);
if(result==0){
    printf("not a palindrome\n");
}
else{
    printf("is a palindrome\n");
}
return 0;
}