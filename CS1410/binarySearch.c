#include <stdio.h>

int linearSearch(int list[],int search,int size){
	int count =0;
	for(int i =0;i<size;i++){
		if(list[i]==search){
			count++;
		}
	}
	printf("\nnum found %d time(s)\n",count);
	return count;
}

void binarySearch(int list[],int search,unsigned int size){
	int i=size/2;
	while(1){
		if(list[i]>search){
			size = i;
			i=i/2;
		}else if(list[i]<search){
			i = (size+i)/2;
		}else{
			printf("found at index %d",i);
			break;
		}
	}
}

int main(){
	int list[] = {1, 4 ,9, 13, 16, 25,33,50,101,121};
	binarySearch(list,121,10);
	linearSearch(list,33,10);
	return 0;
}