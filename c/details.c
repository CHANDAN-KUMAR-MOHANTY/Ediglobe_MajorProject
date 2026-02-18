#include<stdio.h>
int main(){
    char name[30];
    int id;
    char gender;
    char branch[5];
    long int phno=1112223333;
    int Icgpa;

 printf("enter your name:\n");
 scanf("%s",name);
 printf("enter last five digits of your id:\n");
 scanf("%d",&id);
 printf("enter your gender:\n");
 scanf(" %c",&gender);
 printf("enter your branch: \n");
 scanf("%s",branch);
 printf("enter inter cgpa:\n");
 scanf("%d",&Icgpa);


 printf("%s\n",name);
 
 printf("%d\n",id);
 
 printf("%c\n",gender);
 
 printf("%s\n",branch);
 
 printf("%d\n",Icgpa);
}