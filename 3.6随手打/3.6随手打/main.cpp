#include <stdio.h>
#include <math.h>

int main()
{
    int year, leap;  //leap是判断闰年的标志，值为一表示闰年， 0表示非闰年
    scanf("%d",&year);
    if (year%4==0)
    {
        if (year%100==0)
        {
            if (year%400==0)
            {
                leap=1;
            }
            else
            {
                leap=0;
            }
        }
        else
        {
            leap=1;
        }
    }
    else
    {
        leap=0;
    }
    if (leap)
    {
        printf("%d is",year);
    }
    else
    {
        printf("%d is not",year);
    }
    
}
