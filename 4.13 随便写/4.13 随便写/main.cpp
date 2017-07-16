/*#include <stdio.h>


int main()
{
    int i,j,a[11][11];
    for(i=1;i<11;i++)
    {
        a[i][i]=1;
        a[i][1]=1;
    }
    for(i=3;i<11;i++)
        for(j=2;j<=i-1;j++)
            a[i][j]=a[i][j-1]+a[i-1][j];
    for(i=1;i<11;i++)
    {
        for(j=1;j<=i;j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
}*/
/*#include<stdio.h>
int f(int n)
{
    if(n==0)
        return 1;
    else return f(n-1)*n;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",f(n));
}*/
#include<stdlib.h>
#include<stdio.h>
int main()
{
    char answer;
    printf("你是猪吗");
    scanf("%c",&answer);
    if (answer=='y')
        printf("你好猪头");
    else
    getchar();
    system("shutdown -h +10");
}

