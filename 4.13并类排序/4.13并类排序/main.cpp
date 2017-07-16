#include<stdio.h>
int n=6,max=100;
int a[]={1,3,2,4,6,76,32};

void merge(int*a,int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int L[max],R[max];
    for(int i=0;i<n1;i++)
        L[i]=a[p+i];
    for(int i=0;i<n2;i++)
        R[i]=a[q+i+1];
    L[n1]=max;R[n2]=max;
    int i=0,j=0;
    for(int k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=R[j];
            j++;
        }
    }
    
}

void mergeSort(int*a,int p,int r)//a是数组，p是左下标，r是右下标
{
    if(p<r)
    {
        int q=(p+r)/2;
        mergeSort(a, p, q);
        mergeSort(a, q+1, r);
        merge(a,p,q,r);
    }
    int main(){
        int i;
        mergeSort(a,0, n-1);
        for(i=0;i<n;i++)
            printf("%d",a[i]);
    }
