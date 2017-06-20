// Name: Spencer Gable-Cook
// Lab 005
// Question 3
// Program Mission: Play a Dice counting game with user

#include <stdio.h>
#include <ctime>
#include <iostream>
using namespace std;

int rollDie();
int menuChoice();

int main()
{
    
    // Set srand to time to generate new sequence of numbers
    srand((unsigned int) time(NULL));

    // Declare and initialize values
    int rollOne = 0;
    int rollTwo = 0;
    int times = 0;
    int numberOne = 0;
    int numberTwo = 0;
    int choice = 0;
    char exit = 'y';
    
    cout << "Grade 2 Maths: Generating Numbers and counting by 1's or 10's: " << endl;
    cout << "===========================================================" << endl;
    
    // Keep looping until user enters e or E to exit
    do {
    
        // Call rollDie three times to generate three random rolls
        rollOne = rollDie();
        rollTwo = rollDie();
        times = rollDie();
    
        // Set the first number as the combination of the first roll and second roll
        numberOne = rollOne * 10 + rollTwo;
        // Set the second number as the combination of the second roll and first roll
        numberTwo = rollTwo * 10 + rollOne;
    
        // Output options to user
        cout << "Enter your choice from the following menu: " << endl;
        cout << "1: Beginning from " << numberOne << " count " << times << " number(s) by Ones" << endl;
        cout << "2: Beginning from " << numberTwo << " count " << times << " number(s) by Ones" << endl;
        cout << "3: Beginning from " << numberOne << " count " << times << " number(s) by Tens" << endl;
        cout << "4: Beginning from " << numberTwo << " count " << times << " number(s) by Tens" << endl;
    
        // Get choice from user after verifying it in the menuChoice
        choice = menuChoice();
    
        // Create switch statement to compute user's selection
        switch (choice) {
            case 1: // Count by ones from the first number
                // Loop as many times as in the variable times, and increment by one each time
                for (int i = 1; i <= times; i++) {
                    cout << (numberOne + i) << endl;
                }
                break;
            case 2: // Count by ones from the second number
                // Loop as many times as in the variable times, and increment by one each time
                for (int i = 1; i <= times; i++) {
                    cout << (numberTwo + i) << endl;
                }
                break;
            case 3: // Count by tens from the first number
                // Loop as many times as the times variable * 10, and add 10 each time
                for (int i = 10; i <= (10 * times); i += 10) {
                    cout << (numberOne + i) << endl;
                }
                break;
            case 4: // Count by tens from the second number
                // Loop as many times as the times variable * 10, and add 10 each time
                for (int i = 10; i <= (10 * times); i += 10) {
                    cout << (numberTwo + i) << endl;
                }
                break;
            default:
                break;
        }
        
        // Ask user if they would like to repeat game
        cout << "Would you like to continue? (y/n): ";
        cin >> exit;
        exit = tolower(exit);
    } while (exit == 'y');
    
    cout << "Thank you for playing!" << endl;
}

int rollDie() {
    // Generate random number between 1 and 6, and return it to the caller
    int randomNumber = 0;
    randomNumber = rand() % 6 + 1;
    return randomNumber;
}

int menuChoice() {
    
    // Create and ask for user's choice
    int choice = 0;
    
    cout << "Enter your choice: ";
    
    cin >> choice;
    
    // Loop to verify that the choice is between 1 and 4; if not, ask user for value again
    while (choice < 1 || choice > 4) {
        cout << "Invalid! Please input a number from 1 to 4!: ";
        cin >> choice;
    }
    
    // Return valid choice to caller
    return choice;
}
