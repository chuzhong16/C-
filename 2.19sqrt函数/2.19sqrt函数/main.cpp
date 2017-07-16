#include<stdio.h>
int sqrt01(int question);
int main()
{
    int question=49,answer;
    answer=sqrt01(question);
    if(question<0)
        printf("Error");
    else
        printf("the square root of %d is %d\n",question,answer);
}
int sqrt01(int question)
    {
    int temp;
        temp=question/2;
    while(temp--)
    {
        if(temp*temp==question)
            return temp;
    }
        return -1;
    }
