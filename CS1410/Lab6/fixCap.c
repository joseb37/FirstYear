#include <stdio.h>
#include <ctype.h>
  struct employee { 
    char firstname[40]; 
    char lastname[40]; int id;    
 }; typedef struct employee Employee; 

int main(void){
	FILE *fp;
	Employee e[3];
	fp = fopen("employee.txt","r");
	for(int i=0;i<3;i++){
		fscanf(fp,"%d %s %s\n",&e[i].id,e[i].firstname,e[i].lastname);
	}
	fclose(fp);
	
	for(int i =0; i < 3;i++){
		e[i].firstname[0] =toupper(e[i].firstname[0]);
		e[i].lastname[0] =toupper(e[i].lastname[0]);
	}
	fp = fopen("employee.txt","w");
	for(int i=0;i<3;i++){
		fprintf(fp,"%d %s %s\n",e[i].id,e[i].firstname,e[i].lastname);
	}
	fclose(fp);
	return 0;
}