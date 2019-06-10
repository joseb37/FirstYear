#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define WORD_SIZE 31
/*Defintion of struct word
  used to store a single word*/
struct word{
	unsigned int length;
	char value[WORD_SIZE];
};
//create a "Word" data type alias for "struct word"
typedef struct word Word;

/*reads word from user and stores it in given loctaion
input pointer to the word
populate word and return pointer*/

Word* ReadWord(Word *ptrWord){
	printf("ReadWord: ");
	scanf("%s",ptrWord->value);
	ptrWord-> length = strlen(ptrWord->value);
	return ptrWord;
}


int main(){
	Word w;
	ReadWord(&w);
	printf("The word is %s \n", w.value);
	return 0;
}