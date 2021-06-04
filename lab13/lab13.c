#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



typedef struct country_s{
    char *country_name;
    char *capital_name;
    int population;
    bool driving_side;
} Country;

typedef struct country_ll_s{
    Country *country;
    struct country_ll_s *next;
} CountryLL;

//creates blank country
Country * CreateBlankCountry(){
    Country * newCountry = (Country *) malloc(sizeof(Country));

    newCountry->country_name = NULL;
    newCountry->capital_name = NULL;
    newCountry->population = 0;
    newCountry->driving_side = false;
    
    return newCountry;
}


//creates country
Country * CreateCountry(char *coName, char *caName, int pop, bool ds){
    Country * newCountry = (Country *) malloc(sizeof(Country));

    newCountry->country_name = (char *) calloc(strlen(coName) + 1, sizeof(char));
    strcpy(newCountry->country_name, coName);

    newCountry->capital_name = (char *) calloc(strlen(caName) + 1, sizeof(char));
    strcpy(newCountry->capital_name, caName);

    newCountry->population = pop;
    newCountry->driving_side = ds;
    
    return newCountry;
}

//adds country to linked list
void AddCountryLL(CountryLL **head, Country *added){
    if(*head == NULL){
	*head = (CountryLL *) malloc(sizeof(CountryLL));
	(*head)->country = added;
	(*head)->next = NULL;
	return;
    }

    CountryLL *currNode = *head;

    while(currNode->next != NULL)
	currNode = currNode->next;

    currNode->next = (CountryLL *) malloc(sizeof(CountryLL));
    currNode->next->country = added;
    currNode->next->next = NULL;
    
}

//resizes given country array 
void ResizeCountryPointerArray(Country ***pointerArrayPointer, int size, int newSize){
    if(newSize == size)
	return;

    Country **newPointerArray = (Country **) calloc(newSize, sizeof(Country *));
    Country **oldPointerArray = *pointerArrayPointer;

    if(newSize > size){
	for(int i = 0; i < size; ++i)
	    newPointerArray[i] = oldPointerArray[i];
    }
    else if(size > newSize){
	for(int i = 0; i < newSize; ++i)
	    newPointerArray[i] = oldPointerArray[i];
	for(int i = newSize; i < size; ++i)
	    free(oldPointerArray[i]);
    }
	
    free(oldPointerArray);
    *pointerArrayPointer = newPointerArray;
}

//adds given country to given country array
void AddCountryToArray(Country ***pointerArrayPointer, int size, Country *added){
    ResizeCountryPointerArray(pointerArrayPointer, size, size + 1);
    (*pointerArrayPointer)[size] = added;
}

//writes array to "lab13.txt"
void WriteToFile(Country **countryPointerArray, int size){
    FILE *f = fopen("lab13.txt", "w");

    for(int i = 0; i < size; ++i){
	fprintf(f, "%s %s %d %s\n", countryPointerArray[i]->country_name,countryPointerArray[i]->capital_name,countryPointerArray[i]->population,countryPointerArray[i]->driving_side ? "Right" : "Left");

    }
    fclose(f);
}

//reads from "lab13.txt" to linkedlist
void ReadFromFile(CountryLL **head){
    FILE *f = fopen("lab13.txt", "r");

    char coName[30];
    char caName[30];
    char ds[30];
    int pop; bool real_ds;

    char line[100];
    while(fgets(line, 100, f)){
	sscanf(line, "%s %s %d %s", coName, caName, &pop, ds);
	real_ds = (ds[0] == 'R');
	Country *readCountry = CreateCountry(coName, caName, pop, real_ds);
	AddCountryLL(head, readCountry);	
    }

    fclose(f);
}
    
int main(){
    Country **countryPointerArray = NULL;
    int size = 0;

    CountryLL *head = NULL;
    
    CountryLL *currNode;
    int printN;

    int userInput = 0;

    //user country input variables
    char coName[30];
    char caName[30];
    int pop;
    int ds;

    while(userInput != 5){
	printf("1: Enter new record\n");
	printf("2: Write to file\n");
	printf("3: Read from the file\n");
	printf("4: Print the linked list\n");
	printf("5: Exit\n");
	
	printf("Your choice: ");
	scanf("%d", &userInput);
	printf("\n\n\n");

	switch(userInput){
	    case 1:
		printf("Country name: "); scanf("%s", coName);
		printf("Capital name: "); scanf("%s", caName);
		printf("Population of %s: ", coName); scanf("%d", &pop);
		printf("Do people in %s drive on the right side? (Yes:1, No:0) : ", coName); scanf("%d", &ds);
		Country *newCountry = CreateCountry(coName, caName, pop, ds);	    // create country with given info
		AddCountryToArray(&countryPointerArray, size, newCountry); ++size;  // add to array
		break;
	    case 2:
		WriteToFile(countryPointerArray, size);
		break;
	    case 3:
		ReadFromFile(&head);
		break;
	    case 4:
		currNode = head;
		while(currNode != NULL){
		    printN = printf("Country: %s", currNode->country->country_name);
		    printf("%*c", 20 - printN, ' ');
		    printN = printf("Capital: %s", currNode->country->capital_name);
		    printf("%*c", 20 - printN, ' ');
		    printN = printf("Population: %d", currNode->country->population);
		    printf("%*c", 20 - printN, ' ');
		    printN = printf("Drive side: %s", currNode->country->driving_side ? "Right" : "Left");
		    printf("\n");
		    currNode = currNode->next;
		}
		break;
	    case 5:
		break;
	    default:
		printf("TRY AGAIN!\n");
	}

	printf("\n\n\n");
    }
    
    return 0;
}
