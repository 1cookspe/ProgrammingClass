// Name: Spencer Gable-Cook
// Date: Tuesday November 15, 2016
// Lab 006
// Program Mission: To generate a random number and create an array of elements that are divisible by 3
#include <iostream>
using namespace std;
#include <ctime>

void myHeader(string name, int lab, string date, int question);
void myFooter(void);

int main()
{
    // Print welcome header
    myHeader("Spencer Gable-Cook", 6, "Tuesday November 15, 2016", 2);
    
	// Holds user's decision to continue the game
	char yes = 'y';

	do {
        // Variables
        int randomNumber = 0;
        const int N = 10;
        int myArray[N];
        int sum = 0;
        double average = 0;
        
		// Generate random number
		srand((unsigned int)time(NULL));
		randomNumber = rand() % 6 + 1;
		cout << "RANDOM NUMBER = " << randomNumber << endl;

		// Populate array with multiples of 3
		for (int i = 0; i < N; i++) {
			if (randomNumber % 3 == 0) { // if original random number is divisible by 3, every multiple is printed out
				myArray[i] = randomNumber * (i + 1);
			}
			else { // is multipled by 3 each time to get multiples divisible by 3
				myArray[i] = randomNumber * 3 * (i + 1);
			}
		}

		// Print out values of the array and calculate final values
		cout << "\nORIGINAL ARRAY \n";
		for (int i = 0; i < N; i++) {
			cout << "ARRAY[" << i << "] = " << myArray[i] << endl;
			sum += myArray[i];
		}

		// print out sum and average
		average = (double)sum / N;
		cout << "Sum of array: " << sum << endl;
		cout << "Average of array: " << average << endl;

		// Multiply each value of array by 2, and print it out
		cout << "\nARRAY MULTIPLED BY 2: " << endl;
		for (int i = 0; i < N; i++) {
			cout << "ARRAY[" << i << "] = " << myArray[i] * 2 << endl;
		}

		// Print out reversed values of array
		cout << "\nARRAY IN REVERSE: " << endl;
		for (int i = (N - 1); i >= 0; i--) {
			cout << "ARRAY[" << i << "] = " << myArray[i] << endl;
		}

		// ask if user would like to repeat
		cout << "\nWould you like to play again? Enter y/Y for yes, or any other key to stop: ";
		cin >> yes;
		yes = tolower(yes);
	} while (yes == 'y'); // loop again if the user entered y or Y

    // Give user exit message
    myFooter();
}

void myHeader(string name, int lab, string date, int question) {
    cout << "Welcome to the divisible by 3 array generator!" << endl;
    cout << "********************************************" << endl;
    cout << "Name: " << name << endl;
    cout << "Lab Number: 00" << lab << endl;
    cout << "Date: " << date << endl;
    cout << "Question #" << question << endl;
    cout << "********************************************" << endl;
}

void myFooter() {
    cout << "Thank you for playing!" << endl;
}
