#include<stdio.h>
int max(int x,int y)//形式参数
{
    int z;
    z=x>y?x:y;/*if(x>y){z=x;}else{z=y;}*/
    return z;
}
int main()
{
    int a,b,c;
    scanf("%d,%d",&a,&b);
    c=max(a,b);//实参
    printf("Max is %d\n",c);
}
