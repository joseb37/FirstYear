#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
double rec(float base,int exp){
	static float pow = 1;
	if(exp!=0){
		pow=base*rec(base,--exp);
	}
	return pow;
}
double loop(float base,int exp){
	static float pow = 1;
	for(int i = 0; i<exp;i++){
		pow *= base;
	}
	return pow;
}
int main(void){
	char ch;
	float base;
	int exp;
	
	printf("loops or functions?\n");
	scanf("%c",&ch);
	scanf("%c",&ch);
	printf("\nPlease enter a base(any real number) and an exponent(a positive integer or 0)\n");
	scanf("%f %d",&base,&exp);
	
	if(ch=='F'||ch=='f'){
		printf("%f",rec(base,exp));
		
	}else{
		printf("%f",loop(base,exp));
	}
	return 0;
}