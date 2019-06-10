#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
float balance = 0;
float getAmount(){
	float amount;
	scanf("%f",&amount);
	if(amount<0){
		printf("Invalid choice\n");
		getAmount();
	}
	return amount;
}

void initBalance(float amount){
	balance+=amount;
}

int displayMenu(){
	int choice;
	printf("\nCommands: 1=credit, 2=debit,3=balance, 4=exit\n");
	scanf("%d",&choice);
	if(!(choice<4||choice>1)){
		displayMenu();
		printf("INVALID\n");
	}
	return choice;
}

void creditMoney(float credit){
	balance +=credit;
}

bool debitMoney(float debit){
	if(debit<=balance){
		balance -=debit;
		return 1;
	}else{
		printf("Sorry, you don't have enough credit.\n");
		return 0;
	}
}

int countTransaction(){
	static int count=0;
	if(count>=4){
		printf("You cannot have more than five transactions! Bye.");
		exit(0);
		return 0;
	}
	return ++count;
}	

int main(void){
	printf("Enter the initial balance: ");
	initBalance(getAmount());
	while(1){
		switch(displayMenu()){
			case 1: printf("Enter Amount: ");
					creditMoney(getAmount()); 
					countTransaction(); 
					break;
			case 2: printf("Enter Amount: ");
					debitMoney(getAmount());
					countTransaction(); 
					break;
			case 3: printf("%.2f\n",balance); 
					countTransaction();
					break;
			case 4: printf("BYE");
					exit(0);
					break;
		}
	}
	return 0;
}