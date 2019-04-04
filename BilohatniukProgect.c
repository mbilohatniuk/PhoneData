#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


#define FILE_NAME "phoneResours.txt"
#define RESULT_FILE "ProgramResult.txt"


typedef struct {
	char brand[20];
	char name[20];
	float display;
	float expansion;
	float processor;
	float accumulation;
	float mainCamera;
	float frontCamera;
	float battery;
	float weight;
}Phone;

void finishMenu ();
void addPhone ();
void removePhone ();
void compare (Phone InformationForCompare);
void funcToLower(char array[]);
int enteredDataModel(char enteredArray[]);
int wordComparison (char array1[], char array2[]);
int enteredDataBrand(char enteredArray[]);
int correctEnteredData(char enteredData[], float dataStruct[]);
void selectMenu();
void printPhone(int index, Phone phones[]);
void func_showAll();
int isNumber (char array[]);
void administrativeInterface();
void userInterface();
void mainMenu();
Phone* fillArray();		

char userValueBrand[30] = "0", userValueName[30] = "0", userValue[30];

int userValueDisplayInt = 0, userValueExpansionInt = 0,
	userValueProcessorInt = 0, userValueAccumulationInt = 0,userValueMainCameraInt = 0, 
	userValueFrontCameraInt = 0, userValueBatteryInt = 0, userValueWeightInt =0;
	    
Phone *phones;
int arraySize = 0;

int main() {
    phones = fillArray(&arraySize);
	mainMenu();
    return 0;
}

Phone* fillArray() {
	FILE* openResourceFile = fopen(FILE_NAME,"r");
    Phone *phones = (Phone*)malloc(1*sizeof(Phone));
    int i = 0;
    while(fscanf(openResourceFile,"%s%s%f%f%f%f%f%f%f%f",
		phones[i].brand,
		phones[i].name,
	    &phones[i].display,
		&phones[i].expansion,
		&phones[i].processor,
	    &phones[i].accumulation,
		&phones[i].mainCamera,
		&phones[i].frontCamera,
	    &phones[i].battery,
		&phones[i].weight)!= EOF) 
		{
	        phones = (Phone*)realloc(phones,(++i+1)*sizeof(Phone));
	        arraySize += 1;
	    }
        fclose(openResourceFile);
        return phones;
}

void userInterface(){
	char choice;
	int userChoice;
	do {	
		printf ("1: Look at all the phones\n");
		printf ("2: Select menu\n");
		printf("ESC: Close program\n");
		printf("\nEnter your selection:");
		
		choice = getch();
		system("cls");
		
		if(choice == 27){
        	return;
		}
        
	} while(!strchr ("120", choice));
	sscanf(&choice, "%i", &userChoice);
		
 	   switch(userChoice) {
			case 1: 
				system("cls");
		    	func_showAll(phones,arraySize);
		    	break;
			case 2: 
				system("cls"); 
		    	selectMenu();
		    	break;
			case 0:
				mainMenu();
				break;
		default:
	printf("You entered incorrect data,please enter again\n");
	}
}

void selectMenu() {	
	int userChoice;
	char choice;
	
	do {	
		printf("1.Phone brand:"); 				    if(strcmp(userValueBrand,"0") != 0) {printf("----SELECTED----");}
		printf("\n2.Phone model:");					if(strcmp(userValueName,"0") != 0) {printf("----SELECTED----");}
		printf("\n3.Display size(inch):"); 					if(userValueDisplayInt != 0){printf("----SELECTED----");}
		printf("\n4.phone Expansion(vertically):");			if(userValueExpansionInt != 0){printf("----SELECTED----");}
		printf("\n5.Processor(Ggc):");        				if(userValueProcessorInt != 0){printf("----SELECTED----");}
		printf("\n6.Accumulation(Gb):");					if(userValueAccumulationInt != 0){printf("----SELECTED----");}	
		printf("\n7.Main camera(MP):");          			if(userValueMainCameraInt != 0){printf("----SELECTED----");}
		printf("\n8.Front camera(MP):");					if(userValueFrontCameraInt != 0){printf("----SELECTED----");}
		printf("\n9.Battery(mAh):");						if(userValueBatteryInt != 0){printf("----SELECTED----");}			
		printf("\n0.Weight(gramm):");						if(userValueWeightInt != 0){printf("----SELECTED----");}
		printf("\nESC: Close program\n");
		printf("\nS: View phone (s) with selected characteristics\n");	                    
		
		
		choice = getch();
		
		if(choice == 27){
        	return;
		}else if(choice == 's' || choice == 'S') {
		    Phone InformationForCompare;
		    strcpy(InformationForCompare.brand,userValueBrand);
		    strcpy(InformationForCompare.name,userValueName);
		    InformationForCompare.display = userValueDisplayInt;
		    InformationForCompare.expansion = userValueExpansionInt;
		    InformationForCompare.processor = userValueProcessorInt;
		    InformationForCompare.accumulation = userValueAccumulationInt;
		    InformationForCompare.mainCamera = userValueMainCameraInt;
		    InformationForCompare.frontCamera = userValueFrontCameraInt;
		    InformationForCompare.battery = userValueBatteryInt;
		    InformationForCompare.weight = userValueWeightInt;
		    
		    system("cls");
		    compare(InformationForCompare);
		    return;
		}

        system("cls");
        
	} while(!strchr ("0123456789", choice));
			sscanf(&choice, "%i", &userChoice);
			
		float dataFromStruct[arraySize];
	    int i;
			
	switch(userChoice) {
		case 1: enteredDataBrand(userValueBrand); 
		        break;
		        
		case 2: enteredDataModel(userValueName);
		        break;
		        
		case 3: for(i = 0; i < arraySize; i++) {
  	                dataFromStruct[i] = phones[i].display;
                }
		        userValueDisplayInt = correctEnteredData(userValue,dataFromStruct);
		        system("cls");
		        selectMenu(phones,arraySize);
				break;
		        
		case 4: for(i = 0; i < arraySize; i++) {
  	                dataFromStruct[i] = phones[i].expansion;
                }
		        userValueExpansionInt = correctEnteredData(userValue,dataFromStruct);
		        system("cls");
		        selectMenu();
		        break;
		        
		case 5:  for(i = 0; i < arraySize; i++) {
  	                dataFromStruct[i] = phones[i].processor;
                }
		        userValueProcessorInt = correctEnteredData(userValue,dataFromStruct);
		        system("cls");
		        selectMenu();
		        break;
		        
		case 6:  for(i = 0; i < arraySize; i++) {
  	                dataFromStruct[i] = phones[i].accumulation;
                }
		        userValueAccumulationInt = correctEnteredData(userValue,dataFromStruct);
		        system("cls");
		        selectMenu();
		        break;
		case 7:  for(i = 0; i < arraySize; i++) {
  	                dataFromStruct[i] = phones[i].mainCamera;
                }
		        userValueMainCameraInt = correctEnteredData(userValue,dataFromStruct);
		        system("cls");
		        selectMenu();
		        break;
		        
		case 8:  for(i = 0; i < arraySize; i++) {
  	                dataFromStruct[i] = phones[i].frontCamera;
                }
		        userValueFrontCameraInt = correctEnteredData(userValue,dataFromStruct);
		        system("cls");
		        selectMenu();
		        break;
		        
		case 9:  for(i = 0; i < arraySize; i++) {
  	                dataFromStruct[i] = phones[i].battery;
                }
		        userValueBatteryInt = correctEnteredData(userValue,dataFromStruct);
		        system("cls");
		        selectMenu();
		        break;
		        
		case 0:  for(i = 0; i < arraySize; i++) {
  	                dataFromStruct[i] = phones[i].weight;
                }
		        userValueWeightInt = correctEnteredData(userValue,dataFromStruct);
		        system("cls");
		        selectMenu();
		        break;
	}		
}

void printPhone(int index, Phone phones[]) {
	printf("Phone brand: %s\nPhone model: %s\nDisplay size: %g\nExpansion: %g\nProcessor: %g\nAccumulation: %g\nMain camera: %g\nFront camera: %g\nBattarey: %g\nWeight: %g\n",
	phones[index].brand,phones[index].name,phones[index].display,phones[index].expansion,
	phones[index].processor,phones[index].accumulation,phones[index].mainCamera,phones[index].frontCamera,
	phones[index].battery,phones[index].weight);
	printf("\n");
}


int isNumber (char array[]) {
	int i;
	for(i = 0; i < strlen(array); i++) {
		if(array[i] >= '0' && array[i] <= '9'){
			continue;
		}else {
			return 1;
		}
	}
	return 0;
}

void func_showAll(Phone array[], int sizeArray) {
	int i;
	char choice;
	int userChoice;
	
    do {	
		printf ("1: Look at all the phones(console)\n");
		printf ("2: Print all phones is file(ProgramResult.txt)\n");
		printf ("3: Back to the main menu\n");
		printf("ESC: Close program\n");
		printf("\nEnter your selection: ");
		choice = getch();
		system("cls");
		if(choice == 27){
        	return;
		}
		
	} while(!strchr ("123", choice));
	
	    sscanf(&choice, "%i", &userChoice);	
		
	switch(userChoice) {
		case 1: 
		    for(i = 0; i < sizeArray; i++) {
		    	printPhone(i,array);
			}
			finishMenu ();
		    return;
		case 2: ;
			FILE* FillFile = fopen(RESULT_FILE,"w");
			for(i = 0; i < sizeArray; i++) {
		    	fprintf(FillFile,"Telephone brand: %s\nTelephone brand: %s\nDisplay size: %g\nExpansion: %g\nProcessor: %g\nAccumulation: %g\nMain camera: %g\nFront camera: %g\nBattarey: %g\nWeight: %g\n\n",
	            array[i].brand,
				array[i].name,
				array[i].display,
				array[i].expansion,
	            array[i].processor,
				array[i].accumulation,
				array[i].mainCamera,
				array[i].frontCamera,
	            array[i].battery,
				array[i].weight);
			}
			fclose(FillFile);
   			printf("Your information has been successfully written to a file.\n");
   			sleep(2);
   			system("cls");
   			finishMenu ();
		    return;
		case 3:
			system("cls");
			mainMenu();
		    break;
	    default:
	    	printf("You entered incorrect data,please enter again\n");
	    }
	}

int correctEnteredData(char enteredData[], float dataStruct[]) {
	int flag = 1;
	int result;
	float maxCharacteristic = dataStruct[0];
	float minCharacteristic = dataStruct[0];
	
	    int i;
        for( i = 0; i < arraySize; i++){
            if(dataStruct[i] < maxCharacteristic){
                maxCharacteristic = dataStruct[i];
            }
        }
        
        for( i = 0; i < arraySize; i++){
            if(dataStruct[i] > maxCharacteristic){
                maxCharacteristic = dataStruct[i];
            }
        }
	    
	do{
		printf("Enter a characteristic: (minimum value %g: maximum value: %g)\n\n",minCharacteristic,maxCharacteristic);
		
		scanf("%s",enteredData);
		
		if(isNumber(enteredData) == 1) {
		    printf("Not a Number\n");
	    }else {
		    sscanf(enteredData, "%i", &result);
		    if(result < minCharacteristic || result > maxCharacteristic) {
		    	printf("Incorrect characteristics\n");
			}else {
				return result;
				system("cls");
			}
		    
	    }
	}while(flag == 1);
}


int enteredDataBrand(char enteredArray[]) {
	int i,signal = 1;
	int flag = 1;
	char array[30];
	char zero[] = "0";
	printf("Enter the brand of the phone(Samsung,iPhone,Xiaomi,Meizu):\n");
	printf("\nEnter your selection: ");
	
	do {
		scanf("%s",enteredArray);
		
		if(strcmp(enteredArray,zero) ==0) {
			return 0;
		}
		
		for(i = 0; enteredArray[i]; i++) {
            enteredArray[i] = tolower(enteredArray[i]);
        }
        
        for(i = 0; i < arraySize; i++) {
        	strcpy(array,phones[i].brand);
        	funcToLower(array);
            if(strcmp(enteredArray,array) == 0){
            	signal = 0;
			}else {
				continue;
			}
		}
		
		if (signal == 0) {
			flag = 0;
			system("cls");
			selectMenu();
		}else {
			printf("This phone brand does not exist\n\n");
		}
	}while (flag == 1);       
}

int wordComparison (char array1[], char array2[]) {
	int i;
	char zero[] = "0";
	char testArr1[20];
	char testArr2[20];
	
	if(strcmp(array1,zero) ==0 ) {
			return 0;
		}
	 
	strcpy(testArr1,array1);
	strcpy(testArr2,array2);
	
	funcToLower(testArr1);
	funcToLower(testArr2);
	
	if (strcmp(testArr1,testArr2) == 0){
		return 0;
	}else {
		return 1;
	}
}

int enteredDataModel(char enteredArray[]) {
	int i,signal = 1;
	int flag = 1;
	char array[30];
	char zero[] = "0";
	
	printf("Enter model phone(examples: iphone-7, ihpone-8-plus):\n");
	printf("\nEnter your selection: ");
	
	do {
		scanf("%s",enteredArray);
		
		if(strcmp(enteredArray,zero) ==0) {
			return 0;
		}
		
		for(i = 0; enteredArray[i]; i++) {
            enteredArray[i] = tolower(enteredArray[i]);
        }
        
        for(i = 0; i < arraySize; i++) {
        	strcpy(array,phones[i].name);
        	funcToLower(array);
            if(strcmp(enteredArray,array) == 0){
            	signal = 0;
			}else {
				continue;
			}
		}
		
		if (signal == 0) {
			flag = 0;
			system("cls");
			selectMenu();
		}else {
			printf("This phone model does not exist\n\n");
		}
	}while (flag == 1);       
}

void funcToLower(char array[]) {
	int i;
	for(i = 0; array[i]; i++){
		array[i] = tolower(array[i]);
	}
}

void compare (Phone InformationForCompare) {
	int i,j=0;
	int filteredSizeArray = 0;
	
	Phone *filteredPhones = (Phone*)malloc(1*sizeof(Phone));
	
    for(i = 0 ; i < arraySize; i++){
   	    if(wordComparison(InformationForCompare.brand,phones[i].brand) == 0 && 
		   wordComparison(InformationForCompare.name,phones[i].name) == 0 && 
		    phones[i].display >= InformationForCompare.display && 
			phones[i].expansion >= InformationForCompare.expansion &&
		    phones[i].processor >= InformationForCompare.processor && 
			phones[i].accumulation >= InformationForCompare.accumulation &&
		    phones[i].mainCamera >= InformationForCompare.mainCamera && 
			phones[i].frontCamera >= InformationForCompare.frontCamera &&
		    phones[i].battery >= InformationForCompare.battery && 
			phones[i].weight >= InformationForCompare.weight)
			{	
			    strcpy(filteredPhones[j].brand, phones[i].brand),
				strcpy(filteredPhones[j].name, phones[i].name),
		    	filteredPhones[j].display = phones[i].display, 
				filteredPhones[j].expansion = phones[i].expansion,
		    	filteredPhones[j].processor = phones[i].processor, 
				filteredPhones[j].accumulation = phones[i].accumulation,
		    	filteredPhones[j].mainCamera = phones[i].mainCamera, 
				filteredPhones[j].frontCamera = phones[i].frontCamera,
		    	filteredPhones[j].battery = phones[i].battery, 
				filteredPhones[j].weight = phones[i].weight;
		    	
			    filteredPhones = (Phone*)realloc(filteredPhones,(i+2)*sizeof(Phone));
			    filteredSizeArray++;
			    j++;
		    }
	    }
	    
	     func_showAll(filteredPhones,filteredSizeArray);
}

void addPhone () {
	FILE *fileAddPhone = fopen(FILE_NAME,"a");
	
	char ValueBrand[30], ValueName[30];

	float ValueDisplayInt, ValueExpansionInt,
	ValueProcessorInt, ValueAccumulationInt, ValueMainCameraInt, 
	ValueFrontCameraInt, rValueBatteryInt, ValueWeightInt;
	    
	
	printf("1.Phone brand:");
	scanf("%s",ValueBrand);				   
	printf("\n2.Phone model:");	
	scanf("%s",ValueName);				
	printf("\n3.Display size(inch):");
	scanf("%f",&ValueDisplayInt);				
	printf("\n4.phone Expansion(vertically):");		
	scanf("%f",&ValueExpansionInt);	
	printf("\n5.Processor(Ggc):");    
	scanf("%f",&ValueProcessorInt);	    				
	printf("\n6.Accumulation(Gb):");	
	scanf("%f",&ValueAccumulationInt);						
	printf("\n7.Main camera(MP):");  
	scanf("%f",&ValueMainCameraInt);	        			
	printf("\n8.Front camera(MP):");
	scanf("%f",&ValueFrontCameraInt);						
	printf("\n9.Battery(mAh):");	
	scanf("%f",&rValueBatteryInt);									
	printf("\n0.Weight(gramm):");	
	scanf("%f",&ValueWeightInt);					
	
	fprintf(fileAddPhone,"\n%s %s %g %g %g %g %g %g %g %g",
	ValueBrand,
	ValueName,
	ValueDisplayInt,
	ValueExpansionInt,
	ValueProcessorInt,
	ValueAccumulationInt,
	ValueMainCameraInt,
	ValueFrontCameraInt,
	rValueBatteryInt,
	ValueWeightInt);
	
	fclose(fileAddPhone);
}

void removePhone () {
	int i,signal = 1;
	int flag = 1;
	char array[30];
	int storedIndex;
	char enteredArray[30];
	
	printf("Enter model phone which you whatn remove(examples: iphone-7, ihpone-8-plus):\n");
	printf("\nEnter your selection: ");
	
	do {
		scanf("%s",enteredArray);
		fflush(stdin);

		funcToLower(enteredArray);
        for(i = 0; i < arraySize; i ++) {
        	strcpy(array,phones[i].name);
        	funcToLower(array);
            if(strcmp(enteredArray,array) == 0){
            	storedIndex = i;
            	signal = 0;
            	break;
			}else {
				continue;
		}
	}
	
		
		if (signal == 0) {
			FILE* fileRemuve = fopen(FILE_NAME,"w");
			for(i = 0; i < arraySize; i++) {
				if (i != storedIndex) {
					fprintf(fileRemuve,"%s %s %g %g %g %g %g %g %g %g\n",
			        phones[i].brand,
					phones[i].name,
					phones[i].display,
					phones[i].expansion,
			        phones[i].processor,
					phones[i].accumulation,
					phones[i].mainCamera,
					phones[i].frontCamera,
			        phones[i].battery,
					phones[i].weight);
				}
			}
			
			fclose(fileRemuve);
			return;
		}else {
			
			printf("This phone model does not exist\n\n");
		}
	}while (flag == 1);  
}
void mainMenu() {
	char choice;
	int userChoice;
	do {	
		printf ("1: User Interface :\n");
		printf ("2: Administrative interface:\n");;
		printf("ESC: Close program\n");
		printf("\nEnter your selection: ");
		
		choice = getch();
		system("cls");
		
		if(choice == 27){
        	return;
	    } 
		
	} while(!strchr ("12", choice));
	
	    sscanf(&choice, "%i", &userChoice);
	    
	switch(userChoice) {
		case 1: userInterface(); break;
		case 2: administrativeInterface(); break;
	}	
}

void administrativeInterface() {
	char choice;
	int userChoice;
	do {	
		printf ("1: Add phone :\n");
		printf ("2: Remove phone:\n");
		printf ("3: Main menu:\n");
		printf("ESC: Close program\n");
		printf("\nEnter your selection: ");
		
		choice = getch();
		system("cls");
		
		if(choice == 27){
        	return;
	    } 
		
	} while(!strchr ("123", choice));
	
	    sscanf(&choice, "%i", &userChoice);
	    
	switch(userChoice) {
		case 1: addPhone();
		        return;
		case 2: removePhone();
		        return;
		case 3: system("cls");
		        mainMenu();
		        break;
	}
}

void finishMenu () {
	char choice;
	int userChoice;
	do {	
		printf ("\n1: Main menu :\n");
		printf("ESC: Close program\n");
		printf("\nEnter your selection: ");
		
		choice = getch();
		system("cls");
		
		if(choice == 27){
        	return;
	    } 
		
	} while(!strchr ("12", choice));
	
	    sscanf(&choice, "%i", &userChoice);
	    
	switch(userChoice) {
		case 1: system("cls");
		        mainMenu();
		        break;
	}
}


