// Name: Spencer Gable-Cook
// Date: Tuesday November 15, 2016
// Lab 006
// Program Mission: Generate random numbers in array and manipulate values
#include <iostream>
using namespace std;
#include <ctime>

// Define methods
int myRandom();
void printArray(int myArray[], int N);
double myAverage(int myArray[], int N);
int myMax(int myArray[], int N);
int myMin(int myArray[], int N);
void reverseArray(int myArray[], int N);
void myHeader(string name, int lab, string date, int question);
void myFooter();

int main()
{
    // Display header
    myHeader("Spencer Gable-Cook", 6, "Tuesday November 15, 2016", 3);
    
    // Constant int to store size of array
	const int N = 10;
    char y = 'y';
	
    do {
        // Declare the random number
        int number = 0;
        // Declare array, and set size to N (10)
        int myArray[N];

        // ask for and get number from user
        cout << "\nEnter integer value: ";
        cin >> number;

        srand((unsigned int)time(NULL));
        
        cout << "Populating array...\n---------------------\n";
        cout << "Your generated array is... " << endl;

        // Loop through array and populate with values
        for (int i = 0; i < N; i++) {
            myArray[i] = number * myRandom();
        }

        // Call and print functions
        printArray(myArray, N);
        cout << "Average: " << myAverage(myArray, N) << endl;
        cout << "Maximum value: " << myMax(myArray, N) << endl;
        cout << "Minimum value: " << myMin(myArray, N) << endl;
        cout << "\nReversed array: " << endl;
        reverseArray(myArray, N);
        
        // Ask user if they would like to repeat
        cout << "\nDo you want to continue (press y for yes, any other key to end program): ";
        cin >> y;
        y = tolower(y);
    } while (y == 'y'); // loop again if user enters y or Y for yes
    
    myFooter();
}

// Generate random number between 0 and 7
int myRandom() {
	int randomNumber = rand() % 8;
	return randomNumber;
}

// Print all elements of the array using a for loop to iterate through each element
void printArray(int myArray[], int N) {
	for (int i = 0; i < N; i++) {
		cout << myArray[i] << endl;
	}
}

// Calculates average of elements in array
double myAverage(int myArray[], int N) {
	int total = 0;
	double average = 0;
    // Loop through array and get total of all numbers
	for (int i = 0; i < N; i++) {
		total += myArray[i];
	}
    // calculate average by dividing the total by the number of elements in array
	average = (double)total / N;
	return average;
}

// Gets maximum value of values in array
int myMax(int myArray[], int N) {
	int maximum = 0;
    // Loop through each element of array
	for (int i = 0; i < N; i++) {
        // Check if element is greater than maximum, if so, switch the value of maximum to the element value
		if (i == 1 || myArray[i] > maximum) {
			maximum = myArray[i];
		}
	}
	return maximum;
}

int myMin(int myArray[], int N) {
	int minimum = 0;
	for (int i = 0; i < N; i++) {
        // Check if element is less than minimum, if so, switch the value of minimum to the element value
		if (i == 1 || myArray[i] < minimum) {
			minimum = myArray[i];
		}
	}
	return minimum;
}

// Reverses values of array
void reverseArray(int myArray[], int N) {
	int oppositeArray[10];
    // Loop through array backwards and store values in the new oppositeArray
	for (int i = 0; i < N; i++) {
		oppositeArray[i] = myArray[N - i - 1];
	}

	printArray(oppositeArray, N);
}

void myHeader(string name, int lab, string date, int question) {
    cout << "Welcome to the randon number array generator!" << endl;
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
