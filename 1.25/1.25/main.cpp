#include<stdio.h>
int main()
{
    int q,m,o;
    float p;
    printf("please enter an integer");
    scanf("%d",&q);
    for(p=q,o=0;o<100;o++)
        p=((p+(q/p))/2);
    if(p==int(p))
    {   m=(int)p;
        printf("%d %d",q,m);}
    else
        printf("-1");
    };
