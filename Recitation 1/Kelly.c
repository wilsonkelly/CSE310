//Wilson Kelly
//CSE310
//Reciation - Linked Lists


//These aren't necessary, just help run on different systems
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996) // for Visual Studio

#define MAX_NAME_LENGTH 30
#define MAX_CITIES 20

struct cityInfo {   //struct for linked list
    char name[MAX_NAME_LENGTH];
    unsigned int pop;
    unsigned int income;
    struct cityInfo* next;
}*list = NULL;

int count = 0;  //used for checks later

// Function declaration
void flushStdIn();
void executeAction(char);
int add(
    char* name_input,
    unsigned int pop_input,
    unsigned int income_input);		
void display();
void maxPop();

// Run starts here
int main()
{
    // This section asks for the user input, and goes to the corresponding function
    char choice = '0'; //placeholder character
    do
    { 
        printf("\t 1: Add city record at the tail\n");
        printf("\t 2: Add city record at the head.\n");
        printf("\t 3: Display the city with largest population.\n");
        printf("\t 4: Display all the city records.\n");
        printf("\t 5: Exit\n");
        choice = getchar();
        flushStdIn();
        //goes to function
        executeAction(choice);
    } while (choice != '5'); //5 = exit
    return 0;
}

void flushStdIn() //This is used to clean up the extra '\n' characters for input
{
    char c;
    do c = getchar();
    while (c != '\n' && c != EOF);
}

// This section goes to functions based on the users input
void executeAction(char c)
{
    char name_input[MAX_NAME_LENGTH];
    unsigned int pop_input, income_input, add_result = 0;
    
    switch (c)
    {
        case '1': //Add city record at the tail.
            // input city record from user
            printf("\nEnter city name: ");
            fgets(name_input, sizeof(name_input), stdin);
            name_input[strlen(name_input) - 1] = '\0';

            printf("Please enter city population: ");
            scanf("%d", &pop_input);
            flushStdIn();

            printf("Please enter maiden household income: ");
            scanf("%d", &income_input);
            flushStdIn();

            // add the city to the list
            add_result = addTail(name_input, pop_input, income_input);
            if (add_result == 0)
                printf("\nCity is already on the list\n\n");
            else if (add_result == 1)
                printf("\nCity successfully added to the list \n\n");
            else
                printf("\nUnable to add. City list is full \n\n");

            break;
        
        case '2': //Add city record at the head.
            // input city record from user
            printf("\nEnter city name: ");
            fgets(name_input, sizeof(name_input), stdin);
            name_input[strlen(name_input) - 1] = '\0';

            printf("Please enter city population: ");
            scanf("%d", &pop_input);
            flushStdIn();

            printf("Please enter maiden household income: ");
            scanf("%d", &income_input);
            flushStdIn();

            // add the city to the list
            add_result = addHead(name_input, pop_input, income_input);
            if (add_result == 0)
                printf("\nCity is already on the list\n\n");
            else if (add_result == 1)
                printf("\nCity successfully added to the list \n\n");
            else
                printf("\nUnable to add. City list is full \n\n");

            break;

        case '3': //Display the city with largest population.
            maxPop();
            break;
        
        case '4': //Display all the city records. 
            display();		
            break;

        case '5': //Exit
            break;
    }
}

//Code to add to tail of linked list
int addTail(char* name_input,unsigned int pop_input, unsigned int income_input)
{
    struct cityInfo* head = list; 
    // Check to see if list is full
    if (count == MAX_CITIES) {
        return 2; // List is full, return 2 
    }
    else {
        // go through each city in list
		while(head) {
			// Check if name already on list
			if ( strcmp(head->name, name_input) == 0) {
				return 0; // name already on list
			}
			if (head->next != NULL) {
				head = head->next;
			}
			else {
				break;
			}
		}

        // If name not on list and the list isn't full, add to end of list
		struct cityInfo* newCity1 = (struct cityInfo*)malloc(sizeof(struct cityInfo));
		
		strcpy(newCity1->name, name_input);
		newCity1->pop = pop_input;
		newCity1->income = income_input;
		
		newCity1->next = NULL;

		if (head) {
			head->next = newCity1;
		}
		else {
			head = newCity1;
			list = head;
		}
		count++;
		return 1; // name not on list, added to list
    }
}

//Code to add to head of linked list
//Same as linked list insertion
int addHead(char* name_input,unsigned int pop_input, unsigned int income_input)
{
    struct cityInfo** head_ref;
    struct cityInfo* head = list; 
    // Check to see if list is full
    if (count == MAX_CITIES) {
        return 2; // List is full, return 2 
    }
    else {
        // go through each city in list
		while(head) {
			// Check if name already on list
			if ( strcmp(head->name, name_input) == 0) {
				return 0; // name already on list
			}
			if (head->next != NULL) {
				head = head->next;
			}
			else {
				break;
			}
		}

        // If name not on list and the list isn't full, add to end of list
        struct cityInfo* newCity1 = (struct cityInfo*)malloc(sizeof(struct cityInfo));
		
		strcpy(newCity1->name, name_input);
		newCity1->pop = pop_input;
		newCity1->income = income_input;

        newCity1->next = (*head_ref);

        (*head_ref) = newCity1;
    }
}

// Code to display all cities in linked list
void display()
{
	struct cityInfo* head = list;

	if (head != NULL) { //check if list is empty
		while (head) {
            printf("\nCity name: %s", head->name);
            printf("\nCity population: %d", head->pop);
            printf("\nMaiden household income: %d", head->income);
            printf("\n");
			if (head->next != NULL) {
				head = head->next;
			}
			else {
				break;
			}
		}
	}
	else {
		printf("No cities\n");
	}
}

//This code finds the city in the linked list with the maximum population
//Similar to most find max value code, with a few more conditions for linked list

void maxPop()
{   
    struct cityInfo* head = list;
    struct cityInfo* max;
    max = head;
    
	if (head != NULL) {
		while (head) {
			if (max < head) {
				if(head->next == NULL)
                    max=head;
                else
                    max = head->next;
			}
            head = head->next;
		}
        //display max
        printf("\nCity name: %s", max->name);
        printf("\nCity population: %d", max->pop);
        printf("\nMaiden household income: %d", max->income);
        printf("\n");
    }
	else {
		printf("No cities\n");
	}
}
