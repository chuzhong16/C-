#include<stdio.h>
int main()
{
    char x[100];
    int i;
    printf("shuru\n");
    gets(x);
    x[0]=x[0]-32;
    for(i=1;x[i]!='\0';i++)
    {
        if(x[i-1]==' ')
        {
            x[i]=x[i]-32;
        }
    }
    for(i=0;x[i]!='\0';i++)
    {
        printf("%c",x[i]);
    }
    printf("\n");
    return 0;
}
