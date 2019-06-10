#include <stdio.h>

int main(void){
	int num1,num2;
	char op;
	printf("enter an expression: ");
	scanf("%1d %1c %1d",&num1,&op,&num2);
	if(op == '*'){
		printf("%d",num1*num2);
	}else if(op == '/'){
		if(num2==0){
			printf("divison by 0 is invalid");
		}else{
			printf("%d",num1/num2);
		}
	}else if(op == '-'){
		printf("%d",num1-num2);
	}else if(op == '+'){
		printf("%d",num1 +num2);
	}else{
		printf("invaild operation");
	}
	return 0;
}