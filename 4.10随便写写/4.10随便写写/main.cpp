#include<stdio.h>
int main()
{
    int i,a,c,n;
    int b=0;
    scanf("%d",&n);
    for (i=n;i>=1;i--)
    {
        b++;
        for(c=1;c<b;c++)
            printf(" ");
        for(a=1;a<=(2*i-1);a++)
        {
            printf("#");
        }
        printf("\n");
    }
}
