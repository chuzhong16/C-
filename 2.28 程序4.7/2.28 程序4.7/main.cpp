/*#include<stdio.h>
#define BLURB "Authentic imitation"
int main(void)
{
    printf("[%2s]\n",BLURB);
    printf("[%24s]",BLURB);
    printf("[%24.5s]\n",BLURB);
    printf("[%-24.5s]",)
}*/
#include<stdio.h>
#include<math.h>

int main()
{
    double a,b,c,disc,x1,x2,p,q;
    scanf("%lf,%lf,%lf",&a,&b,&c);
    disc=b*b-4.0*a*c;
    p=-b/(2*a);
    q=sqrt(disc)/(2.0*a);
    x1=(p+q);
    x2=(p-q);
    printf("\nx1=%f\nx2=%f\n%f",x1,x2,a);
}
