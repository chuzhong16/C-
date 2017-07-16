#include<stdio.h>
int n=10;
int i,j,key;
int a[]={2,8,13,9,6,10,22,7,1,10};
int main()
{
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    for(int i=0;i<n;i++)
        printf("%d\n",a[i]);
}
