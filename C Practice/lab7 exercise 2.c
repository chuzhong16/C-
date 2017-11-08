#include <stdio.h>

int main(int argc, char *argv[]) {
	char *adr="hello";
	int i;
	for(i=0;i<3;i++)
		printf("%s",(adr+i));
	
}