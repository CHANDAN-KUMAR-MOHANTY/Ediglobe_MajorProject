#include<stdio.h>
int main(){
    int pegA,pegB;
    pegA=20;
    pegB=10;
    int pegC=0;
    printf("pegA=%d\n",pegA);
    printf("pegB=%d\n",pegB);

    pegC=pegA;
    pegA=pegB;
    pegB=pegC;
    
    printf("pegA=%d\n",pegA);
    printf("pegB=%d\n",pegB);

    return 0;
    
}