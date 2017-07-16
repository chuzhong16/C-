#include<stdio.h>
#define PRAISE "You are an."
int main()
{
    char name[40];
    printf("what is your name");
    scanf("%s",name);
    printf("hello,%s. %s\n",name,PRAISE);
}
