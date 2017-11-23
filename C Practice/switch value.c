#include <stdio.h>
void swap(int *u,int *v);
int main(int argc, char *argv[]) {
	int x=5,y=10;
	swap(&x,&y);
	printf("%d",x);
}

void swap(int *u,int *v)
{
	int temp;
	temp=*u;
	*u=*v;
	*v=temp;
}