#include <math.h>
#include <stdio.h>
int main()
{
	int s;
	float n,t,pi;
	s=1,pi=0,n=t=1.0;
	do 
	{
		pi+=t;
		n+=2;
		s=-s;
		t=s/n;
	} while (fabs(t)>1e-6);/*fabs求绝对值*/
	pi*=4;
	printf("pi=%.6f\n",pi);
}