#include <stdio.h>
int main(){
	int a = 7;
	int *aPtr;
	aPtr = &a;
	// This statement will print the value of a
	printf("stat 01: %d \n", a);
	// This statement will print the memory address of a
	printf("stat 02: %p \n", &a);
	// This statement will print the address of a
	printf("stat 03: %p \n", aPtr);
	// This statement will print the address of the pointer varible that points to a
	printf("stat 04: %p \n", &aPtr);
	// This statement will print the value of a
	printf("stat 05: %d \n", a);
	// This statement will print the value of a
	printf("stat 06: %d \n", *aPtr);
	// This statement will print the address of a
	printf("stat 07: %p \n", *&aPtr);
	// This statement will print the address of a
	printf("stat 08: %p \n", &*aPtr);
	// This statement will print the value of a
	printf("stat 09: %d \n", *&a);
	
	
	
	
	float b = 3.7f;
	float * bPtr;
	// This statement will print 3.7
	printf("stat 01: value of b = %f \n", b);
	// This statement will print the unsigned int presentation of the address
	// that bPtr pointing at in memory
	printf("stat 02: %u \n", bPtr);
	// let bPtr point to the address of variable b in memory
	bPtr = &b;
	// Write down the value you will get from this print statement, call it var1
	//the memory address of b
	printf("stat 03: %u \n", bPtr);
	// this statement will print var1
	printf("stat 04: %u \n", &b);
	printf("stat 05: currently bPtr store the address of variable b which is %u in unsigned int format or %p in hexadecimal format \n", bPtr, bPtr);
	// this statement will print the amount of memory b takes up
	printf("stat 06: the size of b in memory is: %d \n", sizeof(b));
	// this statement is going to make bptr point to the next thing in memory
	bPtr++;	
	// Write down the value you will get from this print statement, call it var2
	// var1 + 4
	printf("stat 07: %u \n", bPtr);

	return 0;
}