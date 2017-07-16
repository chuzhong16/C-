#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    float d;
    d=1.0*a/b;
    printf("%.*lf",c,d);
}
