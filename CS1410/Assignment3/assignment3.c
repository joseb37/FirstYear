#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

struct event{
	int hour;
	int minute;
	char des[41];
}; typedef struct event Event;


//prototypes
int InputRange(int min, int max);
Event* InputEvent(Event *newEvent);
int DeleteEvent(Event list[], int i, int *p_size);
void DisplayEventList(Event list[], int size);
void DisplayEvent(Event e);
int InsertionSortEvent(Event list[], int *p_size, Event e);
char* encode(char* s);
char* decode(char* s);
int SaveEventList(char *filename,Event list[],int size);
int LoadEventList(char *filename,Event list[],int *p_size);

int LoadEventList(char *filename,Event list[],int *p_size){
	FILE *fp = fopen(filename,"r");
	if(fp==NULL){
		printf("FILE NOT FOUND\n");
		return -1;
	}
	int i;
	for(i=0;!feof(fp);i++){
		fscanf(fp,"%d %d %s\n",&list[i].hour,&list[i].minute,list[i].des);
	}
	for(int j =i;j<*p_size;j++){
		DeleteEvent(list,j,p_size);
	}
	*p_size=i;
	printf("FILE LOADED\n");
	return i;
}

char* decode(char* s){
	for(int i=0;s[i]!='\0';i++){
		if(s[i]=='_'){
			s[i]=' ';
		}
	}
	return s;
}

/*this function will take a string and replace spaces with "_"
input: a char pointer
output: returns a pointer to the character*/
char* encode(char* s){
	for(int i=0;s[i]!='\0';i++){
		if(s[i]==' '){
			s[i]='_';
		}
	}
	return s;
}


/*this function will insert an event into a sorted array
input: the list the size and the event to be inserted
output: the index where the element was sorted
assumes the list is already sorted*/
int InsertionSortEvent(Event list[], int *p_size, Event e){
	*p_size = *p_size + 1;
	Event temp;
	int insertIndex;
	if(*p_size == 1){
		list[0] = e;
		return 0;
	}
	for(int i = (*p_size)-1;i>0;i--){//loops through the event list
		
		if(e.hour==list[i-1].hour){//checks of two events hours are the same 
			if(e.minute>=list[i-1].minute){//if hours are = then checks minutes
				insertIndex = i;
				while(i<=*p_size-1){//moves every element forward
					temp = list[i];
					list[i] = e;
					e = temp;
					i++;
				}
				break;
			}else if(e.minute<list[0].minute){	//inserts e into the first element if it is the earliest event
				insertIndex = 0;
				i = 0;
				while(i<*p_size){	//moves every element after the insert forward
					temp = list[i];
					list[i] = e;
					e = temp;
					i++;
				}
				break;
			}
		}else if(e.hour>list[i-1].hour){	//checks if the hour of the insert is bigger than the element before it
			insertIndex = i;
			while(i<*p_size){	//moves every element after the insert forward
				temp = list[i];
				list[i] = e;
				e = temp;
				i++;
			}
			break;
		}else if(e.hour<list[0].hour){//inserts e into the first element if it is the earliest event
			insertIndex = 0;
			i = 0;
			while(i<*p_size){	//moves every element after the insert forward
				temp = list[i];
				list[i] = e;
				e = temp;
				i++;
			}
			break;
		}
	}
	return insertIndex;
}

/*this function will display the time and description of an event
input: the event
output: prints the event*/
void DisplayEvent(Event e){
	printf("%02d:%02d %s\n",e.hour,e.minute,e.des);
}

/*this function will print a list of events
input: the list and the size of it
output: prints the list*/
void DisplayEventList(Event list[], int size){
	for(int i = 0; i<size;i++){
		printf("\n[%d] ",i);
		DisplayEvent(list[i]);
	}
}

/*this function will delet an event from an event list
input: the the list the index of the element to be deleted and the size of list
output: returns the index of the deleted element*/
int DeleteEvent(Event list[], int i, int *p_size){
	int j = i;
	if(i==-1){
		printf("DELETION TERMINATED\n");
		return -1;
	}
	while(j<*p_size){
		list[j] = list[j+1];
		j++;
	}
	list[*p_size-1].hour =0;
	list[*p_size-1].minute = 0;
	strcpy(list[*p_size-1].des,"\0");
	*p_size = *p_size-1;
	return i;
}

/*This function will populate an Event structure with the time and description
input: a pointer to the event
output: the same pointer */
Event* InputEvent(Event *newEvent){
	if(newEvent==NULL){
		printf("error: null pointer");
		return NULL;
	}
	printf("Please enter the hour of the event: ");
	newEvent->hour = InputRange(0,23);
	printf("Please enter the minute of the event: ");
	newEvent->minute = InputRange(0,59);
	getchar();
	printf("Enter an event description: ");
	scanf("%[^\n]s", newEvent->des);
	
	return newEvent;
}

/*this function will prompt the user to enter a number. will return the integer if it is within the range
input: the lower and upper bound of the range
output: an intger within the range*/ 

int InputRange(int min, int max){
	int num;
	while(1){	
		scanf("%d",&num);
		if(num<=max && num>=min){
			break;
		}else{
			printf("INVALID INPUT\n");
		}
	}
	return num;
}	
 
int main(void){
	FILE *fp;
	char choice;
	int save;
	int eventListSize=0;
	char* saveFile[]={"EventList1.txt","EventList2.txt","EventList3.txt","EventList4.txt","EventList5.txt","EventList6.txt","EventList7.txt"};
	Event list[MAX];
	Event insert;
	while(eventListSize<=MAX){
		printf("__= Scheduler v1.0 =__\n  1. Schedule an event.\n  2. Delete an event.\n  3. Display schedule.\n  4. Save schedule.\n  5. Load schedule.\n  6. Exit\n==> Please enter an integer between 1 and 6: ");
		switch(InputRange(1, 6)){
			
			case 1: //add event
			
				InputEvent(&insert); 
				InsertionSortEvent(list, &eventListSize, insert);
				break;
			
			case 2: //delete event
			
				if(eventListSize==0){
					printf("\nYou need to add an event first\n\n");
					break;
				}
				printf("What element are you deleting? (enter -1 to cancel) ");
				DeleteEvent(list, InputRange(-1,MAX-1), &eventListSize);
				break;
			
			case 3://print list
			
				if(eventListSize==0){
					printf("\nYou need to add an event first\n\n");
					break;
				}
				for(int i=0;i<eventListSize;i++){
					decode(list[i].des);
				}
				DisplayEventList(list, eventListSize);
				break;
				
			case 4: //save the list to a text file
				for(int i=0;i<eventListSize;i++){
					encode(list[i].des);
				}
				printf("Which save file will you like to save this Event List to (1-7): ");
				save = InputRange(1,7)-1;
				fp = fopen(saveFile[save],"r");
				if(fp==NULL){
					fclose(fp);
					printf("No save file exists would you like to create one (y/n): ");
					scanf("\n");
					scanf("%c",&choice);
					if(choice=='n'){
						printf("Save terminated\n");
						for(int i=0;i<eventListSize;i++){
							decode(list[i].des);
						}
						break;
					}
				}else{
					printf("That save file already exists would you like to overwrite?(y/n): ");
					scanf("\n");
					scanf("%c",&choice);
					if(choice=='n'){
						printf("Save terminated\n");
						for(int i=0;i<eventListSize;i++){
							decode(list[i].des);
						}
						break;
					}
				}
				fp = fopen(saveFile[save],"w");
				for(int i=0; i<eventListSize ;i++){
					fprintf(fp,"%d %d %s\n",list[i].hour,list[i].minute,list[i].des);
				}
				printf("\nSaved to EventList%d.txt\n",save+1);
				fclose(fp);
				
				for(int i=0;i<eventListSize;i++){
					decode(list[i].des);
				}
				break;
			case 5:
				printf("which file would you like to load(1-7): ");
				LoadEventList(saveFile[InputRange(1,7)-1],list,&eventListSize);
				break;
			case 6:
				printf("Thank You!");
				exit(0);
		}//switch
	}//while
	return 0;
}