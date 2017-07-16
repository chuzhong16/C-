#include<stdio.h>
int a[101],n;//定义全局变量
void quicksort(int left,int right)
{
    int i,j,t,temp;
    if(left>right)
        return;
    
    temp=a[left];//temp中存的是准基数
    i=left;
    j=right;
    while(i!=j)
    {
        //从右往左找
        while(a[j]>=temp&&i<j)
            j--;
        //从左往右找
        while(a[i]<=temp&&i<j)
            i++;
            if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[left]=a[i];
    a[i]=temp;
    
    quicksort(left,i-1);
    quicksort(i+1,right);
    return;
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    quicksort(1, n);
    for(i=1;i<=n;i++)
        printf("%d",a[i]);
    getchar();
    return 0;
}
