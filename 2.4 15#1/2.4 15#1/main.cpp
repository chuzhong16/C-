#include<stdio.h>/*Include information from the header file named stdio.h*/
int main()/*Define a main function named main*/
{
    int ID;/*Declare an interger named ID*/
    char name[50];/*Declare an array of 50 characters, whose name is name.*/
    printf("Please enter your name and student ID:\n");/*Ask for name and ID number.*/
    gets(name);/*Acquire the name(with space) entered.*/
    scanf("%d",&ID);/*Acquire the ID number entered.*/
    printf("Your name is:"); /*Display "Your name is:".*/
    puts(name);/*Display the name.*/
    printf("Your student ID is:%d\n",ID);/*Display the number.Ended with a return.*/
    return 0;/*Return value 0 to the system.*/
}
