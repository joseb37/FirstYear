#include <stdio.h>
#include <stdlib.h>

int main(void){
	int goal = rand() % 50 + 1;
	int guess = -1;
	int count = 0;
	while(count!=10){
		printf("Try and guess my integer between 0 and 50: ");
		scanf("%d",&guess);
		if(guess>goal){
			printf("TOO HIGH TRY AGAIN\n");
			count+=1;
		}else if(guess<goal){
			printf("TOO LOW TRY AGAIN\n");
			count+=1;
		}else{
			printf("YOU WIN\n");
			count = 10;
		}
	}
	if(guess!=goal){
		printf("YOU ARE OUT OF GUESSES YOU LOSE :(");
	}
}