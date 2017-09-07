#include <stdio.h>
int main()
{
	int n,i;
	float x,t,s;
	printf("为n,x赋值:\n");
	scanf("%d%f",&n,&x);
	for(s=t=1.0,i=1;i<=n;i++)
	{
		t=t*x/i;s+=t;
	}
	printf("当n=%d,x=%.2f时,s=%.5f: \n",n,x,s);
}