#include <stdio.h>
#include <string.h>

int main()
{
	char name[50];
	char IDnumber[50];
	float heigh;
	int i,j;
	
	printf("Please enter your name:\n");
	gets(name);
	
	printf("\nPlease enter your student ID:\n");
	gets(IDnumber);
	while(strlen(IDnumber)!=8){
		printf("Please enter your student ID and asumme ID's have 8 digits:\n");
		gets(IDnumber);
	}
	
	printf("Please enter a heigh:\n");
	scanf("%f",&heigh);
	
	i=strlen(name);
	for(;i>=0;--i)
		printf("%c",name[i]);
	printf("\n");

	for(j=0;j<8;j++){
		if(j==0||j==4)
			printf("(%c",IDnumber[j]);
		else if (j==3)
			printf("+%c)/",IDnumber[j]);
		else if (j==7)
			printf("+%c)",IDnumber[j]);
		else 
			printf("+%c",IDnumber[j]);
	}
}
