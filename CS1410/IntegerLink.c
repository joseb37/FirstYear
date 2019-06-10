#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
//self ref structure
struct listint{
	int num;
	struct listint *ptrNext;//self ref pointer
};typedef struct listint ListInt;

//Globals
ListInt* ptrFirst = NULL;
ListInt* ptrLast = NULL;
void addTo(ListInt* newInt);

void insertSort(ListInt* ptrInsert){
	ListInt* ptrCurrent = ptrFirst;
	ListInt* temp;
	if(ptrFirst == NULL){//if the list is empty
		addTo(ptrInsert);
		return;
	}else if(ptrFirst->num > ptrInsert->num){//if the insert belongs at the start
		ptrInsert->ptrNext = ptrFirst;
		ptrFirst = ptrInsert;
		return;
	}
	while(ptrCurrent->ptrNext!=NULL){//finds where insert needs to be inserted
		if(ptrCurrent->ptrNext->num < ptrInsert->num){
			ptrCurrent = ptrCurrent->ptrNext;
		}else{
			temp = ptrCurrent->ptrNext;
			ptrCurrent->ptrNext=ptrInsert;
			ptrInsert->ptrNext = temp;
			return;
		}
	}
	addTo(ptrInsert);//adds to then end if it does not need to be inserted in the middle
}

void clearList(){
	ListInt* delete = ptrFirst;
	while(delete!=NULL){
		ptrFirst = ptrFirst->ptrNext;
		free(delete);
		delete = ptrFirst;
	}
}

ListInt* createInt(){
	return (struct listint*)(malloc(sizeof(struct listint)));
}

ListInt* populateInt(ListInt* newInt,int num2){
	newInt->num = num2;
	return newInt;
}
void addTo(ListInt* newInt){
	if(ptrFirst == NULL){
		ptrFirst = newInt;
		ptrLast = newInt;
	}else{
		ptrLast->ptrNext = newInt;
		ptrLast = newInt;
	}
	newInt->ptrNext=NULL;
}

void printList(ListInt* ptrPrint){
	if(ptrPrint!=NULL){
		printf("\n %d",ptrPrint->num);
		printList(ptrPrint->ptrNext);
	}
}
void printReverse(ListInt* ptrPrint){
	if(ptrPrint!=NULL){
		printReverse(ptrPrint->ptrNext);
		fprintf(stderr,"\n %d",ptrPrint->num);
	}
}

int main(void){
	insertSort(populateInt(createInt(),4));
	insertSort(populateInt(createInt(),3));
	insertSort(populateInt(createInt(),5));
	insertSort(populateInt(createInt(),1));
	
	printList(ptrFirst);
	printf("\n ");n 
	printReverse(ptrFirst);
	//sleep(3);
	clearList();
	return 0;
}