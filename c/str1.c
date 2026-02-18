#include<stdio.h>
int main(){
    char ch;
    char s[15];
    char sen[100];
    printf("enter the character:\n");
    scanf("%c",&ch);
    printf("enter the string:\n");
    scanf(" %s",s);
    printf("enter the sentence:\n");
    scanf(" %[^\n]",sen);
    printf("%c\n",ch);
printf("%s\n",s);
printf("%s\n",sen);


    return 0;
}