#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printArray(const int mat[],unsigned int size);
void printArray(const int mat[], unsigned int size){
	printf("\n");
	for(int i = 0; i<size;i++){
		printf("%d, ", mat[i]);
	}
}

void SortArray(int A[],unsigned int size){
	int temp;
	for(int i=0;i<size-1;i++){
		if(A[i]>A[i+1]){
			temp = A[i+1];
			A[i+1] = A[i];
			A[i] = temp;
			i=-1;
		}
	}
}

int main(){
	int A[]={4,2,1,3,5};
	printArray(A,5);
	SortArray(A,5);
	printArray(A,5);
	return 0;
}