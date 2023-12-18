//Wilson Kelly
//CSE310
//Recitation 3
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_NAME_LENGTH 10  
#define MAX_REQUESTS 30

// Function declaration
void flushStdIn();
void executeAction(char);

// Driver Code
int main()
{
	cout << "Welcome to the Plane Landing System\n" << endl;
    // This section asks for the user input, and goes to the corresponding function
    char choice = '0'; //placeholder character

    do
    { 
        cout << "\t 1: Make a landing request\n" << endl;
        cout << "\t 2: Land a Plane\n" << endl;
        cout << "\t 3: List all the landing requests\n" << endl;
        cout << "\t 4: Exit\n" << endl;
        choice = getchar();
        flushStdIn();
        //goes to function
        executeAction(choice);
    } while (choice != '4'); //4 = exit
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
    char flight_number[MAX_NAME_LENGTH];
    unsigned int key_value; //key=minutes
    priority_queue<int> p;
    std::vector<std::string> array; 
    switch (c)
    {
        case '1': //Make a landing request
            // input plane info
            cout << "\nEnter flight number" << endl;
            fgets(flight_number, sizeof(flight_number), stdin);
            flight_number[strlen(flight_number) - 1] = '\0';

            cout << "Enter how many minutes to wait before landing: " << endl;
            scanf("%d", key_value);
            flushStdIn();
            //add request to priority queue
            p.push(key_value);
            array.push_back(flight_number); 

            break;

        case '2': //Land a Plane
            //call land method
                //request with smallest key will be removed
            //for()
            break;

        case '3': //List all the landing requests
            
            cout << "\n Flight numbers" << endl;
            for (int i = 0; i < array.size(); i++) {
		        cout << array[i] << ' ';
	        }
	        cout << endl;
            
            while (!p.empty()) {
                cout << ' ' << p.top();
                p.pop();
            }
            cout << '\n';
            break;
            
            //stopped here, IDE stopped working and I ran out of time
            //Debug/ to do: get print working, implement sort for minheap

        case '4': //Exit
            break;
    }
}