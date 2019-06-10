#include <stdio.h>
#include <stdlib.h>

int main(void){
	float num,total=0;
	char yn = 'n';
	int count;
	while(yn !='Y'){
		count += 1; 
		printf("\nEnter a number: ");
		scanf("%f",&num);
		
		if(num>0){
			total += num;
		}
		
		printf("\nexit (Y/N): ");
		scanf("%c", &yn);
		
	}
	printf("Sum of positive numbers = %.1f , Count = %d",total,count);
}