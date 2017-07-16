#include<stdio.h>
int main()
{
    int a,b,c,i;
    for(a=0;a<=9;a++)
    {
        for(b=0;b<=9;b++)
        for(c=0;c<=9;c++)
        {
            if(a==5)i++;
            if(b==5)i++;
            if(c==5)i++;
    }
    }
    printf("%d\n",i);
   }
