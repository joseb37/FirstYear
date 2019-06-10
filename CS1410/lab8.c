#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
bool isPrime(float num){
	float check = num-1;
	float div;
	while(check!=1){
		div = num/check;
		if(floor(div)==ceil(div)){
			return 0;
		}
	check--;
	}
	return 1;
}

int readNum(void){
	int num;
	printf("Enter a positive integer: ");
	scanf("%d",&num);
	if(num>=0){
		return num;
	}else{
		printf("\nINVALID\n");
		return 0;
	}
	
}
int sumDigits(int num){
	int total = 0;
	while(num){
		total += (num % 10);
		num /= 10;
	}
	return total;
}

int main(void){
	int num = readNum();
	int sum = sumDigits(num);
	bool prime = isPrime(num);
	printf("The sum of the digits are: %d\n",sum);
	if(prime){
		printf("It is prime");
	}else{
		printf("It is not prime");
	}
	return 0;
}