#include<stdio.h>
int main()
{
    int a;
    printf("1:average\n"
           "2:Factorial\n"
           "3:Square root\n"
           "4:Exit\n");
    scanf("%d",&a);
    float x,y,z,ave;
    ave=(x+y+z)/3;
    switch(a)
    {
        case 1:
            printf("please input 3 numbers\n");
            scanf("%f%f%f",&x,&y,&z);
            printf("average is %f\n",ave);
    }
}
