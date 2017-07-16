#include<stdio.h>
int main(){
    int i,j,m;
    for(i=2;i<=1000;i++) //寻找1000以内的完数
    {
        m=0;   //补充
        for(j=1;j<=i-1;j++) //从1开始求i的因子
            if(i%j==0)m=m+j;    //寻找i的因子，并把因子之和加起来
        if(m==i)
            printf("%d是个完数\n",i);}
    return 0;}
