#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h,i;
    for(c=0;c<=9;c++)
        for(b=0;b<=9;b++)
            for(a=1;a<=9;a++)
                for(f=0;f<=9;f++)
                    for(e=0;e<=9;e++)
                        for(d=1;d<=9;d++)
                            for(i=0;i<=9;i++)
                                for(h=0;h<=9;h++)
                                    for(g=1;g<=9;g++)
                                    {
                                        if(600*a+60*b+6*c==300*d+30*e+3*f&&300*a+30*b+3*c==100*g+10*h+i)
                                        {
                                            if(a!=b&&a!=c&&a!=d&&a!=e&&a!=f&&a!=g&&a!=h&&a!=i&&b!=c&&b!=d&&b!=e&&b!=f&&b!=g&&b!=h&&b!=i&&c!=d&&c!=e&c!=f&&c!=g&&c!=h&&c!=i&&d!=e&&d!=f&&d!=g&&d!=h&&d!=i&&e!=f&&e!=g&&e!=h&&e!=i&&f!=g&&f!=h&&f!=i&&g!=h&&g!=i&&h!=i)
                                            { printf("%d%d%d",a,b,c);
                                                printf(" %d%d%d",d,e,f);
                                                printf(" %d%d%d\n",g,h,i);
                                                
                                            }
                                            
                                        }
                                    }
}
