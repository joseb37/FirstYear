#include <stdio.h>
/*this program will swap two elements into diffrent variables
it will take two memory addresses as input
n/a*/ 
void swap(int * var1, int * var2);
void swap(int * var1, int * var2){
	int temp;
	temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}
/*this program will reverse the order of an array
it will take the size of the array and the arrays memory address as input*/
void ReverseArray(int size, int *ptr2Array);
void ReverseArray(int size, int *ptr2Array){
	for(int i=0;i<(size/2);i++){
		swap(ptr2Array+i,ptr2Array+size-1-i);
	}
}
/*this program will calculate the sum the average and the max and min values in an array
input is the array and its size and the memory addresses of sum average max and min*/
void ArrayInfo(int A[],int *sum,float *avg,int *min,int *max,int size);
void ArrayInfo(int A[],int *sum,float *avg,int *min,int *max,int size){
	*sum = 0;
	*min = *A;
	*max = *A;
	for(int i =0;i<size;i++){
		if(A[i]<*min){
			*min=A[i];
		}else if(*max<A[i]){
			*max=A[i];
		}
		*sum=*sum+A[i];
	}
	*avg=(double)*sum/size;
}
/*this program will print the elements of an array and the memory address of each elements
it takes the array and the size of the array as input
it will display the elements and the memory addresses of each element*/
void PrintArray(int size, int array []);
void PrintArray(int size, int array []){
	for(int i=0; i<size; i++){
		printf("array[%d] = %d \n", i, array[i] );
		printf("array[%d] = %p \n\n", i, &array[i] );
	}
}
/*this function will sort a 1d array in acsending order
it takes the size of the array and the array as input
*/
void Sort(int size, int array[]);
void Sort(int size, int array[]){
	for(int i=0;i<size-1;i++){
		if(array[i]>array[i+1]){
			swap(array+(i+1),array+i);
			i=-1;
		}
	}
}
int main(){
	int sum,min,max;
	float avg;
	int data [] = {2, 7, 8, -8, 1, 9, 3, 5};
	int size = sizeof(data)/sizeof(int);
	Sort(size, data);
	PrintArray(size, data);
	ArrayInfo(data,&sum,&avg,&min,&max,size);
	ReverseArray(size,data);
	printf("\n\nsum: %d\taverage: %.3f\tmax: %d\tmin: %d\n\n\n",sum, avg, min ,max);
	PrintArray(size, data);
	return 0;
}