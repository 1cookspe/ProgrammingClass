// Name: Spencer Gable-Cook
// Lab 005
// Question 2
// Program Mission: Create random die game

#include <iostream>
#include <ctime>
using namespace std;

// Initially declare functions to be used
char myCommand(void);
int rollDie();
int calcWin(int number);
int oneTimes = 0;
int twoTimes = 0;
int threeTimes = 0;
int fourTimes = 0;
int fiveTimes = 0;
int sixTimes = 0;
int moneyWon = 0;


int main()
{
    // Declare and initialize variables
    char answer = 'y';
    int numberOfRolls = 0;
    
    cout << "Welcome to the dice game! " << endl;
    
    // Change srand valid to the current time to ensure a new sequence of random numbers are generated
    srand((unsigned int) time(NULL));
    
    // Loop until user hits E or e
    do {
        // Get user's selection and verify it is valid from myCommand()
        answer = myCommand();
        
        // Use switch statement to determine what user selected
        switch (answer) {
            case 'Y': {  // User wants to play again
                // Increment and output # of rolls
                numberOfRolls++;
                cout << "****************************************" << endl;
                cout << "Roll " << numberOfRolls << endl;
                
                // Get random die number from rollDie()
                int die = rollDie();
                
                // Output results to user
                cout << "Die " << die << endl;
                // Calculate user's winning from calcWin(die) function
                cout << "You win $" << calcWin(die) << endl;
                break;
            }
            case 'E': // User wants to exit
                // Output final results
                cout << "****************************************" << endl;
                cout << "Stats: " << endl;
                cout << "Number of ones rolled: " << oneTimes << endl;
                cout << "Number of twos rolled: " << twoTimes << endl;
                cout << "Number of threes rolled: " << threeTimes << endl;
                cout << "Number of fours rolled: " << fourTimes << endl;
                cout << "Number of fives rolled: " << fiveTimes << endl;
                cout << "Number of sixes rolled: " << sixTimes << endl;
                cout << "Total number of rolls: " << numberOfRolls << endl;
                cout << "Money won: $" << moneyWon << endl;
                return 0;
                break;
        }
        // Loop again if user enters y or Y
    } while (answer == 'Y');
}


char myCommand(void) {
    // Get input from user
    char answer = 'y';
    cout << "Enter your command: ";
    cin >> answer;
    // Set char to upper case, just in case user enters lower case letter (used for comparisons)
    answer = toupper(answer);
    
    
    // checks if answer is not Y or E, if so, an invalid error is printed and user is asked to enter a new value until it is valid
    while (answer != 'Y' && answer != 'E') {
        cout << "Invalid command! Enter your command: ";
        cin >> answer;
        answer = toupper(answer);
    }
    
    // Return final, valid answer to the caller
    return answer;
}


int rollDie() {
    int randomNumber = 0;
    // Get random number using rand() function, mod by 6 and add 1 to ensure it is in the range of 1 to 6
    randomNumber = rand() % 6 + 1;
    // Return random number to caller
    return randomNumber;
}


int calcWin(int number) { // Calculate user's winnings based on number rolled
    switch (number) { // Use switch statement to match user's die rolled with their winnings
        case 1:
            // Increment number of 1's rolled
            oneTimes++;
            // User wins $1000, add to moneyWon, return 1000 to caller
            moneyWon += 1000;
            return 1000;
        case 2:
            // Increment number of 2's rolled
            twoTimes++;
            // User wins $500, add to moneyWon, return 500 to caller
            moneyWon += 500;
            return 500;
        case 3:
            threeTimes++;
            moneyWon += 250;
            return 250;
        case 4:
            fourTimes++;
            moneyWon += 200;
            return 200;
        case 5:
            fiveTimes++;
            moneyWon += 100;
            return 100;
        case 6:
            sixTimes++;
            return 0;
    }
    return 0;
}

