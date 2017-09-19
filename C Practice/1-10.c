#include <stdio.h>
/*编写一个将输入复制到输出的程序，并将其中的制表符替换为/t,把回退符替换成\b,把反斜杠替换成\\*/
int main()
{
	int c;
	while((c=getchar())!=EOF)
	{
		if(c=='\t')
			printf("\\t");/*\t 的意思是 横向跳到下一制表符位置*/
		if(c=='\b')
			printf("\\b");/*\b是退格符*/
		if(c=='\\')
			printf("\\\\");
		if(c!='\b')
			if(c!='\t')
				if(c!='\\')
					putchar(c);
	}
}