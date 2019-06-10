#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
void printArray(char mat[][MAX], unsigned int size){
	printf("\n");
	for(int i=0;i<size;i++){
		printf("%s\n", mat[i]);
	}
}
void SortArray(char A[][MAX],unsigned int size){
	char temp[MAX];
	for(int i=0;i<size-1;i++){
		if(strcmp(A[i],A[i+1])>0){
			strcpy(temp ,A[i+1]);
			strcpy(A[i+1] ,A[i]);
			strcpy(A[i] ,temp);
			i=-1;
		}
	}
}
void ParseSentence(char* word){llo
	char* wordToken;
	char words[MAX][MAX];
	wordToken =strtok(word," .;,\n");
	strcpy(words[0],wordToken);
	int j;
	for(j =1;;j++){
		wordToken = strtok(NULL," .;,\n");
		if(wordToken == NULL){break;}
		strcpy(words[j],wordToken);
	}
	SortArray(words,j);
	printArray(words,j);
}
int main(void){
	char string[MAX];
	printf("Enter a phrase <100 characters\n");
	fgets(string,MAX,stdin);
	ParseSentence(string);
	return 0;
}