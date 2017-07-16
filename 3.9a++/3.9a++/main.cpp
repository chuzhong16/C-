#include <stdio.h>
#include <math.h>

int main()
{
    int i=0;
    char c;
    while(1)
    {
        c='\0';
        while(c!=13&&c!=27)
        {
            c=getchar();
            printf("%c\n",c);
            break;
        }
        if(c==27)
            break;
        i++;
        printf("The No. is %d\n",i);
    }
    printf("The end\n");
}
