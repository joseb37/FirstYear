/*Matthew Belanger
  Problem 5
  This program prints Fibonacci Numbers
  2018-11-09*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int main(void){
	double f1 = 0,f2=1,fCurrent=1;
	printf("Fib(1): %.0f\nFib(2): %.0f\nFib(3): %.0f\n",f1,f2,fCurrent);
	for(int i = 0;i<97;i++){
		f1=f2;
		f2=fCurrent;
		fCurrent=f1+f2;
		printf("Fib(%d): %.0f\n",i+4,fCurrent);
	}
	return 0;
}