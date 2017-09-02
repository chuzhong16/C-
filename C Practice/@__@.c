#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b;
	a=1;
	while(a<=3)
	{
		b=1;
		while(b<=5)
		{
			printf("@");
			b++;
		}
		printf("\n");
		a++;
	}
	system("pause");
	return 0;
}