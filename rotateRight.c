#include <stdio.h>
/* Matthew Belanger 105016182
   2018-09-25
   Right Rotation */  

int main(void) {
	int temp,temp2,num1,num2,num3,num4;
	scanf("%d %d %d %d",&num1, &num2, &num3, &num4);
	temp = num4;
	temp2 = num2;
	num2=num1;
	num4=num3;
	num1=temp;
	num3=temp2;
	
	printf("After right rotation the numbers are\n %d\n %d\n %d\n %d\n", num1, num2, num3, num4);
	return 0;
}