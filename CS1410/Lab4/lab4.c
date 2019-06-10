#include <stdio.h>
#include <string.h>
/*This function will reverse a string in memory
it takes a pointer that points to the first char in the string
it return nothing*/ 
void RecursiveReverse(char *buffer);
void RecursiveReverse(char *buffer){
	int len = strlen(buffer);
	char temp;
	static int i = 0;
	if(i !=len/2){
		temp = *(buffer + len-1-i);
		*(buffer + len-1-i) = *(buffer+i);
		*(buffer+i) = temp;
		i++;
		RecursiveReverse(buffer);
		
	}
}
/*This function will reverse a string in memory
it takes a pointer that points to the first char in the string
it return nothing*/ 
void Reverse(char *buffer);
void Reverse(char *buffer){
	int len= strlen(buffer);
	char temp;
	int i;
	for(i = 0;i<len/2;i++){
		temp = *(buffer + len-1-i);
		*(buffer + len-1-i) = *(buffer+i);
		*(buffer+i) = temp;
	}
}

int main(){
	char buffer1[]={'t','h','i','s',' ','i','s',' ','t','h','e',' ','f','i','r','s','t',' ','b','u','f','f','e','r','.','\0'};
	char buffer2[]="this is the second buffer.";
	char buffer3[80];
	char *pbuffer = buffer3;
	printf("Enter a phrase <80 characters\n");
	scanf("%[^\n]s",buffer3);
	printf("%s\n",buffer1);
	printf("%s\n",buffer2);
	printf("%s\n",buffer3);
	while(*pbuffer != '\0'){
		printf("%c", *pbuffer);
		pbuffer++;
	}
	Reverse(buffer3);
	printf("\n%s",buffer3);
	RecursiveReverse(buffer3);
	printf("\n%s\n",buffer3);
	return 0;
}