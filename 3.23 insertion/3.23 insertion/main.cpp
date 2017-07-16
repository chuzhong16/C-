#include <stdio.h>
int a[]={5,2,4,6,1,3};
int n=6;
int main() {
    for (int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while (a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
}
