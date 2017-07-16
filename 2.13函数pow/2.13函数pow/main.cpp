#include<stdio.h>
int power(int a,int b);
int main()
{
    //int power(int a,int b);
    int x,y,z;
    scanf("%d%d",&x,&y);
    z=power(x,y);
    printf("%d的%d次方为%d\n",x,y,z);
      }
int power(int a,int b)
{
    int c;
    c=1;
    
    for(int i=0;i<b;i++)
    {
        c=c*a;
    }
    return(c);
    
}
