#include<stdio.h>
int main(){
    char ch;
    char s[30];
    char sen[30];
    printf("enter the character\n ");
    scanf(" %c",&ch);
        printf("enter the word\n");
        scanf("%s",s);
    printf("enter the sentence\n ");
     scanf(" %[^\n]",sen);

     printf("%c\n %s\n %s",ch,s,sen);
     return 0;
}