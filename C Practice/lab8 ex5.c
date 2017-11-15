#include <stdio.h>
void addArray(float a1[],float a2[],float a3[],int n);

int main(int argc, char *argv[]) {
	float a1[1000],a2[1000],a3[1000];
	int i,size;
	
	printf("Please enter the size for both arrays.\n");
	scanf("%d",&size);
	printf("Please enter array elements for the first array.\n");
	
	for(i=0;i<size;i++){
		scanf("%f",&a1[i]);
		if(i!=size-1)
			printf("Next element.\n");
		else 
			printf("Thanks for the inputs for the first array.\n");
	}
	
	printf("\n\n");
	printf("Please enter array elements for the second array.\n");
	
	for(i=0;i<size;i++){
		scanf("%f",&a2[i]);
		if(i!=size-1)
			printf("Next element.\n");
		else 
			printf("Thanks for the inputs for the second array.\n");
	}
	addArray(a1,a2,a3,size);
}
void addArray(float a1[],float a2[],float a3[],int n){
	int i;
	
	for(i=0;i<n;i++){
		a3[i]=a2[i]+a1[i];
		printf("%f %d ",a1[i],i);
	}
}