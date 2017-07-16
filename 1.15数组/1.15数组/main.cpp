/*#include<stdio.h>
 int main()
 {
 int a[100],i,j,k,n;
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 scanf("%d",&a[i]);
 for(i=1;i<=n-1;i++)
 {
 for(j=1;j<=n-i;j++)
 {
 if(a[j]<a[j+1])
 {
 k=a[j];a[j]=a[j+1];a[j+1]=k;
 }
 }
 }
 for(i=1;i<=n;i++)
 printf("%d",a[i]);
 }*/
#include<stdio.h>
int main()
{
    int a[10];
    int i,j,t;
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n");
    for(j=0;j<9;j++)
    {
        for(i=0;i<9-j;i++)
        {
            if(a[i]>a[i+1])
            {
                t=a[i];a[i]=a[i+1];a[i+1]=t;
            }
        }
        for(i=0;i<10;i++)
            printf("%d",a[i]);
    }
}
