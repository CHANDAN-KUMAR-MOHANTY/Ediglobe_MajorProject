#include <stdio.h>
int main()
{
    int n;
    printf("enter the value of n:\n");
    scanf("%d",&n);
    int arr[n] ;
    printf("enter the values into the array:\n");
 for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
 }
    for (int i = 0; i < n; i++) {
        switch (arr[i]) {
            // range 1 to 6
        case 1 ... 6:
            printf("%d in range 1 to 6\n", arr[i]);
            break;
            // range 19 to 20
        case 19 ... 20:
            printf("%d in range 19 to 20\n", arr[i]);
            break;
        default:
            printf("%d not in range\n", arr[i]);
            break;
        }
    }
}