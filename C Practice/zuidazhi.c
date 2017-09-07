#include <stdio.h>
int max(int a,int b,int c)
{
	int big;
	big=a;
	if(b>big)
		big=b;
	if(c>big)
		big=c;
	return big;
}
int main()
{
	int x,y,z,s;
	printf("input three integral numbers:\n");
	scanf("%d,%d,%d",&x,&y,&z);
	s=max(x,y,z);
	printf("maxmum=%d\n",s);
}