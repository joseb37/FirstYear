/*Matthew Belanger
	LabTest 2
	March 20 2019
	105016182
	cs141
*/

#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct WordText{
	char text[MAX];
	int weight;
}Word;
/*this function will count unique characters in a string
input: a string 
output: the number of unique characters*/
int GetStringWeight(char *pStr ){
	int weight = strlen(pStr);
	char cpy[weight+1];
	strcpy(cpy,pStr);
	for(int i =0 ; cpy[i]!='\0';i++){
		if(cpy[i+1]=='0'){continue;}		
		for(int j = i+1;cpy[j]!='\0';j++){
			if(cpy[i] == cpy[j]){
				cpy[j] = '0';
				weight--;			
			}	
		}
	}
	return weight;
}
/*this function will sort Word by their weight
input: an array of Words and the size of the array
output: n/a*/
void SortWordsByWeight(Word wordList[], int size){
	Word temp;
	for(int i=0;i<size;i++){
		wordList[i].weight=GetStringWeight(wordList[i].text);	
	}	
	for(int i = 0; i<size-1;i++){
		if(wordList[i].weight>wordList[i+1].weight){ //swaps elements that are not in acesending order
			temp = wordList[i+1];
			wordList[i+1] = wordList[i];
			wordList[i] = temp;
			i=-1;//resets the for loop
		}	
	}
}

void PrintWordList(Word wordList[], int size){
	for(int i=0;i<size;i++){
		printf("text = %s, \tweight=%d\n",wordList[i].text ,wordList[i].weight);
	}
}
int main(){
	Word wordList[5] = { {"egg",0},{"apple",0},{"cat",0},{"banana",0}, {"watermelon",0}};		
	SortWordsByWeight(wordList,5);
	PrintWordList(wordList,5);
}
