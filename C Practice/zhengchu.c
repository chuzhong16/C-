#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a;
	scanf("%d",&a);
	if (a%2==0)
		printf("yes");
	if (a%2!=0)
		printf("no");
	system("pause");
	return 0;
}