#include <stdio.h>

double piApprox(int i){
	if(i%2==0){
		return -1*(1/((double)(2*i - 1)));
	}else{
		return (1/((double)(2*i - 1)));
	}
}

int main(void){
	double pi = 0;
	for(int i=1;i<=100;i++){
		pi=piApprox(i)+pi;
	}
	printf("%.3f",4*pi);
	return 0;
}