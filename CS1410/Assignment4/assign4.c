#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//self ref structure
struct event{
	int hour; //hour of the event in 24 hour format
	int minute; //minute of the event
	char des[41]; // a brief description of the event
	struct event* ptrNext; //self ref pointer
}; typedef struct event Event;

//Globals	
Event* ptrFirst = NULL;
Event* ptrLast = NULL;

//Prototypes
void InsertionSortEvent(Event* ptrInsert);
Event* createEvent();
Event* InputEvent(Event *newEvent);
void Print();
void ClearList();
FILE* SortFile(FILE *fp,char* fileName);

//this function will read an event file and sort its contents chronologically
FILE* SortFile(FILE* fp,char* fileName){
	fp = fopen(fileName,"r");
	Event* ptrCurrent;
	while(!feof(fp)){
		ptrCurrent = createEvent();
		fscanf(fp,"%d %d %s\n",&ptrCurrent->hour,&ptrCurrent->minute,ptrCurrent->des);
		InsertionSortEvent(ptrCurrent);
	}
	fclose(fp);
	ptrCurrent = ptrFirst;
	fp = fopen(fileName,"w");
	while(ptrCurrent!=NULL){
		fprintf(fp,"%d %d %s\n",ptrCurrent->hour,ptrCurrent->minute,ptrCurrent->des);
		ptrCurrent = ptrCurrent->ptrNext;
	}
	return fp;
}


//this function will free the allocated memory of a link list
void ClearList(){
	Event* delete = ptrFirst;
	while(delete!=NULL){
		ptrFirst = ptrFirst->ptrNext;
		free(delete);
		delete = ptrFirst;
	}
}

/*this function will print a linked list from a given entry to the end*/
void Print(Event* ptrPrint){
	if(ptrPrint!=NULL){
		printf("\n %d:%d %s",ptrPrint->hour,ptrPrint->minute,ptrPrint->des);
		Print(ptrPrint->ptrNext);
	}
}

//this function will input event details
Event* InputEvent(Event *newEvent){
	printf("Please enter the event information (hh mm \"<description>\")\n");
	scanf("%d",&newEvent->hour);
	scanf("%d",&newEvent->minute);
	scanf("\n%[^\n]s",newEvent->des);
	newEvent->ptrNext = NULL;
	return newEvent;
}

//this function will reserve memory for an event
Event* createEvent(){
	return (Event*)(malloc(sizeof(struct event)));
}

/*this function will insert an event into a sorted array
input: the list the size and the event to be inserted
output: the index where the element was sorted
assumes the list is already sorted*/
void InsertionSortEvent(Event* ptrInsert){
	Event* ptrCurrent = ptrFirst;
	Event* temp;
	if(ptrFirst == NULL){ //if the list is empty
		ptrFirst = ptrInsert;
		ptrLast = ptrInsert;
		return;
	}
	if(ptrFirst->hour == ptrInsert->hour){//if insert belongs at start of list
		if(ptrFirst->minute >= ptrInsert->minute){
			ptrInsert->ptrNext = ptrFirst;
			ptrFirst = ptrInsert;
			return;
		}
	}else if(ptrFirst->hour > ptrInsert->hour){//if insert belongs at start
		ptrInsert->ptrNext = ptrFirst;
		ptrFirst = ptrInsert;
		return;
	}
	while(ptrCurrent->ptrNext!=NULL){//Otherwise finds where insert needs to be inserted
		
		if(ptrCurrent->ptrNext->hour < ptrInsert->hour){//if current is smaller than the insert check the next element
			ptrCurrent = ptrCurrent->ptrNext;
			continue;
			
		}else if(ptrCurrent->ptrNext->hour == ptrInsert->hour){//if the hours are the same check minute
			if(ptrCurrent->ptrNext->minute < ptrInsert->minute){//if current is smaller than the insert check the next element
				ptrCurrent = ptrCurrent->ptrNext;
				continue;
				
			}else{//if the insert >= to current then insert the insert
				temp = ptrCurrent->ptrNext;
				ptrCurrent->ptrNext=ptrInsert;
				ptrInsert->ptrNext = temp;
				return;
			}
		}else{//if the insert >= to current then insert the insert
			temp = ptrCurrent->ptrNext;
			ptrCurrent->ptrNext=ptrInsert;
			ptrInsert->ptrNext = temp;
			return;
		}
	}
	
	//adds insert to the end if its the latest event
	ptrLast->ptrNext = ptrInsert;
	ptrLast = ptrInsert;
	return;
}

int main(void){
	FILE *fp=NULL;
	//Print(ptrFirst);
	SortFile(fp,"mylist.txt");
	//Print(ptrFirst);
	ClearList();
	return 0;
}