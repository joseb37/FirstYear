#include <stdio.h>
#include <stdlib.h>

struct newInt{
	int num;
	struct newInt* ptrNext;
};typedef struct newInt NewInt;

//Globals
NewInt* ptrFirst = NULL;
NewInt* ptrLast = NULL;

//prototypes
void addTo(NewInt* ptrNew);
NewInt* populateInt(NewInt* ptrNew,int num);
NewInt* createInt();
void printInt();
void clearInt();

NewInt* createInt(){
	return (NewInt*)(malloc(sizeof(struct newInt)));
}
NewInt* populateInt(NewInt* ptrNew,int num){
	ptrNew->num = num;
	ptrNew->ptrNext=NULL;
	return ptrNew;
}
void addTo(NewInt* ptrNew){
	if(ptrFirst==NULL){
		ptrFirst = ptrNew;
		ptrLast = ptrNew;
		return;
	}else{
		ptrLast->ptrNext = ptrNew;
		ptrLast = ptrNew;
	}
}
	
void printInt(){
	NewInt* ptrCurrent = ptrFirst;
	while(ptrCurrent != NULL){
		printf("%d\n",ptrCurrent->num);
		ptrCurrent = ptrCurrent->ptrNext;
	}
}
void clearInt(){
	NewInt* ptrClear = ptrFirst;
	while(ptrClear != NULL){
		ptrFirst = ptrFirst->ptrNext;
		free(ptrClear);
		ptrClear = ptrFirst;
	}
	ptrLast = NULL;
}
int main(){
	int num;
	while(1){
		printf("\nEnter a number >0: ");
		scanf("%d",&num);
		if(num>=0){
			addTo(populateInt(createInt(),num));
		}else{
			break;
		}
	}
	printInt();
	clearInt();
	return 0;
}