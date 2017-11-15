#include <stdio.h>
int index(int a[],int n);
int main(int argc, char *argv[]) {
	int a[10000];
	int i,size;
	
	printf("Please enter the size of the array.\n");
	scanf("%d",&size);
	printf("Please enter array element.\n");
	
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
		if(i!=size-1)
			printf("Next element.\n");
		else 
			printf("Thanks for the inputs.\n");
	}
	printf("\n The index of the largest value in the array is %d.\n",index(a,size));
	return 0;
}
int index(int a[],int n){
	int i,j,largest=0;
	for(i=0;i<n;i++){
		if(a[i]>largest){
			largest=a[i];
			j=i;
		}
	}
	return j;
}