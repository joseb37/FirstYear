#include <stdio.h>

int main(){
	int arr[] = {1,2,3,4,5,6,7};
	int size =7;
	int temp;
	for(int i =0;i<size/2;i++){
		temp = arr[i];
		arr[i]=arr[size-1-i];
		arr[size-1-i] = temp;
	}
	for(int i =0;i<size;i++){
		printf("%d, ",arr[i]);
	}
	return 0;
}