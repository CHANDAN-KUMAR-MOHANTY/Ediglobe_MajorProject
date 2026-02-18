#include<stdio.h>
int main(){
    int day;
    printf("enter the number of day of the week:\n");
    scanf("%d",&day);
    switch(day){
                case 1:printf("the day is monday\n");
                break;
                case 2:printf("the day is tuesday\n");
                break;
                case 3:printf("the day is wednesday\n");
                break;
                case 4:printf("the day is thursday\n");
                break;
                case 5:printf("the day is friday\n");
                break;
                case 6:printf("the day is saturday\n");
                break;
                case 7:printf("the day is sunday\n");
                break;
                default:printf("enter the valid day\n");
    }
}