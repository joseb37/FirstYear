#include <stdio.h>

int main(void){
	int num1,num2;
	char op;
	printf("enter an expression: ");
	scanf("%1d %1c %1d",&num1,&op,&num2);
	switch(op){
	case "+" printf("%d", num1 + num2); break;
	case "-" printf("%d", num1 - num2); break;
	case "*" printf("%d", num1 * num2); break;
	case "/" printf("%d", num1 / num2); break;
	default printf(invalid operation)
	}
}