/*1. The program first asks the user to input the number of double entries to allocate (by means of the statement malloc( )).
2. If the memory is not sufficient to allocate them, then the program exits (see the first if statement in the program).
3. Otherwise, the program asks the user to fill up the double entries into an array (see the while loop, also with the possibility to break the loop when the entry is the character ’q’).
4. Finally, the program does some printings and frees the memories which have been previously allocated.*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
	double *ptd;
	int max,number,i=0;
	
	puts("What is the number of type double entries?");
	scanf("%d",&max);
	ptd=(double*)malloc(max*sizeof(double));
	
	if(ptd==NULL){
		puts("Memory allocation failed. Goodbye.");
		exit(EXIT_FAILURE); //EXIT_FAILURE is a special value in C
	}
	
	puts("Enter the values(q to quit):");
	while(i<max&&scanf("%lf",&ptd[i])==1)
		++i;
	
	printf("Here are your %d entries:\n",number=i);
	
	for(i=0;i<number;i++){
		printf("%7.2f",ptd[i]);
		if(i%7==6)
			putchar('\n');
	}
	if(i%7!=0)
		putchar('\n');
	
	puts("Done.");
	free(ptd);
	return 0;
	
}