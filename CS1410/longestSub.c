#include <stdio.h>
#include <string.h>
int isUnique(int start,int end, char* string);
int longestSub(char* s){
	int longest = 0;
	int tempLong = 1;
	for(int i = 0;s[i]!='\0';i++){
		for(int j = i+1;s[j]!='\0';j++){
			if(isUnique(i,j,s)){
				tempLong++;
			}else{
				break;
			}
		}
		if(tempLong>=longest){
			longest = tempLong;
		}
		tempLong=1;
	}
	return longest;
}

int isUnique(int start,int end, char* s){
	for(int i = start;i<end;i++){
		if(s[i] == s[end]){
			return 0;
		}
	}
	return 1;
}

int main(void){
	char * s ="abcabcba";
	printf("%d\n",longestSub(s));
}