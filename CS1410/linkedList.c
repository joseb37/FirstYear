#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//define self referencial structure
struct node{
	int id; //a unique id
	char value[10]; //a string of size 9
	struct node* ptrNext; //self ref pointer
};
// globals
struct node* ptrFirst = NULL;
struct node* ptrLast = NULL;

// prototypes
struct node* addToEnd(struct node* ptrNew);
struct node* populateNode(struct node* ptrNew,int id,char* value);
struct node* createNode();
void printList();
void printNode(struct node* ptrCurrent);
void clearList();
void printListReverse();
/*void printListReverse(){
	struct node*ptrCurrent = ptrLast;
	
	struct node* ptrPrevious = NULL;
	while(ptrCurrent!=NULL){
		
	}
}*/

void printNode(struct node* ptrCurrent){
	if(ptrCurrent !=NULL){
		printf("%d %s\n",ptrCurrent->id,ptrCurrent->value);
	}
}

//will print list to the console
void printList(){
	struct node* ptrCurrent = NULL;
	
	ptrCurrent = ptrFirst;
	while(ptrCurrent!=NULL){
		printNode(ptrCurrent);
		ptrCurrent = ptrCurrent->ptrNext;
	}
}

//add a node to the end of the list
struct node* addToEnd(struct node* ptrNew){
	if(ptrFirst == NULL){
		ptrFirst = ptrNew;
		ptrLast = ptrNew;
	}else{
		ptrLast->ptrNext = ptrNew;
		ptrLast = ptrNew;
	}
	return NULL; 
}

//populate node with values
//returns the pointer to the node, or NULL
struct node* populateNode(struct node* ptrNew,int id,char* value){
	if(ptrNew != NULL){
		ptrNew->id=id;
		strcpy(ptrNew->value,value);
		ptrNew->ptrNext = NULL;
	}
	return ptrNew;
}

//creates a new node using malloc
//returns pointer to new node, or NULL
struct node* createNode(){
	return (struct node*)(malloc(sizeof(struct node)));
}

//clears list using free
void clearList(){
	struct node* ptrDelete = NULL;
	while(ptrFirst !=NULL){
		ptrDelete = ptrFirst;
		ptrFirst = ptrFirst->ptrNext;
		free(ptrDelete);
	}
	ptrLast =NULL;
}


int main(void){
	addToEnd(populateNode(createNode(),1,"one"));
	addToEnd(populateNode(createNode(),2,"two"));
	addToEnd(populateNode(createNode(),3,"three"));
	addToEnd(populateNode(createNode(),4,"four"));
	printList();
	
	clearList();
	return 0;
}