#include <stdio.h>
    struct employee { 
    char firstname[40]; 
    char lastname[40]; int id;    
 }; typedef struct employee Employee; 
   
   
/* Input the employee data interactively from the keyboard */
void InputEmployeeRecord(Employee *ptrEmp); 
void InputEmployeeRecord(Employee *ptrEmp){
	printf("Enter the Employees name <first> <last>: ");
	scanf("%s %s",ptrEmp->firstname,ptrEmp->lastname);
	printf("Enter the employees ID: ");
	scanf("%d",&ptrEmp->id);
}
   
/* Display the contents of a given Employee record*/
void PrintEmployeeRecord(Employee *e); 
void PrintEmployeeRecord(Employee *e){
	printf("ID: %d\tName: %s %s\n",e->id,e->firstname,e->lastname);
}	
/* Save the contents of the employee record list to the newly created text file specified by FileName */ 
void SaveEmployeeRecord(Employee e[], const char *FileName); 
void SaveEmployeeRecord(Employee e[], const char *FileName){
	FILE *fp;
	fp = fopen(FileName,"w");
	for(int i=0;i<3;i++){
		fprintf(fp,"%d %s %s\n",e[i].id,e[i].firstname,e[i].lastname);
	}
	fclose(fp);
}
   
int main() { 
	Employee e1[3];
	for(int i = 0;i<3;i++){
		InputEmployeeRecord(&e1[i]); 
		PrintEmployeeRecord(&e1[i]);
	}
	SaveEmployeeRecord(e1, "employee.txt");   
	return 0;
} 