// Name: Spencer Gable-Cook
// Date: Tuesday, November 15, 2016
// Lab 005
// Question #1
// Program Mission: To allow users to fill up their water bottles, along with changing the filter

// Add libraries
#include <iostream>
#include <string>
using namespace std;

// Declare functions
void validChar();
void filterStatus();
bool validChar(char choice);
void myHeader(string name, int lab, string date, int question);
void myFooter(void);

int main()
{
    // Call header method to display the header
    myHeader("Spencer Gable-Cook", 6, "Tuesday, November 15, 2016", 1);
    
    // Call validChar() to start the loop and ask the user if they want to fill up their water bottle
    validChar();
}


void validChar() {
	// char y is used to get the user's input on whether or not they want to fill up their water bottle
    char y = 'y';
    
    // Execute do while loop until fillUp is false, that is the user has stopped filling up bottles
    do {
        // Ask user if they want to fill up and get answer
        cout << "Enter Y/y to fill up: ";
        cin >> y;
        // convert input to lower case for comparison purposes
        y = tolower(y);

        // Check to see if user entered y or n, if they didn't then loop until they have entered a valid input
        while (y != 'y') {
            cout << "ERROR: Check the bottle is close enough to the fountain!" << endl;
            cout << "Enter Y/y to put the bottle close to the fountain: ";
            cin >> y;
        }
        
        // If user entered yes, they continue filling up bottles, and move to the filterStatus()
        if (y == 'y') {
            filterStatus();
        } else { // user has entered no, they stop filling up bottles
            
        }
        
        cout << "\nDo you want to fill another bottle? (y/Y or n/N): ";
        cin >> y;
    
    } while (validChar(y));
    
    // User has entered 'n', they have stopped filling up water bottles, show them the exit message
    myFooter();
}


void filterStatus() {
    // static int to hold number of times fountain has been used, static to ensure the data is not lost everytime the method is called again
	static int timesUsed;
	char y = 'y';
	
    // If fountain has been used less than 15 times, it can still be used without changing the filter
    if (timesUsed < 15) {
        
        // increment number of times used
        timesUsed++;
        cout << "The fountain has filled up " << timesUsed << " bottles" << endl;

        // If fountain has been used 10 or more times, user is warned that the filter should be replaced at 15 uses
        if (timesUsed >= 10) {
            // Ask user if they want to change filter
            cout << "WARNING! You should change the filter within the next " << (15 - timesUsed) << " uses! \nWould you like to change the filter?: ";
            cin >> y;
        
            // Use validChar(y) to verify the user's input is valid, and get whether they said yes or no
            if (validChar(y)) { // user entered yes, reset filter with 0 times used
                cout << "Filter changed! You now have a new, clean filter!" << endl;
                timesUsed = 0;
            }
        
        }
        
    } else if (timesUsed == 15) { // filter has been used 15 times, too many times, demand that the user changes the filter
        cout << "The filter has been used too many times --- the filter is dirty. Do you want to change the filter? (y/n):" << endl;
        cin >> y;
        
        // loop until user enters yes
        while (!validChar(y)) {
            cout << "ERROR! You can't proceed without a new filter!" << endl;
            cout << "Do you want to change the filter? (y/n): ";
            cin >> y;
        }
        
        // user has finally entered yes, reset filter
        cout << "Filter changed! You can now use the fountain again!" << endl;
        timesUsed = 0;
    }

}

// checks input is valid, and returns true for yes and false for no
bool validChar(char choice) {
    // change char to lower case for comparison purposes
    choice = tolower(choice);
    // loop until user has entered either yes or no (valid choices)
    while (choice != 'y' && choice != 'n') {
        cout << "ERROR: Check the bottle is close enough to the fountain! \n Type y/Y for yes, n/N for no: ";
        cin >> choice;
        choice = tolower(choice);
    }
    
    // if choice is y (yes), return true
    if (choice == 'y') {
        return true;
    } // choice is n (no), return false
    return false;
}

// print out header using parameters given
void myHeader(string name, int lab, string date, int question) {
    cout << "Welcome to the water bottle simulator!" << endl;
    cout << "********************************************" << endl;
    cout << "Name: " << name << endl;
    cout << "Lab Number: 00" << lab << endl;
    cout << "Date: " << date << endl;
    cout << "Question #" << question << endl;
    cout << "********************************************" << endl;
}

// print out exit footer to user once they end the program
void myFooter() {
    cout << "*************************************" << endl;
    cout << "You've successfully filled up all your water bottles!" << endl;
    cout << "*************************************" << endl;
}


