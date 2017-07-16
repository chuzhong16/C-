#include<stdio.h>
int main()
{
   ;
    float a,b,c,i;
    a=i=1.0;
    c=-1.0;
    for(b=3;b<=1000000;b=b+2)
    {
        a=a-i/b;
        i=i*c;
    }
    printf("%f",a);
}
