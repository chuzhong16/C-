#include<stdio.h>
void test(int v);
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,-1};
    int i;
    for(i=0;i<10;i++)
    {
        test(a[i]);
    }
    printf("\n");
}
void test (int v)
{
    if(v>0)
    {
        printf("%d",v);
    }
    else
    {
        printf("%d",0); 
    }
}
