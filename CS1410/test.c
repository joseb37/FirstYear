#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
/* Function to sort an array using insertion sort*/
void InsertionSort(int arr[], int size, int insert) { 
	int temp;
	for(int i = 0;i<size;i++){
		if(insert<arr[i]){
			while(i<size){
				temp = arr[i];
				arr[i] = insert;
				insert = temp;
				i++;
			}
		}
	}
	size++;
} 

int main(){
	int arr[MAX] = {1,2,3,4,6,7,8,9};
	InsertionSort(arr,9,5);
	for(int i =0;i<9;i++){
		printf("%d",arr[i]);
	}
	return 0;
}