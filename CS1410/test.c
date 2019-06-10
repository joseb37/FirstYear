
#include <stdio.h> 
 void f2(int n, int a[]) { 	  	
 for (int i=0;i<n-1;i++)     
	 	 	a[i]=a[i+1]; 	 
}  int main() {  	
int A[]={1,2,3,4,5,6};  	
int i, N=6; 
	 	for (i=0;i<N;i++)    
	 	 	printf("%d ",A[i]); 
 
	 	printf("\n");  
 
	 	f2(N,A); 
  	for (i=0;i<N;i++)    
	 	 	printf("%d ",A[i]); 
 	 
	 	return 0;  
}  
