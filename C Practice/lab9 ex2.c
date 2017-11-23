/* Write a program that declares a 3 by 5 two-dimensional array and initialises it with some values of your choice. The program should:
a. print all the values;
b. double the values;
c. print all the values again.
Write a function that is responsible for displaying the values and a second function that doubles the values. The functions could take as arguments the array name and the number of rows as arguments.*/
#include <stdio.h>
#include <stdlib.h>

void display(int **a,int cols,int rows);
void doublevalue(int **a,int cols,int rows);
int main(int argc, char *argv[]) 
{
	int **marray;
	int x,y,rows=3,cols=5;
	
	marray=(int **)malloc(rows*sizeof(int*));
	if(marray==NULL)
	{
		free(marray);
		printf("Memory allocation failed while allicating for marray[].\n");
		exit(0);
	}
	
	for(x=0;x<rows;x++){
		marray[x]=(int*)malloc(cols*sizeof(int));
		if(marray[x]==NULL){
			free(marray[x]);
			printf("Memory allocation failed while allocating for marray[x]\n");
			exit(0);
		}
	}
	
	for(y=0;y<rows;y++){
		for(x=0;x<cols;x++){
			marray[y][x]=x+y;
		}
	}
	
	printf("Print all values:\n");
	display(marray,cols,rows);
	
	doublevalue(marray,cols,rows);
	printf("Double the values:\n");
	display(marray,cols,rows);
	
	for(x=0;x<rows;x++)
		free(marray[x]);
		
	free(marray);
}

void display(int **a,int cols,int rows){
	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
void doublevalue(int**a,int cols,int rows){
	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			a[i][j]*=2;
		}
	}
}
