#include<stdio.h>
#include<stdlib.h>

struct student
{
    int roll;
    float a,b,c;
    char name[30];
};

int main(){
    struct student *s;
    int n;
    int *total;
    int avg;
    int highm=0,highIn=-1;
    printf("enter the value of n:\n");
     scanf("%d",&n);
    s=(struct student *)malloc(n*sizeof(struct student));
    total=(int *)calloc(n,sizeof(int));

    for(int i=0;i<n;i++){
        printf("enter the values of the student-%d\n",i+1);
        printf("roll no:\n");
        scanf("%d",&(s+i)->roll);
        printf("enter the marks of the student in the three subjects:\n");
        scanf("%f %f %f",&(s+i)->a,&(s+i)->b,&(s+i)->c);
        printf("enter the name of the student:\n");
        scanf("%s",(s+i)->name);
        
        total[i]=(s+i)->a+(s+i)->b+(s+i)->c;
        if(total[i]>highm){
            highm=total[i];
            highIn=i;
        }
        
    }
    for(int i=0;i<n;i++){
        printf("The total marks of the student-%d : %d\n",i+1,total[i]);
        printf("the avg of the student-%d : %.2f\n",i+1,(total[i]/3.0));
    }
    printf("the highest marks are of the student-%d that is %d",highIn,highm);
    free(s);
    free(total);
    
    return 0;
}








