/*
Name: Simple Program for Name,Student ID number and Height
File name: 1613453_1.c
copyright: Free
Author: Zhong Chu ID number: 1613453.
Description: A Programm that can read full name,student ID number and height that user inputs, then store them in string,integer and float. Reverse the string. Divide and print the sum of first 4 digits and the sum of rest. convert the height which uses unit of 'meter' to units of 'feet' and 'inch'*/
#include <stdio.h>                                  /* include information about standard library stdio.h*/
#include <string.h>                                 /* include information about standard library string.h*/
#include <math.h>                                   /* include information about standard library math.h*/
#include <stdlib.h>                                 /* include information about standard library stdlib.h*/
#define chartonumber(x) (x-'0')                     /* To transform x from char to int*/

int main()                                          /* Define a main function named main*/
{
	char name[50],IDnumber[50];                     /* Declare two arrays of 50 characters, whose name are name and IDnumber.*/
	float height,sum_first,sum_last,result;          /* Declare four variables of type of float namely heigh,sum_first,sum_last andresult*/                                              
	int feet,inches,i;                              /* Declare three variables of type of int namely feet,inches and i*/
	sum_first=sum_last=result=0.0;                  /* let the initial value of sum_first,sum_last,result equal to 0.0*/
	
	printf("Please enter your name:\n");            /* Ask user to input their name.*/
	gets(name);                                     /* store the name into the array of the name.*/
	
	printf("Please enter your student ID:\n");      /* Ask user to input their student ID.*/
	gets(IDnumber);                                 /* store the student ID into the array of the name.*/
	while(strlen(IDnumber)!= 8){
		printf("Please enter your student ID and asumme ID's have 8 digits:\n");
		gets(IDnumber);                             /* Using while to make sure the length of IDnumber is eight*/                           
	}
	
	printf("Please enter a height:\n");              /* Ask user to input a heigh*/
	scanf("%f",&height);                             /* store the value of the input number into variable heigh using the scanf function */
	
	printf("The name in reverse is ");              /* display The name in reverse is on the screen */
	i=strlen(name);                                 /* compute the length of name and assign it to i*/
	for( ; i >= 0;--i)                             
		printf("%c",name[i]);                       /* Using a for-loop to print the name in reverse*/
	printf("\n");                                   /* To exchange a newline */

	for(int j = 0;j< 8;j++)                          
	{
		IDnumber[j]=chartonumber(IDnumber[j]);      /* To transform IDnumber[j] from char to int*/
		if(j<4)                                     /* If j is smaller than four*/
			sum_first=sum_first+IDnumber[j];       
		else                                        /* If j is larger than four*/

			sum_last=sum_last+IDnumber[j];      
	}
	result=sum_first/sum_last;                      /* compute the result at the given number according to the formula provided */
	printf("The division of the first 4 digits and the last four digits of the ID number is %.2f/%.2f=%.2f",sum_first,sum_last,result);
												    /* display the division of the first 4 digits and the last four digits of the ID number is */
	printf("\n");                                   /* To exchange a newline */

	feet=height/0.3048;                              /* Convert imperial height into feet form.*/
	inches=(height-feet*0.3048)/0.0254;              /* Convert the rest into inches form*/
	if(fabs(height-feet*0.3048-inches*0.0254)>fabs(height-feet*0.3048-(inches+1)*0.0254))
		++inches;                                   /* make sure the results are rounded*/
	printf("%.2f m is %d feet %d inches\n",height,feet,inches);
		                                            /* display Conversion results on the screen */
	system("pause");                                /* system ("pause") is from the program call "pause" command*/
	return 0;		                                /* Return value 0 to the system.*/
	}

