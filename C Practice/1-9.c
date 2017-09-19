#include <stdio.h>
/*编写一个将输入复制到输出的程序，并将其中连续的空格用一个空格代替*/
#define NONBLANK 'a'
int main()
{
	int c,lastc;
	lastc=NONBLANK;
	while((c=getchar())!=EOF)
	{
		if(c!=' ')
			putchar(c);
		if(c==' ')
			if(lastc!=' ')
				putchar(c);
		lastc=c;
	}
}