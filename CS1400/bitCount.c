#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int num;
	printf("enter a number");
	scanf("%d",&num);
	
	if(num>1 && num<1000){
		printf("%f bits",ceil(log(num)/log(2)));
	}else{
		printf("INVALID");
	}
	return 0; 
}