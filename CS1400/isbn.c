 /*Matthew Belanger
   Check Number calculator
   This program will take 12 isbn numbers and output the 13th
   2018-10-16*/
 
 #include <stdio.h>
 int main(void){
	int d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12;
	printf("Enter the isbn number");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&d1,&d2,&d3,&d4,&d5,&d6,&d7,&d8,&d9,&d10,&d11,&d12);
	printf("The check number is: %d ",10-((3*(d2+d4+d6+d8+d10+d12)+(d1+d3+d5+d7+d9+d11))%10));
 return 0; 
 }