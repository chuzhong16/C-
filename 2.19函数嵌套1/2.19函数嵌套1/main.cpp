#include<stdio.h>
long square(int p);//平方
long factorial(int q);//阶乘
int main()
{
    int i;
    long s=0;
    for (i=2; i<=3; i++)
    {
        s=s+square(i);
    }
    printf("%ld\n",s);
}
long square(int p)
{
    int k;
    long r;
    long factorial(int);
    k=p*p;
    r=factorial(k);
    return r;
}
long factorial(int q)
{
    long c=1;
    int i;
    for(i=1;i<=q;i++)
    {
        c*=i;
    }
    return c;
}
