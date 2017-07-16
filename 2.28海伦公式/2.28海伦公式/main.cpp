#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,s,area;
    scanf("%f,%f,%f",&a,&b,&c);
    s=0.5*(a+b+c);
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("a=%10.3f,b=%.2f,c=%.2f,s=%.2f\n",a,b,c,s);
    printf("area=%7.2f\n",area);
}
