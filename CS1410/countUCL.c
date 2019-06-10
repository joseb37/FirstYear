#include <stdio.h>
#include <ctype.h>
int countUCL(char *s){
	if(s[0]=='\0'){
		return 0;
	}else if(s[0]==toupper(s[0])){
		return countUCL(s+1) +1;
	}else{
		return countUCL(s+1);
	}

}

int main(void){
	printf("%d",countUCL("hELLo"));
}