#include<stdio.h>
int main()
{
	FILE*pfile;
	char ch='A';
	pfile=fopen("hello.txt","w+");
	fputc(ch,pfile);
	rewind(pfile);
	ch=fgetc(pfile);
	printf("%c",ch);
} 
