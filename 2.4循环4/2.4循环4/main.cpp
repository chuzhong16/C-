#include<stdio.h>
int main(){
    int i=1,p=1;
    double sum=0;
    while(1.0/i>=0.000001)
    {
        sum=sum+1.0/i*p;
        i=i+2;
        p=p*(-1);
    }
    printf("%.5f",sum);
}
