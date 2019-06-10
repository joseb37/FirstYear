#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 200
int main(){       
    char fname[31], lname[31];      // store a name       
    char line[MAX];       
    char *p_space;       
    char *p_token;
    printf("Please enter your name: ");
    fgets(line, MAX, stdin);
    // extract first and last names using strchr to find the space        // between them
    p_space = strchr(line, ' ');
    if (p_space == NULL){               
        fprintf(stderr, "no space found!\n");               
        exit(1);       
    }
	/* METHOD 1        
		strncpy(fname, line, p_space - line);
        strcpy(lname, p_space+1); 
	*/
	/* METHOD 2        
		sscanf(line, "%s%s", fname, lname);
	*/
	/* METHOD 3       
		p_token = strtok(line, " .,?;:!'`-");       
		strcpy(fname, p_token);
		p_token = strtok(NULL, " .,?;:!'`-");
		strcpy(lname, p_token);
	*/
	// what if I want to extract the words out of a sentence?
        p_token = strtok(line, " .,");
        while(p_token != NULL){
			puts(p_token);               
            p_token = strtok(NULL, " .,");       
       }
      //puts(fname);
	  //puts(lname);
    return 0;
}