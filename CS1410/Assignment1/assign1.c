#include <stdio.h>
#define COL 200
#define ROW 200
#include <stdlib.h>
#include <time.h>

/*Description: This function will print an array
Input: a 2d array the size of rows of the array and the size of the columns
Output: prints the contents of the array in a tabular format*/
void displayArray2D(const int mat[][COL],unsigned int rowsize,unsigned int colsize);
void displayArray2D(const int mat[][COL],unsigned int rowsize,unsigned int colsize){
	printf("\n");
	for(int i = 0; i<rowsize;i++){
		for(int j =0;j<colsize;j++){
			printf("\t%d, ", mat[i][j]);
		}
		printf("\n");
	} 
}
/*
Description: This program will copy a 2D array into another array in a spiral i.e.|	1 2 3		1 2 3
Input: it will take 2 an 2D integer arrays and the row and collumn size of them	  |	4 5 6 - - > 8 9 4
Output: returns 0 if sort was succesful -1 if it was not						  | 7 8 9		7 6 5
*/
int CopyArray2DSpiral(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize);
int CopyArray2DSpiral(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize){
	return 0;//sort was sucessful
}


/*
Description: This function will copy an array into another array
Input: 2 2d arrays the size of rows of the arrays and the size of the columns
Output: returns 0 is copy is sucessful
*/
int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize,unsigned int colsize);
int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize,unsigned int colsize){
	for(int i = 0; i<rowsize;i++){
		for(int j =0;j<colsize;j++){
			B[i][j]=A[i][j];
		}
	} 
	return 0;
}

/*
This function will sort a 2d array in ascending or descending order rowwise
a 2d array the size of rows of the array and the size of the columns and either a 1 for ascending orer or a 2 for decending
returns 0 is sort is sucessful -1 if unsucessful
*/
int Sort2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize, int order);
int Sort2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize, int order){
	int temp;
	if(order == 1){ //acsending
		//holds the value of the smallest value
		for(int i=0;i<rowsize;i++){
			for(int j=0;j<colsize;j++){
				if(j!=0 && A[i][j-1]>A[i][j]){//sorts the row
					temp = A[i][j-1];
					A[i][j-1] = A[i][j];
					A[i][j] = temp;
					i = 0;
					j = 0;
				}else if(j == 0 && i != 0 && A[i-1][colsize-1]>A[i][0]){//checks if the last element in the row above is larger
					temp = A[i-1][colsize-1];
					A[i-1][colsize-1] = A[i][j];
					A[i][j] = temp;
					i = 0;
					j = 0;
				}
			}
		}
	}else if(order == 2){//descending
		for(int i=0;i<rowsize;i++){
			for(int j=0;j<colsize;j++){
				if(j!=0 && A[i][j-1]<A[i][j]){//sorts the row
					temp = A[i][j-1];
					A[i][j-1] = A[i][j];
					A[i][j] = temp;
					i = 0;
					j = 0;
				}else if(j == 0 && i != 0 && A[i-1][colsize-1]<A[i][0]){//checks if the last element in the row above is smaller
					temp = A[i-1][colsize-1];
					A[i-1][colsize-1] = A[i][j];
					A[i][j] = temp;
					i = 0;
					j = 0;//resets
				}
			}
		}
	}else{
		return -1;
	}
	return 0;
}
/*
Description: this function will sum the contents of a speciied column of a array
input:  a 2d array the size of rows of the array and the size of the columns and the specified column
output: returns the sum of the column
*/
int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int col_to_sum);
int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int col_to_sum){
	int sum = 0; // holds the sum of the column
	for(int i=0;i<rowsize;i++){
		sum+=A[i][col_to_sum];
	}
	return sum;
}
/*
Description: This function will find the largest element in an array
Input: a 2d array the size of rows of the array and the size of the columns
Output: the smallest value
*/
int FindLargest(int A[][COL], unsigned int rowsize, unsigned int colsize);
int FindLargest(int A[][COL], unsigned int rowsize, unsigned int colsize){
	int large = A[0][0];	//holds the value of the largest value
	for(int i=0;i<rowsize;i++){
		for(int j=0;j<colsize;j++){
			if(large<A[i][j]){
				large = A[i][j];
			}
		}
	}
	return large;
}
/*
Description: This function will populate an array with random integers
Input: a 2d array the size of rows of the array and the size of the columns and the minimum and the maximum value of the potential elements of the array
Output: N/A
*/
void populateArray2DUnique(int A[][COL], unsigned int rowsize,unsigned int colsize, int min, int max);
void populateArray2DUnique(int A[][COL], unsigned int rowsize,unsigned int colsize, int min, int max){
	srand(time(NULL));
	for(int i=0;i<rowsize;i++){
		for(int j=0;j<colsize;j++){
			A[i][j] = min+rand()%(max-min + 1);
		}
	}
}
int main(){
	//function parameters
	int A[ROW][COL];
	int B[ROW][COL];
	int max,min;
	int order;
	int colsize,rowsize,col_to_sum;
	
	//input
	printf("Please enter the rowsize: ");
	scanf("%d",&rowsize);
	printf("\nPlease enter the colsize: ");
	scanf("%d",&colsize);
	printf("\nPlease enter the maximum value in the array: ");
	scanf("%d", &max);
	printf("\nPlease enter the minimum value in the array: ");
	scanf("%d", &min);
	
	//function calls
	populateArray2DUnique(A, rowsize,colsize,min, max);
	displayArray2D(A, rowsize,colsize);
	printf("\nThe largest value is: %d",FindLargest(A, rowsize,colsize));
	printf("\nPlease enter the column to sum (first column is 0): ");
	scanf("%d",&col_to_sum);
	printf("The sum of that collumn is: %d",FindColSum(A, rowsize,colsize,col_to_sum));
	printf("\nEnter 1 to sort increasing or 2 to decrease: ");
	scanf("%d",&order);
	Sort2DArray(A, rowsize,colsize,order);
	displayArray2D(A, rowsize,colsize);
	CopyArray2D(A,B,rowsize,colsize);
	
	return 0;
}