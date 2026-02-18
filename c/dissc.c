#include<stdio.h>
#include<math.h>
int main(){
    int A,B,C,dis;
    printf("enter the values of A B C:\n");
    scanf("%d %d %d",&A,&B,&C);
    dis=pow(B,2)-4*A*C;
    if(dis<0){
        printf("imaginary roots");
    }
    else if (dis==0)
    {
        printf("real and equal roots");
        
    }
    else{
        printf("real and distinct roots");
    }   
}