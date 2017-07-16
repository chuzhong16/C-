#include<stdio.h>
#include<string.h>
#define PRAISE "You are an "
int main(void)
{
    char name[40];
    printf("what is yoour name?");
    scanf("%s",name);
    printf("hello,%s. %s\n",name,PRAISE);
    printf("Your name of %zd letters occupies %zd memory cells.\n",strlen(name),sizeof name);
    printf("The phrase of praise has %zd letters",strlen(PRAISE));
    printf("and occupies %zd memory cells.\n",sizeof PRAISE);
    return 0;
}
