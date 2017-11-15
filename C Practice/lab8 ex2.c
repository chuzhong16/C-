#include <stdio.h>

int main(int argc, char *argv[]) {
	float t[3][4];
	float *ptr;
	float sum=0.0;
	int i,j;
	
	srand(time(0));
	ptr=&(t[0][0]);
	for(i=0;i<3*4;i++){
		sum+=*(ptr+i)=((float)rand()/(rand()+1));
		printf("The pointed value %f and index i:%d\n",*(ptr+i),i);
	}
}