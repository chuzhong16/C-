#include<stdio.h>
int main()
{
    int n,i;
    float a=0;
    scanf("%d",&i);
    for(n=1;n<=i;n++)
    {
        a=a+1.0/n;
    }
    printf("%.3lf",a);
    return 0;
}
