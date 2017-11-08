#include <stdio.h>

int main(int argc, char *argv[]) {
	float t[3][4]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0};
	float*ptr;
	float a=0;
	for(int i=0;i<=2;i++)
		for(int j=0;j<=3;j++)
			{
				ptr=&t[i][j];
				a=a+*ptr;}
	printf("%f",a);
}