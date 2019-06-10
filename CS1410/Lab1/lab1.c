#include <stdio.h>

/*this function will take the sum of a number and every integer less than it to 1 using an iterative algorithm
	input: a positive integer 
	output: the sum of 1 to that number*/
int fun1(int n);
int fun1(int n){
	int total = 0; //holds the total of the sum
	for(int i =1;i<=n;i++){
		total = total + i;
	}
	return total;
}

/*this function will take the sum of a number and every integer less than it to 1 using an recursive algorithm
	input: a positive integer 
	output: the sum of 1 to that number*/
int fun1r(int n);
int fun1r(int n){
	if(n==1){
		return 1;
	}else{
		return n+fun1r(n-1);
	}
}

/*this function will calculate the sum of squares a number plus 1 using an iterative algorithm
	input: a number number
	output: the sum of the squares of 1+1 to n+1
	*/
int fun2(int n);
int fun2(int n){
	int total = 0;//stores the total of the sum
	
	for(int i = 1;i<=n;i++){
		total += (i+1)*(i+1);
	}
	return total;
}

/*this function will calculate the sum of squares a number plus 1 using an recursive algorithm
	input: a number number
	output: the sum of the squares of 1+1 to n+1
	*/
int fun2r(int n);
int fun2r(int n){
	if(n==1){
		return 4;
	}else{
		return (n+1)*(n+1) + fun2r(n-1);
	}
}

/*	this function will return the nth fibonacci number using an iterative algorithm
	input: a numebr n
	output: the nth fibonacci number*/
int fibonacci(int n);
int fibonacci(int n){
	int fib2=0; //holds f(n-2) for fn=f(n-1)+f(n-2))
	int fib1=1; //holds f(n-1) for fn=f(n-1)+f(n-2))
	int fib; //holds fn
	
	if(n==1){
		return fib2;
	}else if(n==2){
		return fib1;
	}else{
		for(int i = 3;i<=n;i++){
			fib = fib1+fib2;
			fib2=fib1;
			fib1=fib;
		}
	}
	return fib;
}

/*	this function will return the nth fibonacci number using an recursive algorithm
	input: a numebr n
	output: the nth fibonacci number*/
int fibonaccir(int n);
int fibonaccir(int n){
		if(n==1){
			return 0;
		}else if(n==2){
			return 1;
		}else{
			return fibonaccir(n-2)+fibonaccir(n-1);
		}
}

/*	this function will find the greatest common divisor between two integers using an iterative algorithm
	input: two integers
	output: the greatest common divisor between the inputs
	*/
int gcd(int x, int y);
int gcd(int x, int y){
	for(int i = x;i>0;i--){
		if(x%i==0&&y%i==0){
			return i;
		}
	}
	return 1;
}
/*	this function will find the greatest common divisor between two integers using a recursive algorithm
	input: two integers
	output: the greatest common divisor between the inputs
	*/
int gcdr(int x, int y);
int gcdr(int x, int y){
	if(y==0){//base case
		return x;
	}else{//recursive call
		return gcdr(y,x%y);	
	}
}

/*	Power: This function will calculate awnser of a number raised to an exponent using an iterative algorithm
	input: 2 positive integers a^between
	output: the solution to a^between
	*/
int Power(int a, int b);
int Power(int a, int b){
	int total = 1;//holds the awnser to a^i
	for(int i=0;i<b;i++){
		total = total*a;
	}
	return total;
}

/*	Power: This function will calculate awnser of a number raised to an exponent using a recursive algorithm
	input: 2 positive integers a^between
	output: the solution to a^between
	*/
int Powerr(int a, int b);
int Powerr(int a, int b){
	if(b==1){//base case
		return a;
	}else{// recursive call
		return a*Powerr(a,b-1);
	}
}

/* Display: displays numbers less than an integer n that re divisible by an int m using an iterative algorithm
	input: integers n and m
	output: numbers less than an integer n that re divisible by an int m
	*/
void display(int n, int m);
void display(int n, int m){
	while(n-m!=0){
		if(n%m==0){
			printf("%d\n",n);
		}
		n=n-1;
	}
	if(n%m==0){
		printf("%d\n",n);
	}
}
/* Display: displays numbers less than an integer n that re divisible by an int m using a recursive algorithm
	input: integers n and m
	output: numbers less than an integer n that re divisible by an int m
	*/
void displayr(int n, int m);
void displayr(int n, int m){
	if((n-m)!=0){
		if(n%m==0){
			printf("%d\n",n);
			displayr(n-1,m);
		}else{
			displayr(n-1,m);
		}
	}
}


void drawLine(int n);
void drawLine(int n){
	if(n==1){
		printf("*");
	}else{
		printf("*");
		drawLine(n-1);
	}
}

/* Draw Triangle: displays a right triangle of "*" of height n using an iterative algorithm
	input: integers n 
	output: a right triangle of "*" of height n
	*/
void drawTriangle(int n);
void drawTriangle(int n){
	for(int i = 1; i <= n; i++){
		drawLine(i);
		printf("\n");
	}
}
	
/* Draw Triangle: displays a right triangle of "*" of height n using a recursive algorithm
	input: integers n 
	output: a right triangle of "*" of height n
	*/
void drawTriangler(int n);
void drawTriangler(int n){
	static int i =1; //counts to n
	if(i==n){
		drawLine(n);
	}else{
		drawLine(i);
		printf("\n");
		i++;
		drawTriangler(n);
	}
		
}

int menu();
int menu(){
int n; //holds the choice
	printf("**INTERATIVE**\n1: fun1\n2: fun2\n3: fibonacci\n4. gcd\n5: power\n6: Display\n7: Draw Triangle\n\n\n**RECURSIVE**\n8: fun1\n9: fun2\n10: fibonacci\n11. gcd\n12: power\n13: Display\n14: Draw Triangle\n");
	scanf("%d",&n);
	return n;
}
int main() { 
	int n; // 1st function variable
	int m; //second function variable
	int choice = menu(); //function selection
	switch(choice){
	case 1: printf("Enter n\n");
			scanf("%d",&n);
			printf("%d",fun1(n));
			break;
	case 2: printf("Enter n\n");
			scanf("%d",&n);
			printf("%d",fun2(n));
			break;
	case 3: printf("Enter n\n");
			scanf("%d",&n);
			printf("%d",fibonacci(n));
			break;
	case 4: printf("Enter x then y\n");
			scanf("%d %d",&n,&m);
			printf("%d",gcd(n,m));
			break;
	case 5: printf("Enter the base then power\n");
			scanf("%d %d",&n,&m);
			printf("%d",Power(n,m));
			break;
	case 6: printf("Enter n then m\n");
			scanf("%d %d",&n,&m);
			display(n,m);
			break;
	case 7: printf("Enter n\n");
			 scanf("%d",&n);
			 drawTriangle(n); 
			break;
	case 8: printf("Enter n\n");
			scanf("%d",&n);
			printf("%d",fun1r(n));
			break;
	case 9: printf("Enter n\n");
			scanf("%d",&n);
			printf("%d",fun2r(n));
			break;
	case 10:printf("Enter n\n");
			scanf("%d",&n);
			printf("%d",fibonaccir(n));
			break;
	case 11: printf("Enter x then y\n");
			 scanf("%d %d",&n,&m);
			 printf("%d",gcdr(n,m));
			 break;
	case 12: printf("Enter the base then power\n");
			 scanf("%d %d",&n,&m);
			 printf("%d",Powerr(n,m));
			 break;
	case 13: printf("Enter n then m\n");
			 scanf("%d %d",&n,&m);
			 displayr(n,m);
			 printf("%d",m);
			 break;
	case 14: printf("Enter n\n");
			 scanf("%d",&n);
			 drawTriangler(n); 
			 break;
	default: printf("INVALID"); break;
	}
	return 0;  
}