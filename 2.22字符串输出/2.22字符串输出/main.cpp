#include<stdio.h>
#include<string.h>
#define DENSITY 62.4
int main()
{
    float weight,volume;
    int size,letters;
    char name[40];
    printf("Hi!what is your first name\n");
    scanf("%s",name);
    printf("%s,what is your weight in pounds?\n",name);
    scanf("%f",&weight);
    size=sizeof name;
    letters=strlen(name);
    volume=weight/DENSITY;
    printf("well,%2.2f\n",volume);
    printf("Also,%d",letters);
}
