#include <stdio.h>

int main(int argc, char *argv[]) {
	int *ptr;
	int arr2D[3][3]={{2}，{3，4，5}，{6}}；
	ptr=&arr2D[0];
	printf("%d",*(ptr+2));
	return 0;
	
}