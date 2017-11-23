#include <stdio.h>
struct book{
	char title[20];
	char author[20];
	float value;
};
int main(int argc, char *argv[])
{
	struct book lib;
	struct book*plib=&lib;
	gets(plib->title);
	gets(plib->author);
	scanf("%f",&plib->value);
	printf("%s by %s is %.2f\n",plib->title,plib->author,plib->value);	
}