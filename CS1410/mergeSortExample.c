/*in class example to demostrate merge sort*/

#include <stdio.h>

void printArray(const int mat[],unsigned int size);
void printArray(const int mat[], unsigned int size){
	printf("\n");
	for(int i = 0; i<size;i++){
		printf("%d, ", mat[i]);
	}
}

void mergeSort(const int A[], unsigned int size_a, const int B[], unsigned int size_b,int C[]);
/* mergeSort: merge the contents of 2 sorted arrays into a new arrays
   Input: 3 arrays, A, B, C and the size of A and B (positive int)
   Assume C is large enough to contain A and B
   Assume A and B are sorted
   Output: combine the contents of A and B such that the contents of C are sorted
   */
   
 /*Steps to code merge sort*/
 /*	1.check which value is smaller at given indices
	2. copy the smaller value to C at c
	3. increment each index
	4.Check if a or b are finished
 */
void mergeSort(const int A[], unsigned int size_a, const int B[], unsigned int size_b,int C[]){
	int a = 0; 	// maintain the current position in A
	int b = 0;	//... in B
	int c;	//... in C
	for(c=0; c<size_a+size_b; c++){	
		//check is A is finished
		if(a == size_a){
			//copy rest of B
			C[c] = B[b];
			b++;
		}else if(b == size_b){
			//copy rest if of A
			C[c] = A[a];
			a++;
		}else{	
			if(A[a]<=B[b]){
				C[c] = A[a];
				a++;
			}else{
				C[c] = B[b];
				b++;
			}
		}
	}	
}
// tester code
int main(){
	int A[] = {1,3,5,7,9};
	int B[] = {2,3,6};
	int C[100];
	mergeSort(A, 5, B, 3, C);
	printArray(C,8);
	return 0;
}