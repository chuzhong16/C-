#include <stdio.h>
double difference(double a[],int size);
int main(int argc, char *argv[]) {
	double a[1000];
	int i,size;
	printf("Please enter the size of the array.\n");
	scanf("%d",&size);
	if(size==1){
		printf("The size must be at least 2 and try it later.\n");
		return 0;
	}
	printf("Please enter array elements.\n");
	
	for(i=0;i<size;i++){
		scanf("%lf",&a[i]);
		if(i!=size-1)
			printf("Next element.\n");
		else 
			printf("Thanksfor the inputs.\n");
	}
	printf("\n The difference between the largest and smallest elements in the array is %lf\n",difference(a,size));
	return 0;
}
double difference(double a[],int size){
	int i;
	double largest=0.0,smallest;
	for(i=0;i<size;i++){
		if(a[i]>=largest){
			largest=a[i];
		}
	}
	
	smallest=a[0];
	for(i=0;i<size;i++){
		if(a[i]<=smallest){
			smallest=a[i];
		}
	}
	return(largest-smallest);
}