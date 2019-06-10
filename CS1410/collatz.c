#include <stdio.h>
#define CASES 100000

int SequenceLength(long A, long lim){
	int i;
	for(i = 1; A!=1 ;i++){
		if(A%2==0){
			A=A/2;
		}else{
			A = 3*A +1;
			if(A>lim){
				break;
			}
		}
	}
	return i; 
}

int main(void){
	int i;
	int j;
	long A[CASES];
	long lim[CASES];
	int lengths[CASES];
	for(i=0; 1 ;i++){
		scanf("%ld %ld",&A[i],&lim[i]);
		if(A[i]<0 && lim[i]<0){
			break;
		}
		lengths[i] = SequenceLength(A[i],lim[i]);
	}
	for(j = 0; j<i;j++){
		printf("Case %d: A = %ld, limit = %ld, number of terms = %d\n",j+1,A[j], lim[j],lengths[j]);
	}
	return 0;
}