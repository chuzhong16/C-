#include <stdio.h>
/*编写一个统计空格、制表符和换行符个数的程序*/
int main()
{
	int c,nv,nt,nl;
	nb=0;
	nt=0;
	nl=0;
	while(c=getchar()!=EOF)
	{
			if(c==' ')
				++nb;
			if(c=='\t')
				++nt;
			if(c=='\n')
				++nl;
	}
	printf("%d %d %d\n",nb,nt,nl);
}