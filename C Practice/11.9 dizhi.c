#include <stdio.h>

int main(int argc, char *argv[]) {
	int a[10];
	int i;
	int *p;
	
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n");
	for(p=a;p<(a+10);p++)
	{
		printf("%d",*p);
	}
}